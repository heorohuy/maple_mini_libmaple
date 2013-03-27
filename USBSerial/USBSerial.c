
#include "USBSerial.h"
#include <libmaple/systick.h>
#include <libmaple/nvic.h>
#include <libmaple/delay.h>
#include <libmaple/usb_cdcacm.h>
#include <libmaple/usb.h>

#define USB_TIMEOUT 50

uint32 millis(void) {
    return systick_uptime();
}

void USBSerialBegin(void){
        usb_cdcacm_enable(GPIOB, 9);
}

//This makes sure the function only runs if the USB is properly setup
uint8 USBisConnectedMain(void) {
    return usb_is_connected(USBLIB) && usb_is_configured(USBLIB);
}

//Ripped this off from the HardwareSerial class.
void USBSerialwriteMain(const void *buf, uint32 len) {
    if (!USBisConnectedMain() || !buf) {
        return;
    }

    uint32 txed = 0;
    uint32 old_txed = 0;
    uint32 start = millis();

    uint32 sent = 0;

    while (txed < len && (millis() - start < USB_TIMEOUT)) {
        sent = usb_cdcacm_tx((const uint8*)buf + txed, len - txed);
        txed += sent;
        if (old_txed != txed) {
            start = millis();
        }
        old_txed = txed;
    }


    if (sent == USB_CDCACM_TX_EPSIZE) {
        while (usb_cdcacm_is_transmitting() != 0) {
        }
        /* flush out to avoid having the pc wait for more data */
        usb_cdcacm_tx(NULL, 0);
    }
}
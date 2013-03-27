


#include "SerialUSB.h"
#include <string.h>
#include <stdint.h>
#include <libmaple/libmaple.h>
#include <libmaple/systick.h>
#include <libmaple/nvic.h>
#include <libmaple/usb_cdcacm.h>
#include <libmaple/usb.h>


#define USB_TIMEOUT 50

SerialUSB::SerialUSB(void){

}

void SerialUSB::start(void){
    usb_cdcacm_enable(GPIOB, 9);
}

void SerialUSB::end(void){
    usb_cdcacm_disable(GPIOB, 9);
}

void SerialUSB::write(uint8 someChar){
    this->write(&someChar, 1);
}

void SerialUSB::write(const char *str){
    this->write(str, strlen(str));
}

void SerialUSB::write(const void *buf, uint32 len){
    //Silently fails if it's not connected or there's no buffer
    if(!this->isConnected() || !buf){
        return;
    }

    uint32 txed = 0;
    uint32 old_txed = 0;
    uint32 start = systick_uptime();

    uint32 sent = 0;

    while (txed < len && (systick_uptime() - start < USB_TIMEOUT)) {
        sent = usb_cdcacm_tx((const uint8*)buf + txed, len - txed);
        txed += sent;
        if (old_txed != txed) {
            start = systick_uptime();
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

uint32 SerialUSB::available(void){
    return usb_cdcacm_data_available();
}

uint32 SerialUSB::read(void *buf, uint32 len) {
    if (!buf) {
        return 0;
    }

    uint32 rxed = 0;
    while (rxed < len) {
        rxed += usb_cdcacm_rx((uint8*)buf + rxed, len - rxed);
    }

    return rxed;
}

uint8 SerialUSB::read(void) {
    uint8 b;
    this->read(&b, 1);
    return b;
}

uint8 SerialUSB::pending(void) {
    return usb_cdcacm_get_pending();
}

uint8 SerialUSB::isConnected(void) {
    return usb_is_connected(USBLIB) && usb_is_configured(USBLIB);
}


SerialUSB usbSerial;


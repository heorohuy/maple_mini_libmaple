#ifndef _USBSERIAL_H_
#define _USBSERIAL_H_

/* Conditional extern "C" so we're safe to call from C++ files */
#ifdef __cplusplus
extern "C" {
#endif

#include <libmaple/systick.h>
#include <libmaple/nvic.h>
#include <libmaple/delay.h>
#include <libmaple/usb_cdcacm.h>
#include <libmaple/usb.h>


void init(void);
uint32 millis(void);
void USBSerialBegin(void);
void USBSerialwriteMain(const void *buf, uint32 len);


#ifdef __cplusplus
}
#endif

#endif  /* _USBSERIAL_H_ */

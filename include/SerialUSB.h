
#ifndef _SerialUSB_H_
#define _SerialUSB_H_

#include <libmaple/libmaple.h>
#include "Print.h"

class SerialUSB: public Print {
 public:
    SerialUSB(void);
    void start(void);
    void end(void);
    uint32 available(void);

    uint32 read(void *buf, uint32 len);
    uint8  read(void);;

    void write(uint8);
    void write(const char *str);
    void write(const void*, uint32);

    uint8 isConnected();
    uint8 pending();

};

extern SerialUSB usbSerial;

#endif

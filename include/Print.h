#ifndef _PRINT_H_
#define _PRINT_H_

#include <libmaple/libmaple_types.h>

enum {
    BYTE = 0,
    BIN  = 2,
    OCT  = 8,
    DEC  = 10,
    HEX  = 16
};

class Print {
public:
    virtual void write(uint8 ch) = 0;
    virtual void write(const char *str);
    virtual void write(const void *buf, uint32 len);
    void print(char);
    void print(const char[]);
    void print(uint8, int=DEC);
    void print(int, int=DEC);
    void print(unsigned int, int=DEC);
    void print(long, int=DEC);
    void print(unsigned long, int=DEC);
    void print(long long, int=DEC);
    void print(unsigned long long, int=DEC);
    void print(double, int=2);
    void println(void);
    void println(char);
    void println(const char[]);
    void println(uint8, int=DEC);
    void println(int, int=DEC);
    void println(unsigned int, int=DEC);
    void println(long, int=DEC);
    void println(unsigned long, int=DEC);
    void println(long long, int=DEC);
    void println(unsigned long long, int=DEC);
    void println(double, int=2);
private:
    void printNumber(unsigned long long, uint8);
    void printFloat(double, uint8);
};

#endif
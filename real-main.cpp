// Here's a wirish include:

#include "SerialUSB.h"
#include <libmaple/libmaple.h>
#include <libmaple/gpio.h>
#include <libmaple/timer.h>
#include <libmaple/usart.h>
#include "board.h"



char ch = 'a';
char ch2 = 'b';

// setup() and loop():


void setup(void) {

    //Testing using the onboard LED
    //pinMode(BOARD_LED_PIN, OUTPUT);

    //SerialUSB works, but we can also just call the usb_cdcacm function directly
    //SerialUSB.begin();
    //USBSerialBegin();
    //GPIO magic
    //gpio_set_mode(GPIOB, 12, GPIO_OUTPUT_PP);
    //gpio_write_bit(GPIOB, 12, 1);
    //Magic number
    //delay(255);

    usbSerial.start();

}




void loop(void) {
    
    //Testing using the onboard LCD
    //toggleLED();
    
    //SerialUSB.write(&ch, 1);
    //SerialUSB.write(ch);

    usbSerial.println("Banana!");
    //The serial write function
    //USBSerialwriteMain(&ch, 1);

    //usb_cdcacm_tx((uint8*)&ch2, 1); 
    //usb_cdcacm_tx((uint8*)&ch, 1); 


    //delay(5000);

    //usb_cdcacm_putc('a');


}

// Standard libmaple init() and main.
//
// The init() part makes sure your board gets set up correctly. It's
// best to leave that alone unless you know what you're doing. main()
// is the usual "call setup(), then loop() forever", but of course can
// be whatever you want.

__attribute__((constructor)) void premain() {
    init();
}

int main(void) {
    setup();

    while (true) {
        loop();
    }

    return 0;
}

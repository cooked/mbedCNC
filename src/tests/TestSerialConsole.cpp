#include "mbed.h"
#include "SerialConsole.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Thread thread;

void led2_thread() {
    while (true) {
        led2 = !led2;
        wait(1);
    }
}

int main() {

	SerialConsole sc = SerialConsole( USBRX, USBTX, MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE);

    thread.start(led2_thread);

    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}

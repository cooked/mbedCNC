#include <map>
#include "mbed.h"
#include "mbed_events.h"
#include "ModuleManager.h"
#include "EventManager.h"
// modules
#include "SerialConsole.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

Thread thread1;
Thread thread2;

void led1_thread() {
	while (true) {
        led1 = !led1;
        wait(0.5);
    }
}

void led2_thread() {
    while (true) {
        led2 = !led2;
        wait(1);
    }
}

int main() {

	ModuleManager 	mm = new ModuleManager();
	EventManager 	em = new EventManager();

	mm.add("serial", new SerialConsole(USBTX, USBRX, MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE));

    thread1.start(led2_thread);
    thread2.start(led2_thread);
    eventDispatcher.start(callback(&eventQueue, &EventQueue::dispatch_forever));

    // start stuff
    mm.start();
    em.start();

    wait(osWaitForever);
}

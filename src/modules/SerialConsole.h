// from Smoothie but:
// - uses Stream (mbed) instead of custom StreamOutput

#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include "mbed.h"
#include "libs/Module.h"
#include "libs/RingBuffer.h"

class SerialConsole : public Module, public Stream {
    public:
        SerialConsole( PinName rx_pin, PinName tx_pin, int baud_rate );

        void on_module_loaded();
        void on_serial_char_received();
        void on_main_loop(void * argument);
        void on_idle(void * argument);
        bool has_char(char letter);

        int _putc(int c);
        int _getc(void);
        int puts(const char*);

        RingBuffer<char,256> buffer;             // Receive buffer
        Serial* serial;
        struct {
          bool query_flag:1;
          bool halt_flag:1;
        };
};

#endif

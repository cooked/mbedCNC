// from Smoothie

#ifndef MODULE_H
#define MODULE_H

// See : http://smoothieware.org/listofevents
// When adding a new event the virtual method needs to be defined in class Module and the method pointer need to be defined in
// Module.cpp:16 in the same order
enum _EVENT_ENUM {
    ON_MAIN_LOOP,
    ON_CONSOLE_LINE_RECEIVED,
    ON_GCODE_RECEIVED,
    ON_IDLE,
    ON_SECOND_TICK,
    ON_GET_PUBLIC_DATA,
    ON_SET_PUBLIC_DATA,
    ON_HALT,
    ON_ENABLE,
    NUMBER_OF_DEFINED_EVENTS
};

class Module;
typedef void (Module::*ModuleCallback)(void *argument);
extern const ModuleCallback kernel_callback_functions[NUMBER_OF_DEFINED_EVENTS];

// Module base class
// All modules must extend this class, see http://smoothieware.org/moduleexample
class Module
{
public:
    Module();
    virtual ~Module();
    virtual void on_module_loaded() {};

    void register_for_event(_EVENT_ENUM event_id);

    // event callbacks, not every module will implement all of these
    // there should be one for each _EVENT_ENUM
    virtual void on_main_loop(void *) {};
    virtual void on_console_line_received(void *) {};
    virtual void on_gcode_received(void *) {};
    virtual void on_idle(void *) {};
    virtual void on_second_tick(void *) {};
    virtual void on_get_public_data(void *) {};
    virtual void on_set_public_data(void *) {};
    virtual void on_halt(void *) {};
    virtual void on_enable(void *) {};

};

#endif

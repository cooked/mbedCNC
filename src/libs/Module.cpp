// from Smoothie

#include "libs/Module.h"
//#include "libs/Kernel.h"

Module::Module(){}
Module::~Module(){}

// this is used to callback the specific method in the Module instance, there must be one for each _EVENT_ENUM and in the same order
// NOTE this is stored in Flash so takes up no RAM
const ModuleCallback kernel_callback_functions[NUMBER_OF_DEFINED_EVENTS] = {
    &Module::on_main_loop,
    &Module::on_console_line_received,
    &Module::on_gcode_received,
    &Module::on_idle,
    &Module::on_second_tick,
    &Module::on_get_public_data,
    &Module::on_set_public_data,
    &Module::on_halt,
    &Module::on_enable

};


void Module::register_for_event(_EVENT_ENUM event_id){
    // Events are the basic building blocks of Smoothie. They register for events, and then do stuff when those events are called.
    // You add things to Smoothie by making a new class that inherits the Module class. See http://smoothieware.org/moduleexample for a crude introduction
    //THEKERNEL->register_for_event(event_id, this);
}

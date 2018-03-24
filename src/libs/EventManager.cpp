/*
 * EventManager.cpp
 *
 *  Created on: 24 Mar 2018
 *      Author: stefanocottafavi
 */

#include "EventManager.h"

void EventManager::start() {
	this->queue.dispatch_forever();
}

// Call a specific event with an argument
void EventManager::onEvent(_EVENT_ENUM id_event, void * argument) {
//    bool was_idle = true;
//    if(id_event == ON_HALT) {
//        this->halted = (argument == nullptr);
//        was_idle = conveyor->is_idle(); // see if we were doing anything like printing
//    }

    // send to all registered modules
    for (auto m : hooks[id_event]) {
        (m->*kernel_callback_functions[id_event])(argument);
    }

//    if(id_event == ON_HALT) {
//        if(!this->halted || !was_idle) {
//            // if we were running and this is a HALT
//            // or if we are clearing the halt with $X or M999
//            // fix up the current positions in case they got out of sync due to backed up commands
//            this->robot->reset_position_from_current_actuator_position();
//        }
//    }
}

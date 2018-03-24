/*
 * EventManager.h
 *
 *  Created on: 23 Mar 2018
 *      Author: stefanocottafavi
 */

#ifndef SRC_LIBS_EVENTMANAGER_H_
#define SRC_LIBS_EVENTMANAGER_H_

#include "mbed_events.h"

class EventManager {
    public:
        EventManager();
        static EventManager* 	instance;
        static EventQueue 		queue;
        void start();
        void onEvent();
};



#endif /* SRC_LIBS_EVENTMANAGER_H_ */

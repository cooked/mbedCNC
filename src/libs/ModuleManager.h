/*
 * ModuleManager.h
 *
 *  Created on: 23 Mar 2018
 *      Author: stefanocottafavi
 */

#ifndef SRC_LIBS_MODULEMANAGER_H_
#define SRC_LIBS_MODULEMANAGER_H_

#include <map>
#include <string>
#include "Module.h"

class ModuleManager {
    public:
        ModuleManager();
        static ModuleManager* instance;

        void 	add(std::string name, Module* module);
        void 	start();
        void 	startModule();
        void 	stopModule();
        Module* get(std::string name);
    private:
        std::map<std::string, Module> modules;

};



#endif /* SRC_LIBS_MODULEMANAGER_H_ */

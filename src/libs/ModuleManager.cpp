/*
 * ModuleManager.cpp
 *
 *  Created on: 23 Mar 2018
 *      Author: stefanocottafavi
 */

#include "ModuleManager.h"

void ModuleManager::add(std::string name, Module* module) {
	this->modules[ name ] = module;
}

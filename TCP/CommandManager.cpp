/*
 * CommandManager.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */

#include "CommandManager.h"

CommandManager::CommandManager() {
//    commandsMap["print"] = new PrintCommand;

}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}

void CommandManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}


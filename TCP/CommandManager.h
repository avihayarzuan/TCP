/*
 * CommandManager.h
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */

#include <map>
#include "Command.h"
#include "PrintCommand.h"

using namespace std;

#ifndef TCP_COMMANDMANAGER_H_
#define TCP_COMMANDMANAGER_H_

/*
 *
 */
class CommandManager {
 public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command, vector<string> args);
 private:
    map<string, Command *> commandsMap;
};

#endif /* TCP_COMMANDMANAGER_H_ */

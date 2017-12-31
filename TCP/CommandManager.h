/*
 * CommandManager.h
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */



using namespace std;

#ifndef TCP_COMMANDMANAGER_H_
#define TCP_COMMANDMANAGER_H_
#include "StartCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"

class CommandManager {
 public:
    CommandManager();
    ~CommandManager();
    void executeCommand(string command, vector<string> args, StructArgs *sa);
 private:
    map<string, Command *> commandsMap;
};

#endif /* TCP_COMMANDMANAGER_H_ */

/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_COMMANDMANAGER_H_
#define TCP_COMMANDMANAGER_H_
#include "StartCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "GetListCommand.h"

class CommandManager {
 public:
    CommandManager();
    ~CommandManager();
    /**
     * the command manager get command as string and vector of
     * arguments and use the matching command.
     * @param command the command to run
     * @param args arguments to use in command
     * @param sa StructArgs of client sending the command
     */
    void executeCommand(string command, vector<string> args, StructArgs *sa);
 private:
    map<string, Command *> commandsMap;
};

#endif /* TCP_COMMANDMANAGER_H_ */

/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_STARTCOMMAND_H_
#define TCP_STARTCOMMAND_H_

#include "Command.h"

/*
 *
 */
class StartCommand : public Command {
 public:
    /**
     * given command 'start' and argument of the game name to start
     * @param args the game name
     * @param sa StructArgs of client.
     */
    void execute(vector<string> args, StructArgs *sa);
    /**
     * the method checks if the game name already exist in active
     * games, or in available games.
     * @param name the game name
     * @param sa StructArgs of client.
     * @return true if already false otherwise
     */
    bool isExist(string name, StructArgs *sa);
};

#endif /* TCP_STARTCOMMAND_H_ */

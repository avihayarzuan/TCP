/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_CLOSECOMMAND_H_
#define TCP_CLOSECOMMAND_H_

#include "Command.h"

class CloseCommand : public Command {
 public:
    /**
     * given command 'close' and argument of the game name to close
     * @param args the game name
     * @param sa StructArgs of client.
     */
    void execute(vector<string> args, StructArgs *sa);
};

#endif /* TCP_CLOSECOMMAND_H_ */

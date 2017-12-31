/*
 * JoinCommand.h
 *
 *  Created on: Dec 29, 2017
 *      Author: avihay
 */

#ifndef TCP_JOINCOMMAND_H_
#define TCP_JOINCOMMAND_H_

using namespace std;
#include "Command.h"


/*
 *
 */
class JoinCommand : public Command {
 public:
    void execute(vector<string> args, StructArgs *sa);
    int sendColor(int clientSocket, char color);
};

#endif /* TCP_JOINCOMMAND_H_ */

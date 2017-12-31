/*
 * StartCommand.h
 *
 *  Created on: Dec 27, 2017
 *      Author: avihay
 */


#ifndef TCP_STARTCOMMAND_H_
#define TCP_STARTCOMMAND_H_

//class Command;
//struct StructArgs;

using namespace std;
#include "Command.h"


/*
 *
 */
class StartCommand : public Command {
 public:
    void execute(vector<string> args, StructArgs *sa);
};

#endif /* TCP_STARTCOMMAND_H_ */

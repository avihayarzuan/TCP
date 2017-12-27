/*
 * StartCommand.h
 *
 *  Created on: Dec 27, 2017
 *      Author: avihay
 */
#include "Command.h"
#include <iostream>


using namespace std;

#ifndef TCP_STARTCOMMAND_H_
#define TCP_STARTCOMMAND_H_

/*
 *
 */
class StartCommand : public Command {
 public:
    void execute(vector<string> args);
};

#endif /* TCP_STARTCOMMAND_H_ */

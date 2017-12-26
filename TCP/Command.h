/*
 * Command.h
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */

#include <vector>
#include <string>

using namespace std;
#ifndef TCP_COMMAND_H_
#define TCP_COMMAND_H_

class Command {
 public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};



#endif /* TCP_COMMAND_H_ */
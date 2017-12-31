/*
 * CloseCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: avihay
 */

#ifndef TCP_CLOSECOMMAND_H_
#define TCP_CLOSECOMMAND_H_

#include "Command.h"

/*
 *
 */
class CloseCommand : public Command {
 public:
    void execute(vector<string> args, StructArgs *sa);
};

#endif /* TCP_CLOSECOMMAND_H_ */

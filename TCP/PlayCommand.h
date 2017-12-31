/*
 * PlayCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: avihay
 */

#ifndef TCP_PLAYCOMMAND_H_
#define TCP_PLAYCOMMAND_H_

#include "Command.h"

/*
 *
 */
class PlayCommand : public Command {
 public:
    void execute(vector<string> args, StructArgs *sa);
};

#endif /* TCP_PLAYCOMMAND_H_ */

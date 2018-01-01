/*
 * GetListCommand.h
 *
 *  Created on: Jan 1, 2018
 *      Author: kfir
 */

#ifndef GETLISTCOMMAND_H_
#define GETLISTCOMMAND_H_

#include "Command.h"

class GetListCommand : public Command {
public:
	void execute(vector<string> args, StructArgs *sa);
};

#endif /* GETLISTCOMMAND_H_ */

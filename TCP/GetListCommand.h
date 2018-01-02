/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef GETLISTCOMMAND_H_
#define GETLISTCOMMAND_H_

#include "Command.h"

class GetListCommand : public Command {
public:
    /**
     * given command 'get_list' the function send to client socket
     * the available game list.
     * @param args should return no argument in vector
     * @param sa client StructArgs
     */
	void execute(vector<string> args, StructArgs *sa);
};

#endif /* GETLISTCOMMAND_H_ */

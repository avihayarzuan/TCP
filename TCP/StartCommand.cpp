/*
 * StartCommand.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: avihay
 */

#include "StartCommand.h"

void StartCommand::execute(vector<string> args) {
//    vector<string> v = server.getCommandArgs(check);
    for (vector<string>::const_iterator i = args.begin(); i != args.end(); ++i) {
        cout << *i << endl;
    }

}

/*
 * PlayCommand.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: avihay
 */

#include "PlayCommand.h"

void PlayCommand::execute(vector<string> args, StructArgs *sa) {
    int oppSocket;

    for (vector<ActiveGames>::const_iterator it =
                    sa->activeGameVec->begin(); it != sa->activeGameVec->end();
                    it++) {
        if (sa->gameName.compare(it->name) == 0) {
            if (sa->socket == it->blackPlayer) {
                oppSocket = it->whitePlayer;
            } else {
                oppSocket = it->blackPlayer;
            }
        }
    }

    char buf[MAX_SIZE] = { 0 };
    string x = args.front();
    string y = args.back();
    strcpy(buf, "(");
    strcat(buf, x.c_str());
    strcat(buf, ", ");
    strcat(buf, y.c_str());
    strcat(buf, ")");

    write(oppSocket, buf, sizeof(char) * (MAX_SIZE));

}

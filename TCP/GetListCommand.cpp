/*
 * GetListCommand.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: kfir
 */

#include "GetListCommand.h"

void GetListCommand::execute(vector<string> args, StructArgs *sa) {
	int oppSocket = 0;
	string roomList = "Active rooms:\n";
	bool noActiveRooms = false;

	if(sa->activeGameVec->size()) {
		for (vector<ActiveGames>::const_iterator it = sa->activeGameVec->begin();
					it != sa->activeGameVec->end(); it++) {
				roomList += it->name;
				roomList += "\n";
			}
	} else {
		noActiveRooms = true;
	}

	char buf[MAX_SIZE] = { 0 };

	if(noActiveRooms) {
		strcpy(buf, "There are no active rooms at the moment...\n");
	} else {
		strcpy(buf, roomList.c_str());
	}

	write(oppSocket, buf, sizeof(char) * (MAX_SIZE));

}

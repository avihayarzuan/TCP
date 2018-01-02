/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "GetListCommand.h"

void GetListCommand::execute(vector<string> args, StructArgs *sa) {
	int socket =  sa->socket;
	string roomList = "Active rooms:\n";
	bool noActiveRooms = false;

	if(sa->gameList->size()) {
		for (map<string, int>::const_iterator it = sa->gameList->begin();
					it != sa->gameList->end(); it++) {
				roomList += it->first;
				roomList += "\n";
			}
	} else {
		noActiveRooms = true;
	}

	char buf[MAX_SIZE] = { 0 };

	if(noActiveRooms) {
		strcpy(buf, "There are no available rooms at the moment...\n");
	} else {
		strcpy(buf, roomList.c_str());
	}

	write(socket, buf, sizeof(char) * (MAX_SIZE));

}

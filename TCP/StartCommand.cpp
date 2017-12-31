/*
 * StartCommand.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: avihay
 */
#include "StartCommand.h"

void StartCommand::execute(vector<string> args, StructArgs *sa) {
    char buf[MAX_SIZE] = { 0 };
    char notValid[] = "-1";
    char valid[] = "1";

    for (vector<string>::const_iterator i = args.begin(); i != args.end();
            ++i) {
        cout << *i << endl;
    }
    if (isExist(args.front(), sa)) {
        write(sa->socket, notValid, sizeof(notValid));
    }else if (sa->gameList->count(args.front())) {
        write(sa->socket, notValid, sizeof(notValid));
    } else {
        write(sa->socket, valid, sizeof(valid));
        sa->gameList->insert(pair<string, int>(args.front(), sa->socket));
        sa->gameName = args.front();
        int stat;
        // reads 1 means verification by client
        stat = read(sa->socket, buf, sizeof(char) * (MAX_SIZE));
//        bool otherClient;
//        while (!isExist(args.front(), sa)) {
        while (sa->gameList->count(sa->gameName)) {
            //wait for the game to be in active games
        }
        cout << "start playing" << endl;
    }

}

bool StartCommand::isExist(string name, StructArgs *sa) {
    bool nameExist = false;
    for (vector<ActiveGames>::const_iterator it = sa->activeGameVec->begin();
            it != sa->activeGameVec->end(); it++) {
        if (name.compare(it->name) == 0) {
            nameExist = true;
            break;
        }
    }
    return nameExist;
}

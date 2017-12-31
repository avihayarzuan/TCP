/*
 * JoinCommand.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: avihay
 */

#include "JoinCommand.h"
pthread_mutex_t active_mutex;

void JoinCommand::execute(vector<string> args, StructArgs *sa) {
    char buf[MAX_SIZE] = { 0 };
    char notValid[] = "-1";
    char valid[] = "1";

    for (vector<string>::const_iterator i = args.begin(); i != args.end();
            ++i) {
        cout << *i << endl;
    }

    if (sa->gameList->count(args.front())) {
        write(sa->socket, valid, sizeof(valid));
        int firstPlayerSocket = sa->gameList->find(args.front())->second;
        ActiveGames ag;
        ag.name = args.front();
        ag.blackPlayer = firstPlayerSocket;
        ag.whitePlayer = sa->socket;
        pthread_mutex_lock(&active_mutex);
        sa->activeGameVec->push_back(ag);
        pthread_mutex_unlock(&active_mutex);
        sa->gameList->erase(args.front());
        //read value 1 from second client
        read(sa->socket, buf, sizeof(char) * (MAX_SIZE));
        sendColor(firstPlayerSocket, BLACK);
        sendColor(sa->socket, WHITE);
        sa->gameName = ag.name;
//        sa->playing = true;
//        sa->oppSocket = firstPlayerSocket;
    } else {
        write(sa->socket, notValid, sizeof(notValid));
    }
}

int JoinCommand::sendColor(int clientSocket, char color) {
    char buf[MAX_SIZE];
    buf[0] = color;
    int stat = write(clientSocket, buf, sizeof(char) * MAX_SIZE);
    return stat;
}

/*
 * InfoHeader.h
 *
 *  Created on: Dec 27, 2017
 *      Author: avihay
 */

#ifndef TCP_INFOHEADER_H_
#define TCP_INFOHEADER_H_
//#include "Server.h"
//#include "CommandManager.h"
#include <map>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

//class Server;
//class CommandManager;

struct ActiveGames {
    string name;
    int blackPlayer;
    int whitePlayer;
};

//struct findGame {
//    string name;
//    findGame(string name) : name(name){}
//    bool operator () (const ActiveGames& a) const
//    {
//        return a.name == name;
//    }
//};

struct StructArgs {
    map <string, int> * gameList;
    vector <ActiveGames> * activeGameVec;
    int socket;
    int oppSocket;
    string gameName;
    bool connected;
    bool playing;
};

//    CommandManager * manager;
//    Server *server;
//struct ThreadArgs {
//    Server *server;
//    map <string, int> * gameList;
//    CommandManager * manager;
//    int socket;
//};



#endif /* TCP_INFOHEADER_H_ */

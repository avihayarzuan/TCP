/*
 * ClientHandler.h
 *
 *  Created on: Dec 28, 2017
 *      Author: avihay
 */

#ifndef TCP_CLIENTHANDLER_H_
#define TCP_CLIENTHANDLER_H_

using namespace std;

//#include "InfoHeader.h"
#include "CommandManager.h"
#include <vector>
#include <string>


//struct ActiveGames {
//    string name;
//    int blackPlayer;
//    int whitePlayer;
//};

struct ThreadArgs {
    map<string, int> * openGameList;
    vector <ActiveGames> * activeGameVec;
    CommandManager * manager;
    int socket;
};

//struct StructArgs;
////struct ThreadArgs;
//class Server;
//class CommandManager;
/*
 *
 */
class ClientHandler {
 public:
    ClientHandler();

    static void * handle(void *s);

    static int firstContact(ThreadArgs *sa);

    static void play(int socket1, int socket2);

    bool hasError(int stat);

    static string getCommandFromBuf(char buf[]);

    static vector<string> getCommandArgsFromBuf(char buf[]);

    virtual ~ClientHandler();
};

#endif /* TCP_CLIENTHANDLER_H_ */

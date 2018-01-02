/*
 * Kfir Ventura
 * Avihay Arzuan
 */
/**
 * all other classes use include this class,
 * so the includes, mutex and structs are given here.
 */

using namespace std;
#ifndef TCP_COMMAND_H_
#define TCP_COMMAND_H_

#define MAX_SIZE 256
#define BLACK 'X'
#define WHITE 'O'

#include <map>
#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <pthread.h>
#include <cstdlib>

struct ActiveGames {
    string name;
    int blackPlayer;
    int whitePlayer;
};

struct StructArgs {
    map<string, int> * gameList;
    vector<ActiveGames> * activeGameVec;
    int socket;
    int oppSocket;
    string gameName;
    bool connected;
    bool playing;
};

class Command {
 public:
    virtual void execute(vector<string> args, StructArgs *sa) = 0;
    virtual ~Command() {
    }
    pthread_mutex_t m1;
};

#endif /* TCP_COMMAND_H_ */

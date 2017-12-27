/**
 **/

#ifndef TCPSERVER_SERVER_H
#define TCPSERVER_SERVER_H

#include "CommandManager.h"
#include <map>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


//struct ThreadArgs {
//    Server *server;
//    int socket;
//};

class Server {
public:
    /**
     * constructor for the server class
     * @param port the port number to run the server
     */
    Server(const int port);
    /**
     * starts the server
     * create a socket to the server and
     * assign a local address to the socket
     */
    void start();
    /**
     * close the socket of the server
     */
    void stop();
    /**
     *using the socket the sever starts to listen and then
     * start communicate with the players.
     */
    void handleClients();
//private:
    // the port number for the server
    int port;
    // the socket's file descriptor
    int serverSocket;

    bool shouldExit;

    map <string, int> gameList;

    CommandManager manager;

    string getCommand(char buf[]);

    vector<string> getCommandArgs(char buf[]);

    int askForCommand(int client);
    /**
     * using two different socket the server starts the game
     * @param clientSocketFirst
     * @param clientSocketSecond
     */
    void play(int clientSocketFirst, int clientSocketSecond);
    /**
     * the function responsible for the game flow
     * @param clientSocketFirst the starting player
     * @param clientSocketSecond the second player
     * @return
     */
    int playOneTurn(int clientSocketFirst, int clientSocketSecond);
    /**
     * when starting the game the function send to the socket the
     * player color for the game
     * @param clientSocket
     * @param color
     * @return the status of sending the message
     */
    int sendColor(int clientSocket, char color);
    /**
     * check if there is an error, depends the return value.
     * @param stat
     * @return true if there is an error, false otherwise
     */
    bool hasError(int stat);

};

#endif //TCPSERVER_SERVER_H

/**
 **/


#include "ClientHandler.h"
#include <vector>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef TCPSERVER_SERVER_H
#define TCPSERVER_SERVER_H


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
    ClientHandler clientHandler;
    bool shouldExit;
    vector <string> gameList;
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
//    void *mainThread(void *arg);
};

#endif //TCPSERVER_SERVER_H

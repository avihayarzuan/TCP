/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCPSERVER_SERVER_H
#define TCPSERVER_SERVER_H

#include "ClientHandler.h"
#include "ThreadPool.h"

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

    int port;

    int serverSocket;

    bool shouldExit;

    //list of available games
    map<string, int> openGameList;

    // active game vector
    vector <ActiveGames> activeGameVec;

    //thread list to close when server is closed
    vector <pthread_t> threadList;

    ClientHandler *clientHandler;

//    CommandManager cm;




};

#endif //TCPSERVER_SERVER_H

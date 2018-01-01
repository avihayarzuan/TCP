/**
 **/
#include "Server.h"

#define MAX_CONNECTED_CLIENTS 10
#define MOVE_SIZE 256
#define ERROR -1
#define NO_CONNECTION 0
#define BLACK 'X'
#define WHITE 'O'
#define END_GAME "End"
#define SERVER_EXIT "exit"

//pthread_mutex_t m1;

void * mainThread(void *s);
void * listenToExit(void*s);

//
//struct ThreadArgs {
//    Server *server;
//    map <string, int> * gameList;
//    CommandManager * manager;
//    int socket;
//};

Server::Server(const int port)
        : port(port),
          serverSocket(0),
          shouldExit(false) {

    this->clientHandler = new ClientHandler();
    cout << "Server" << endl;
}

void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress,
             sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
//    pthread_t exitLoop;
//    int rc1 = pthread_create(&exitLoop, NULL, listenToExit, this);
//    if (rc1) {
//        cout << "Error: unable to create thread, " << rc1 << endl;
//        exit(-1);
//    }
    pthread_t maint;
    int rc = pthread_create(&maint, NULL, mainThread, this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    this->threadList.push_back(maint);
    while (!this->shouldExit) {
        cout << "Type 'exit' to turn off the server" << endl;
        string input = "";
        string exitStr("exit");
        getline(cin, input);
        cout << input << endl;
        if (input.compare(exitStr) == 0) {
            cout << "Shutting down server" << endl;
            this->shouldExit = true;
            break;
        }
    }
    this->stop();
//    this->closeServer();
//    pthread_exit(NULL);
    delete this->clientHandler;
}

void * mainThread(void *s) {
    CommandManager manager;
    int count = 0;
    cout << "Server thread created" << endl;
    Server *server = (Server*) s;
    listen(server->serverSocket, MAX_CONNECTED_CLIENTS);
    while (!server->shouldExit) {
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof((struct sockaddr*) &clientAddress);
        cout << "Waiting for clients connections..." << endl;
        int clientSocket = accept(server->serverSocket,
                                  (struct sockaddr *) &clientAddress,
                                  &clientAddressLen);
        count++;
        if (clientSocket == ERROR) {
            throw "Error on accept client";
        }
        cout << "Client connected. number: " << count << endl;
        pthread_t handleThread;
        ThreadArgs args;
        args.openGameList = &server->openGameList;
        args.activeGameVec = &server->activeGameVec;
        args.manager = &manager;
        args.socket = clientSocket;
        args.shouldClose = &server->shouldExit;
        int rc = pthread_create(&handleThread, NULL,
                                server->clientHandler->handle, &args);
        server->threadList.push_back(handleThread);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
    }

//        pthread_exit(NULL);
    return s;
}

void Server::closeServer() {
    for (vector<pthread_t>::iterator i = threadList.begin();
            i != threadList.end(); ++i) {
        pthread_cancel(*i);
        pthread_join(*i, NULL);
    }
}

void Server::stop() {
    for (vector<pthread_t>::iterator i = threadList.begin();
            i != threadList.end(); ++i) {
        pthread_cancel(*i);
    }
    close(serverSocket);
    cout << "server stopped" << endl;
}

void * listenToExit(void *s) {
    Server * server = (Server *) s;
    while (true) {
        cout << "Type 'exit' to turn off the server" << endl;
        string input = "";
        string exitStr("exit");
        getline(cin, input);
        cout << input << endl;
        if (input.compare(exitStr) == 0) {
            cout << "Shutting down server" << endl;
            server->shouldExit = true;
            break;
        }
    }
    return s;
}

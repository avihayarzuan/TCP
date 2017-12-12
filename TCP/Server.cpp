/**
 **/

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define MOVE_SIZE 256
#define ERROR -1
#define NO_CONNECTION 0
#define BLACK 'X'
#define WHITE 'O'
#define END_GAME "End"

Server::Server(const int port)
        : port(port),
          serverSocket(0) {
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
    while (true) {
        this->handleClients();
    }
}

void Server::handleClients() {
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    // Define the client socket's structures
    struct sockaddr_in clientAddressFirst;
    socklen_t clientAddressLenFirst =
            sizeof((struct sockaddr*) &clientAddressFirst);
    struct sockaddr_in clientAddressSecond;
    socklen_t clientAddressLenSecond =
            sizeof((struct sockaddr*) &clientAddressSecond);
    cout << "Waiting for clients connections..." << endl;
    // Accept a new client connection
    int clientSocketFirst = accept(serverSocket,
                                   (struct sockaddr *) &clientAddressFirst,
                                   &clientAddressLenFirst);
    if (clientSocketFirst == ERROR) {
        throw "Error on accept first client";
    }
    cout << "Client first connected" << endl;
    int clientSocketSecond = accept(serverSocket,
                                    (struct sockaddr *) &clientAddressSecond,
                                    &clientAddressLenSecond);
    if (clientSocketSecond == ERROR) {
        throw "Error on accept second client";
    }
    cout << "Client second connected" << endl;
    play(clientSocketFirst, clientSocketSecond);
    // Close communication with the client
    close(clientSocketFirst);
    close(clientSocketSecond);
}

void Server::play(int clientSocketBlack, int clientSocketWhite) {
    int stat;
    stat = sendColor(clientSocketBlack, BLACK);
    if (hasError(stat)) {
        return;
    }
    cout << "sent black color" << endl;
    stat = sendColor(clientSocketWhite, WHITE);
    if (hasError(stat)) {
        return;
    }
    cout << "sent white color" << endl;
    bool shouldPlay = true;
    bool blackPlayerTurn = true;
    while (shouldPlay) {
        if (blackPlayerTurn) {
            stat = playOneTurn(clientSocketBlack, clientSocketWhite);
            blackPlayerTurn = false;
        } else {
            stat = playOneTurn(clientSocketWhite, clientSocketBlack);
            blackPlayerTurn = true;
        }
        if (stat <= 0) {
            shouldPlay = false;
        }
    }
}

int Server::playOneTurn(int clientSocket1, int clientSocket2) {
    char buf[MOVE_SIZE] = {0};
    int stat;
    stat = read(clientSocket1, buf, sizeof(char) * (MOVE_SIZE));
    if (hasError(stat)) {
        return stat;
    }
    stat = write(clientSocket2, buf, sizeof(char) * (MOVE_SIZE));
    if (hasError(stat)) {
        return stat;
    }
    if (strcmp(buf, END_GAME) == 0) {
        stat = -7;
    }
    return stat;
}

int Server::sendColor(int clientSocket, char color) {
    char buf[MOVE_SIZE];
    buf[0] = color;
    int stat = write(clientSocket, buf, sizeof(char) * MOVE_SIZE);
    return stat;
}

bool Server::hasError(int stat) {
    if (stat == ERROR) {
        cout << "Error sending to socket" << endl;
        return true;
    }
    if (stat == NO_CONNECTION) {
        cout << "Error in connection" << endl;
        return true;
    }
    return false;
}

void Server::stop() {
    close(serverSocket);
}

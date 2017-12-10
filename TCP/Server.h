/**
 **/

#ifndef TCPSERVER_SERVER_H
#define TCPSERVER_SERVER_H


class Server {
public:
    Server(const int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocket);
    void play(int clientSocketFirst, int clientSocketSecond);
    int playOneTurn(int clientSocketFirst, int clientSocketSecond);
    int sendColor(int clientSocket, char color);
    bool hasError(int stat);
    void handleClients();
};

#endif //TCPSERVER_SERVER_H

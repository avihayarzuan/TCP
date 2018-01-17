/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "Server.h"
//#include "HandleClientTask.h"

#define MAX_CONNECTED_CLIENTS 10
#define MOVE_SIZE 256
#define ERROR -1
#define NO_CONNECTION 0
#define BLACK 'X'
#define WHITE 'O'
#define END_GAME "End"
#define SERVER_EXIT "exit"

#define THREAD_NUM 5
#define TASKS_NUM 10

void* sendToClientHandler(void *taskId);
void * mainThread(void *s);

struct StructTask {
    Server *s;
    int socket;
//    pthread_t t;
    CommandManager *m;
};

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
    delete this->clientHandler;
}

void * mainThread(void *s) {
    CommandManager manager;
    //creates a Thread pool of size 5:
    ThreadPool pool(THREAD_NUM);
    vector<Task*> v;
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
        StructTask st;
        st.s = server;
        st.socket = clientSocket;
        st.m = &manager;
        Task *task = new Task(sendToClientHandler, (void *) &st);
        v.push_back(task);
        pool.addTask(task);

    }
    pool.terminate();
    for (vector<Task*>::iterator i = v.begin();
            i != v.end(); ++i) {
        delete(*i);
    }
    return s;
}

// the task to run run by the ThreadPool
void* sendToClientHandler(void *taskId) {
    StructTask * ta = (StructTask*) taskId;

    ThreadArgs args;
    args.openGameList = &ta->s->openGameList;

    args.activeGameVec = &ta->s->activeGameVec;
    args.manager = ta->m;
    args.socket = ta->socket;
    args.shouldClose = &ta->s->shouldExit;
    ta->s->clientHandler->handle((void *) &args);
    return taskId;
}

void Server::stop() {

    for (vector<pthread_t>::iterator i = threadList.begin();
            i != threadList.end(); ++i) {
        pthread_cancel(*i);
    }
    close(serverSocket);
    cout << "server stopped" << endl;
}

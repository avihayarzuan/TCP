/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "ClientHandler.h"

#define MESSAGE_SIZE 256
#define MOVE_SIZE 256
#define ERROR -1
#define NO_CONNECTION 0

ClientHandler::ClientHandler() {
}

ClientHandler::~ClientHandler() {
}

void * ClientHandler::handle(void *s) {
    ThreadArgs * ta = (ThreadArgs*) s;
    CommandManager *manager = ta->manager;
    StructArgs client;
    client.gameList = ta->openGameList;
    client.activeGameVec = ta->activeGameVec;
    client.socket = ta->socket;
    client.connected = true;
    //loop that reads from user sockets, runs as a thread.
    while (client.connected && !*ta->shouldClose) {
        int stat;
        char buf[MOVE_SIZE] = { 0 };
        stat = read(client.socket, buf, sizeof(char) * (MOVE_SIZE));
        if (stat < 0 || buf[0] == '\0') {
            cout << "Disconnecting from server" << endl;
            break;
        }
        string command = ClientHandler::getCommandFromBuf(buf);
        cout << command << endl;
        vector<string> v = ClientHandler::getCommandArgsFromBuf(buf);
        manager->executeCommand(command, v, &client);
    }
    close(client.socket);

    return s;
}

//get first word out of char array
string ClientHandler::getCommandFromBuf(char buf[]) {
    string str(buf);
    for (int i = 0; i < MESSAGE_SIZE; i++) {
        if ((buf[i] == ' ') || (buf[i] == '\0')) {
            string command = str.substr(0, i);
            return command;
        }
    }
    //should not get this line
    return "error in message";
}

//read from char array words from the second word until the end.
vector<string> ClientHandler::getCommandArgsFromBuf(char buf[]) {
    string str(buf);
    vector<string> v;
    int i;
    for (i = 0; i < MESSAGE_SIZE; i++) {
        if (buf[i] == ' ') {
            i++;
            break;
        }
    }
    char seperator = ' ';
    string args = str.substr(i);
    for (size_t p = 0, q = 0; p != args.npos; p = q) {
        v.push_back(
                args.substr(p + (p != 0),
                            (q = args.find(seperator, p + 1)) - p - (p != 0)));
    }
    return v;
}

bool ClientHandler::hasError(int stat) {
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

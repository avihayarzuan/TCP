#include "Server.h"
#include "ReadPort.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    // name of the file of settings
    char buf[] = "settings.txt";
    const int port = ReadPort::getPort(buf);
    Server server(port);
    try {
        server.start();
//        server.
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}

//    char check[] = "start rrr rr ee";
//    string c = server.getCommand(check);
//    cout << c;
//    vector<string> v = server.getCommandArgs(check);
//    for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i)
//        cout << *i << endl;

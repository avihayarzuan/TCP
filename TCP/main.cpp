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
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}

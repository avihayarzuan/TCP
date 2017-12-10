#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include "ReadPort.h"
using namespace std;

int main() {
    char buf[] = "settings.txt";
    const int port = ReadPort::getPort(buf);
    cout << port << endl;
    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}

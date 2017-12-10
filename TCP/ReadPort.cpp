/*
 * ReadPort.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: avihay
 */

#include "ReadPort.h"

int ReadPort::getPort(char * path) {
    int port = -1;
    ifstream file;
    file.open(path);
    if (file.is_open()) {
        string line;
        getline(file, line);
        int start = line.find("(");
        int end = line.find(")");
        int diff = (end - start);
        string num = line.substr(start+1, (diff-1));
        port = atoi(num.c_str());
        file.close();
    }
    return port;
}

/*
 * ClientHandler.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */

#include "ClientHandler.h"

ClientHandler::ClientHandler() {
    // TODO Auto-generated constructor stub

}

ClientHandler::~ClientHandler() {
    // TODO Auto-generated destructor stub
}

void * ClientHandler::handle(void *socket) {
    pthread_t h;
//    int rc = pthread_create(&h, NULL, )
    return socket;
}

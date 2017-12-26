/*
 * ClientHandler.h
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */
#include <pthread.h>
#include <cstdlib>

using namespace std;
#ifndef TCP_CLIENTHANDLER_H_
#define TCP_CLIENTHANDLER_H_

/*
 *
 */
class ClientHandler {
 public:
    ClientHandler();
    static void *handle(void * socket);
    virtual ~ClientHandler();
};

#endif /* TCP_CLIENTHANDLER_H_ */

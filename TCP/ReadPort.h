/*
 * ReadPort.h
 *
 *  Created on: Dec 10, 2017
 *      Author: avihay
 */

#ifndef TCP_READPORT_H_
#define TCP_READPORT_H_

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
/*
 *
 */
class ReadPort {
 public:
    static int getPort(char * path);
};

#endif /* TCP_READPORT_H_ */

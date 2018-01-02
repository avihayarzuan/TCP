/*
 * Kfir Ventura
 * Avihay Arzuan
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
    /**
     * using the file name it reads from it the port number
     * @param path settings text file
     * @return int of the port number
     */
    static int getPort(char * path);
};

#endif /* TCP_READPORT_H_ */

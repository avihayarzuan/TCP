/*
 * Command.h
 *
 *  Created on: Dec 26, 2017
 *      Author: avihay
 */

using namespace std;
#ifndef TCP_COMMAND_H_
#define TCP_COMMAND_H_

#define MAX_SIZE 256
#define BLACK 'X'
#define WHITE 'O'

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include "InfoHeader.h"

struct StructArgs;

class Command {
 public:
    virtual void execute(vector<string> args, StructArgs *sa) = 0;



    virtual ~Command() {
    }
};

#endif /* TCP_COMMAND_H_ */

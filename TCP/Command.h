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

    bool isExist(string name, StructArgs *sa) {
        bool nameExist = false;
        for (vector<ActiveGames>::const_iterator it =
                sa->activeGameVec->begin(); it != sa->activeGameVec->end();
                it++) {
            if (sa->gameName.compare(it->name)) {
                nameExist = true;
                break;
            }
        }
//        if (sa->gameList->count(name)) {
//            nameExist = true;
//        }
        return nameExist;
    }
    ;

    virtual ~Command() {
    }
};

#endif /* TCP_COMMAND_H_ */

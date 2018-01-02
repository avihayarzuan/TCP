/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#include "CloseCommand.h"

void CloseCommand::execute(vector<string> args, StructArgs *sa) {
    for (vector<ActiveGames>::iterator it = sa->activeGameVec->begin();
            it != sa->activeGameVec->end(); it++) {
        if (args.front().compare(it->name) == 0) {
            sa->activeGameVec->erase(it);
            break;
        }
    }
    sa->connected = false;
}

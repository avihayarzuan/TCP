/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_CLIENTHANDLER_H_
#define TCP_CLIENTHANDLER_H_

#include "CommandManager.h"
#include <vector>
#include <string>

struct ThreadArgs {
    map<string, int> * openGameList;
    vector<ActiveGames> * activeGameVec;
    CommandManager * manager;
    bool * shouldClose;
    int socket;
};

class ClientHandler {
 public:
    ClientHandler();

    virtual ~ClientHandler();
    /**
     * the function is static, should get a pointer to ThreadArgs struct
     * reads commands in loop from user and acts accordingly
     * @param s pointer to TreadArgs struct
     */
    static void * handle(void *s);
    /**
     * checks if the stat param means error
     * @param stat int to check value of.
     * @return true if has error, false otherwise
     */
    bool hasError(int stat);
    /**
     * get char array and parse the command from it
     * @param buf message from user
     * @return string of the command
     */
    static string getCommandFromBuf(char buf[]);
    /**
     * read from char array arguments and keep it in vector of strings
     * @param buf message from user
     * @return vector of the arguments
     */
    static vector<string> getCommandArgsFromBuf(char buf[]);
};

#endif /* TCP_CLIENTHANDLER_H_ */

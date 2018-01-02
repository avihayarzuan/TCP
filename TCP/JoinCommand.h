/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_JOINCOMMAND_H_
#define TCP_JOINCOMMAND_H_

#include "Command.h"

class JoinCommand : public Command {
 public:
    /**
     * given command 'join' and argument of the game name to join.
     * checks if the game name is available to join to.
     * if available sends the players their colors to start the game
     * @param args the game name
     * @param sa StructArgs of client.
     */
    void execute(vector<string> args, StructArgs *sa);
    /**
     * send the player socket his color of the game.
     * @param clientSocket
     * @param color
     * @return status of success to write
     */
    int sendColor(int clientSocket, char color);
};

#endif /* TCP_JOINCOMMAND_H_ */

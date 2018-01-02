/*
 * Kfir Ventura
 * Avihay Arzuan
 */

#ifndef TCP_PLAYCOMMAND_H_
#define TCP_PLAYCOMMAND_H_

#include "Command.h"

/*
 *
 */
class PlayCommand : public Command {
 public:
    /**
     * given command 'play' and argument of the move to play
     * send to opponent socket the move.
     * @param args the x y move
     * @param sa StructArgs of client.
     */
    void execute(vector<string> args, StructArgs *sa);
};

#endif /* TCP_PLAYCOMMAND_H_ */

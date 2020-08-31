#ifndef NINEMANSMORRIS_TURNSTRATEGY_H
#define NINEMANSMORRIS_TURNSTRATEGY_H

#include "../player.h"
#include "../board.h"
class turnStrategy {
public:
  virtual int doTurn(player * player, board * board) = 0;
};

#endif // NINEMANSMORRIS_TURNSTRATEGY_H

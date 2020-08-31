#ifndef NINEMANSMORRIS_MOVINGTURNSTRATEGY_H
#define NINEMANSMORRIS_MOVINGTURNSTRATEGY_H

#include "../board.h"
#include "turnStrategy.h"
class movingTurnStrategy : public turnStrategy {
  int doTurn(player *player, board *board) override;
};

#endif // NINEMANSMORRIS_MOVINGTURNSTRATEGY_H

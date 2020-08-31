#ifndef NINEMANSMORRIS_INITIALTURNSTRATEGY_H
#define NINEMANSMORRIS_INITIALTURNSTRATEGY_H
#include "../board.h"
#include "turnStrategy.h"

class initialTurnStrategy : public turnStrategy {
  int doTurn(player *player, board *board) override;
};

#endif // NINEMANSMORRIS_INITIALTURNSTRATEGY_H

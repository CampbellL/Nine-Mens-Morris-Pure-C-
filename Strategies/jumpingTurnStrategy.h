#ifndef NINEMANSMORRIS_JUMPINGTURNSTRATEGY_H
#define NINEMANSMORRIS_JUMPINGTURNSTRATEGY_H

#include "../board.h"
#include "turnStrategy.h"
class jumpingTurnStrategy : public turnStrategy {
  int doTurn(player *player, board *board) override;
};

#endif // NINEMANSMORRIS_JUMPINGTURNSTRATEGY_H

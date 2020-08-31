#define PRINT_LN(x) std::cout << x << std::endl
#include "initialTurnStrategy.h"
#include <iostream>
int initialTurnStrategy::doTurn(player *player, board *board) {
  auto position = -1;
  PRINT_LN("Choose a position for your piece!");
  std::cin >> position;
  if (board->placePiece(position)) {
    player->placePiece(position);
    return position;
  }
  return -1;
}

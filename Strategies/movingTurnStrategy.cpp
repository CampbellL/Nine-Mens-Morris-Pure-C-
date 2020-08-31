#define PRINT_LN(x) std::cout << x << std::endl
#include "movingTurnStrategy.h"
#include <iostream>
int movingTurnStrategy::doTurn(player *player, board *board) {
  auto pieceToMove = -1;
  auto target = -1;
  PRINT_LN("Select a piece to move");
  std::cin >> pieceToMove;
  PRINT_LN("Select a the target to move to");
  std::cin >> target;
  if (board->movePiece(pieceToMove, target)) {
    player->movePieceInPieces(pieceToMove, target);
    return target;
  }
  return -1;
}

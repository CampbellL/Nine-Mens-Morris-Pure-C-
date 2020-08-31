#ifndef NINEMANSMORRIS_GAME_H
#define NINEMANSMORRIS_GAME_H

#include "Strategies/turnStrategy.h"
#include "board.h"

class game {
public:
  int static currentPlayer;

  void start();

  game();

  static std::string getPlayerIcon(int id);

private:
  std::array<player, 2> players;
  board board;

  turnStrategy * strategy;

  void setStrategy(turnStrategy *newStrategy);

  static void nextTurn();

  void removePieceFromGame();

  player * getCurrentOpponent();
};

#endif // NINEMANSMORRIS_GAME_H

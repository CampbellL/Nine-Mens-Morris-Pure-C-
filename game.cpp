#include "game.h"
#include "Strategies/initialTurnStrategy.h"
#include "Strategies/jumpingTurnStrategy.h"
#include "Strategies/movingTurnStrategy.h"
#include "Strategies/turnStrategy.h"
#include <iostream>

#define PRINT_LN(x) std::cout << x << std::endl

int game::currentPlayer = 1;

void game::start() {
  initialTurnStrategy initialTurnStrategy;
  jumpingTurnStrategy jumpingTurnStrategy;
  movingTurnStrategy movingTurnStrategy;

  while (true) {
    this->board.draw();
    PRINT_LN("Player " << game::getPlayerIcon(currentPlayer) << "'s turn");
    auto player = &this->players[game::currentPlayer - 1];
    if (player->hasThreePieces() && player->currentPhase == Movement) {
      player->nextPhase();
    }
    switch (player->currentPhase) {
    case Initial: {
      this->setStrategy(&initialTurnStrategy);
      break;
    }
    case Movement: {
      this->setStrategy(&movingTurnStrategy);
      break;
    }
    case Jumping: {
      this->setStrategy(&jumpingTurnStrategy);
      break;
    }
    }
    int position = -2;
    while (position < 0) {
      position = this->strategy->doTurn(player, &this->board);
      if (position == -1) {
        PRINT_LN("Illegal Move");
      }
    }
    if (this->board.isMill(position)) {
      this->removePieceFromGame();
    }
    if (player->isOutOfPieces()) {
      player->nextPhase();
    }
    if (getCurrentOpponent()->hasLost()) {
      PRINT_LN("Player " << game::getPlayerIcon(currentPlayer) << "'won");
      exit(0);
    }
    game::nextTurn();
  }
}

void game::removePieceFromGame() {
  auto removePos = -1;
  bool pieceRemoved = false;
  while (!pieceRemoved) {
    this->board.draw();
    PRINT_LN("You have scored a mill! Choose the piece you want to remove");
    std::cin >> removePos;
    if (this->board.removePiece(removePos, this->getCurrentOpponent())) {
      pieceRemoved = true;
    }
  }
}

std::string game::getPlayerIcon(int id) {
  switch (id) {
  case 0:
    return "x";
  case 1:
    return "○";
  case 2:
    return "●";
  default:
    return "";
  }
}

void game::nextTurn() {
  game::currentPlayer == 1 ? currentPlayer = 2 : currentPlayer = 1;
}

game::game() {
  this->players = {player(), player()};
  this->strategy = nullptr;
  game::currentPlayer = 1;
}

player *game::getCurrentOpponent() {
  return &this->players[(game::currentPlayer == 1 ? 2 : 1) - 1];
}

void game::setStrategy(turnStrategy *newStrategy) {
  this->strategy = newStrategy;
}

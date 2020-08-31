#include <iostream>

#define PRINT_LN(x) std::cout << x << std::endl

#include "board.h"
#include "game.h"

void board::draw() {
  PRINT_LN(this->getNodeCharAtPosition(0) + "--------------" +
          this->getNodeCharAtPosition(1) + "--------------" +
          this->getNodeCharAtPosition(2));
  PRINT_LN("|              |              |");
  PRINT_LN("|    " + this->getNodeCharAtPosition(3) + "---------" +
          this->getNodeCharAtPosition(4) + "---------" +
          this->getNodeCharAtPosition(5) + "    |");
  PRINT_LN("|    |         |         |    |");
  PRINT_LN("|    |    " + this->getNodeCharAtPosition(6) + "----" +
          this->getNodeCharAtPosition(7) + "----" +
          this->getNodeCharAtPosition(8) + "    |    |");
  PRINT_LN("|    |    |         |    |    |");
  PRINT_LN("" + this->getNodeCharAtPosition(9) + "----" +
          this->getNodeCharAtPosition(10) + "----" +
          this->getNodeCharAtPosition(11) + "         " +
          this->getNodeCharAtPosition(12) + "----" +
          this->getNodeCharAtPosition(13) + "----" +
          this->getNodeCharAtPosition(14) + "");
  PRINT_LN("|    |    |         |    |    |");
  PRINT_LN("|    |    " + this->getNodeCharAtPosition(15) + "----" +
          this->getNodeCharAtPosition(16) + "----" +
          this->getNodeCharAtPosition(17) + "    |    |");
  PRINT_LN("|    |         |         |    |");
  PRINT_LN("|    " + this->getNodeCharAtPosition(18) + "---------" +
          this->getNodeCharAtPosition(19) + "---------" +
          this->getNodeCharAtPosition(20) + "    |");
  PRINT_LN("|              |              |");
  PRINT_LN("" + this->getNodeCharAtPosition(21) + "--------------" +
          this->getNodeCharAtPosition(22) + "--------------" +
          this->getNodeCharAtPosition(23) + "");
}

std::string board::getNodeCharAtPosition(int position) {
  if (position > this->vertices.size())
    throw std::logic_error(
        "The position given is outside the bounds of the board");
  return game::getPlayerIcon(this->vertices[position]);
}

bool board::isInBounds(int position) const {
  return position > this->vertices.size() || position < 0;
}

bool board::placePiece(int position) {
  if (this->isInBounds(position))
    throw std::logic_error(
        "The position given is outside the bounds of the board");
  if (this->vertices[position] != 0)
    return false;
  this->setNodeAtPosition(position);
  return true;
}

void board::setNodeAtPosition(int position) {
  if (this->isInBounds(position))
    throw std::logic_error(
        "The position given is outside the bounds of the board");
  this->vertices[position] = game::currentPlayer;
}

bool board::isConnected(int position1, int position2) {
  for (auto & edge : this->edges) {
    if (edge[0] == std::min(position1, position2) &&
        edge[1] == std::max(position1, position2)) {
      return true;
    }
  }
  return false;
}

board::board() = default;

void board::clearBrokenMills(int position, int playerId) {
  int point1, point2, point3;

  for (auto &possibleMillPosition : this->possibleMillPositions) {
    point1 = possibleMillPosition[0];
    point2 = possibleMillPosition[1];
    point3 = possibleMillPosition[2];
    if (point1 == position || point2 == position || point3 == position) {
      if (this->vertices[point1] == playerId && this->vertices[point2] == playerId &&
          this->vertices[point3] == playerId) {
        this->protectedPoints.erase(
            std::find(protectedPoints.begin(), protectedPoints.end(), point1));
        this->protectedPoints.erase(
            std::find(protectedPoints.begin(), protectedPoints.end(), point2));
        this->protectedPoints.erase(
            std::find(protectedPoints.begin(), protectedPoints.end(), point3));
      }
    }
  }
}

bool board::isMill(int position) {
  int player = 0;
  int point1, point2, point3;

  for (auto &possibleMillPosition : this->possibleMillPositions) {
    point1 = possibleMillPosition[0];
    point2 = possibleMillPosition[1];
    point3 = possibleMillPosition[2];
    if (point1 == position || point2 == position || point3 == position) {
      if (this->vertices[point1] != 0 &&
          this->vertices[point1] == this->vertices[point2] &&
          this->vertices[point2] == this->vertices[point3]) {
        this->protectedPoints.push_back(point1);
        this->protectedPoints.push_back(point2);
        this->protectedPoints.push_back(point3);
        player = this->vertices[point1];
      }
    }
  }
  return player != 0;
}

bool board::removePiece(int position, player *player) {
  auto playerId = (game::currentPlayer == 1 ? 2 : 1);

  if (player->hasUnprotectedPiecesOnBoard(this->protectedPoints) &&
      std::find(this->protectedPoints.begin(), this->protectedPoints.end(),
                position) != this->protectedPoints.end()) {
    return false;
  }

  if (this->vertices[position] != playerId) {
    return false;
  }

  this->clearBrokenMills(position, playerId);

  player->removePieceFromPieces(position);

  this->vertices[position] = 0;

  return true;
}

bool board::movePiece(int startPosition, int targetPosition) {
  bool connected = isConnected(startPosition, targetPosition);

  if (this->vertices[startPosition] != game::currentPlayer ||
      this->vertices[targetPosition] != 0 || !connected) {
    return false;
  }

  this->clearBrokenMills(startPosition, game::currentPlayer);

  this->vertices[startPosition] = 0;
  this->vertices[targetPosition] = game::currentPlayer;

  return true;
}

bool board::movePieceFreely(int startPosition, int targetPosition, player * player) {
  if(this->vertices[startPosition] != game::currentPlayer || this->vertices[targetPosition] != 0) {
    return false;
  }

  player->movePieceInPieces(startPosition, targetPosition);

  this->vertices[startPosition] = 0;
  this->vertices[targetPosition] = game::currentPlayer;

  return true;
}

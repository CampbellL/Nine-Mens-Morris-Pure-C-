#include "player.h"

bool player::isOutOfPieces() const { return this->pieceCount == 0; }

void player::placePiece(int position) {
  this->piecePositions.push_back(position);
  this->pieceCount -= 1;
}

void player::removePieceFromPieces(int position) {
  if (!this->piecePositions.empty()) {
    this->piecePositions.erase(
        std::find(piecePositions.begin(), piecePositions.end(), position));
  }
}

void player::movePieceInPieces(int startPosition, int targetPosition) {
  removePieceFromPieces(startPosition);
  pieceCount++;
  placePiece(targetPosition);
}

bool player::hasUnprotectedPiecesOnBoard(std::vector<int> protectedPoints) {
  for (int &piecePosition : piecePositions) {
    if (std::find(protectedPoints.begin(), protectedPoints.end(),
                  piecePosition) == protectedPoints.end())
      return true;
  }
  return false;
}

void player::nextPhase() { this->currentPhase++; }

bool player::hasLost() const {
  return this->piecePositions.size() < 3 && currentPhase != Initial;
}
bool player::hasThreePieces() const {
  return this->piecePositions.size() == 3 && currentPhase != Initial;
}

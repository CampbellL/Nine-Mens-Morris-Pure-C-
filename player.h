#ifndef NINEMANSMORRIS_PLAYER_H
#define NINEMANSMORRIS_PLAYER_H

#include <vector>

enum phase { Initial = 0, Movement = 1, Jumping = 2 };

class player {
private:
  std::vector<int> piecePositions = {};

  int pieceCount = 9;

public:
  int currentPhase = 0;

  [[nodiscard]] bool hasThreePieces() const;

  void placePiece(int position);

  [[nodiscard]] bool hasLost() const;

  void nextPhase();

  void removePieceFromPieces(int position);

  void movePieceInPieces(int startPosition, int targetPosition);

  [[nodiscard]] bool isOutOfPieces() const;

  bool hasUnprotectedPiecesOnBoard(std::vector<int> protectedPoints);
};

#endif // NINEMANSMORRIS_PLAYER_H

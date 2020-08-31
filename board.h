#ifndef NINEMANSMORRIS_BOARD_H
#define NINEMANSMORRIS_BOARD_H

#include "player.h"
#include <array>
#include <vector>

class board {
public:
  board();

private:
  std::array<int, 24> vertices = {{0}};
  std::vector<int> protectedPoints;
  std::array<std::array<int, 2>, 32> edges = {
      {{{0, 1}},   {{0, 9}},   {{1, 2}},   {{1, 4}},   {{2, 14}},  {{3, 10}},
       {{3, 4}},   {{4, 5}},   {{4, 7}},   {{5, 13}},  {{6, 7}},   {{6, 11}},
       {{7, 8}},   {{8, 12}},  {{9, 10}},  {{9, 21}},  {{10, 11}}, {{10, 18}},
       {{11, 15}}, {{12, 13}}, {{12, 17}}, {{13, 14}}, {{13, 20}}, {{14, 23}},
       {{15, 16}}, {{16, 17}}, {{16, 19}}, {{18, 19}}, {{19, 20}}, {{19, 22}},
       {{21, 22}}, {{22, 23}}}};
  std::array<std::array<int, 3>, 16> possibleMillPositions = {{{{0, 1, 2}},
                                                               {{0, 9, 21}},
                                                               {{1, 4, 7}},
                                                               {{2, 14, 23}},
                                                               {{3, 4, 5}},
                                                               {{3, 10, 18}},
                                                               {{5, 13, 20}},
                                                               {{6, 7, 8}},
                                                               {{6, 11, 15}},
                                                               {{8, 12, 17}},
                                                               {{9, 10, 11}},
                                                               {{12, 13, 14}},
                                                               {{15, 16, 17}},
                                                               {{16, 19, 22}},
                                                               {{18, 19, 20}},
                                                               {{21, 22, 23}}}};

  [[nodiscard]] bool isInBounds(int position) const;

public:
  std::string getNodeCharAtPosition(int position);

  void setNodeAtPosition(int position);

  void draw();

  bool placePiece(int position);

  bool removePiece(int position, player *player);

  bool isMill(int position);

  void clearBrokenMills(int position, int playerId);

  bool isConnected(int position1, int position2);

  bool movePiece(int startPosition, int targetPosition);

  bool movePieceFreely(int startPosition, int targetPosition, player *player);
};

#endif // NINEMANSMORRIS_BOARD_H

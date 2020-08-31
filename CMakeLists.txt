cmake_minimum_required(VERSION 3.16)
project(NineMansMorris)

set(CMAKE_CXX_STANDARD 20)

add_executable(NineMansMorris main.cpp board.cpp board.h player.cpp player.h game.cpp game.h Strategies/turnStrategy.h Strategies/initialTurnStrategy.cpp Strategies/initialTurnStrategy.h Strategies/movingTurnStrategy.cpp Strategies/movingTurnStrategy.h Strategies/jumpingTurnStrategy.cpp Strategies/jumpingTurnStrategy.h)
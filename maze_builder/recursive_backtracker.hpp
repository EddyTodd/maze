#pragma once

#include "maze_builder.hpp"
#include <iostream>

namespace maze {

class RecursiveBacktracker : public MazeBuilder {
public:
  RecursiveBacktracker(){};
  RecursiveBacktracker(RecursiveBacktracker &other) {}
  RecursiveBacktracker(RecursiveBacktracker &&other) noexcept {}
  ~RecursiveBacktracker() {}

private:
  virtual Grid &build(unsigned int width, unsigned int height);
  void explore(unsigned int x, unsigned int y);
  static void shuffleDirections(Direction *directions);
};

} // namespace maze

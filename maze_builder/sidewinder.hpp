#pragma once

#include "maze_builder.hpp"
#include <iostream>

namespace maze {

class Sidewinder : public MazeBuilder {
public:
  Sidewinder() {};
  Sidewinder(Sidewinder &other) {}
  Sidewinder(Sidewinder &&other) noexcept {}
  ~Sidewinder() {}

private:
  virtual Grid &build(unsigned int width, unsigned int height);
};

} // namespace maze

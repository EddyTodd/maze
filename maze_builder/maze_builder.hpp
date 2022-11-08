#pragma once

#include "../grid.hpp"
#include <iostream>

namespace maze {

class MazeBuilder {
public:
  MazeBuilder() {}
  MazeBuilder(MazeBuilder &other) {}
  MazeBuilder(MazeBuilder &&other) noexcept {}
  virtual ~MazeBuilder() {}

  virtual Grid &build(unsigned int width, unsigned int height) = 0;

protected:
  Grid *m_grid;
};

} // namespace maze

#include "random_fusion.hpp"
#include "recursive_backtracker.hpp"
#include "recursive_division.hpp"
#include "sidewinder.hpp"
#include "wilson.hpp"
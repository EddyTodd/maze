#pragma once

#include "maze_builder.hpp"
#include <iostream>

namespace maze {

class RecursiveDivision : public MazeBuilder {
public:
  RecursiveDivision() {
    std::cout << "[RecursiveDivision] created" << std::endl;
  };
  RecursiveDivision(RecursiveDivision &other) {
    std::cout << "[RecursiveDivision] copied" << std::endl;
  }
  RecursiveDivision(RecursiveDivision &&other) noexcept {
    std::cout << "[RecursiveDivision] moved" << std::endl;
  }
  ~RecursiveDivision() {
    std::cout << "[RecursiveDivision] deleted" << std::endl;
  }

private:
  virtual Grid &build(unsigned int width, unsigned int height);
  void divide(unsigned int x0, unsigned int y0, unsigned int x1,
              unsigned int y1);
};

} // namespace maze

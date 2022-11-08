#pragma once

#include "grid.hpp"
#include "maze_builder/maze_builder.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

namespace maze {

class Maze {
public:
  Maze(unsigned int width, unsigned int height,
       std::unique_ptr<MazeBuilder> mazeBuilder)
      : WIDTH(width), HEIGHT(height),
        grid(std::move(mazeBuilder->build(width, height))) {}

  Maze(Maze &other) {}

  Maze(Maze &&other) noexcept {
    grid.grid = std::move(other.grid.grid);
    WIDTH = other.HEIGHT;
    HEIGHT = other.HEIGHT;
    other.grid.grid = nullptr;
  }

  ~Maze() {}

  Grid grid;

  unsigned int WIDTH, HEIGHT;

  void generateImage(const std::string &imageName);
};

} // namespace maze

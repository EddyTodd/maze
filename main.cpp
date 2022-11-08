#include "maze.hpp"
#include <iostream>
#include <memory>

int main() {
  maze::Maze maze(200, 200, std::make_unique<maze::Wilson>());
  maze.generateImage("wilson");
  return 0;
}

#pragma once

#include <iostream>

namespace maze {

enum Direction : unsigned char {
  UP = 0b1000,
  DOWN = 0b0100,
  LEFT = 0b0010,
  RIGHT = 0b0001
};

class Grid {
public:
  unsigned int WIDTH, HEIGHT;
  unsigned char *grid;

  Grid() = default;

  Grid(unsigned int width, unsigned int height)
      : WIDTH(width), HEIGHT(height),
        grid(new unsigned char[width * height]{0}) {}

  Grid &operator=(const Grid &t) { return *this; }

  Grid(Grid &other) {
    WIDTH = other.WIDTH;
    HEIGHT = other.HEIGHT;
    grid = new unsigned char[WIDTH * HEIGHT];
    memcpy(grid, other.grid, WIDTH * HEIGHT);
  }

  Grid(Grid &&other) noexcept {
    if (&other == this)
      return;

    grid = std::move(other.grid);
    WIDTH = other.HEIGHT;
    HEIGHT = other.HEIGHT;
    other.grid = nullptr;
    delete &other;
  }

  Grid &operator=(Grid &&other) noexcept {
    if (&other == this)
      return *this;

    grid = std::move(other.grid);
    WIDTH = other.HEIGHT;
    HEIGHT = other.HEIGHT;
    other.grid = nullptr;

    return *this;
  }

  ~Grid() { delete grid; }

  unsigned char *operator[](unsigned int x) const {
    return (x < WIDTH) ? &(grid[x * HEIGHT]) : nullptr;
  }

  void connect(unsigned int x, unsigned int y, const Direction dir);
  bool canConnect(unsigned int x, unsigned int y, const Direction dir) const;
};

} // namespace maze

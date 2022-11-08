#pragma once

#include "maze_builder.hpp"
#include <iostream>
#include <stack>
#include <unordered_set>

namespace maze {

class Wilson : public MazeBuilder {
public:
  Wilson(){};
  Wilson(Wilson &other) {}
  Wilson(Wilson &&other) noexcept {}
  ~Wilson() {}

private:
  struct Cell {
  public:
    unsigned int x;
    unsigned int y;
    Cell(unsigned int a, unsigned int b) : x(a), y(b) {}

    Cell &operator=(Cell &&other) noexcept {
      if (&other == this)
        return *this;
      this->x = other.x;
      this->y = other.y;
      return *this;
    }

    Cell(const Cell &other) {
      x = other.x;
      y = other.y;
    }

    ~Cell() {}

    bool operator==(const Cell &other) const {
      return x == other.x && y == other.y;
    }
  };

  struct CellHasher {
    size_t operator()(const Cell &x) const {
      return x.x << sizeof(unsigned int) | x.y;
    }
  };

  virtual Grid &build(unsigned int width, unsigned int height);
  bool loop(unsigned int x, unsigned int y);

  std::unordered_set<Cell, CellHasher> m_set;
  std::unordered_set<Cell, CellHasher> m_pathSet;
  Cell m_cut = Cell(0, 0);
};

} // namespace maze

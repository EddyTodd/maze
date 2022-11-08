#include "recursive_division.hpp"

namespace maze {

Grid &RecursiveDivision::build(unsigned int width, unsigned int height) {
  m_grid = new Grid(width, height);
  divide(0, 0, width - 1, height - 1);
  return *m_grid;
}

void RecursiveDivision::divide(unsigned int x0, unsigned int y0,
                               unsigned int x1, unsigned int y1) {
  if (x0 == x1) {
    while (y0 < y1)
      m_grid->connect(x0, y0++, DOWN);
    return;
  } else if (y0 == y1) {
    while (x0 < x1)
      m_grid->connect(x0++, y0, RIGHT);
    return;
  }
  bool isVertical = x1 - x0 < y1 - y0   ? true
                    : x1 - x0 > y1 - y0 ? false
                                        : rand() & 1;

  if (isVertical)
    y1--;
  else
    x1--;

  unsigned int x = x0 + rand() % (x1 - x0 + 1);
  unsigned int y = y0 + rand() % (y1 - y0 + 1);
  if (isVertical) {
    m_grid->connect(x, y, DOWN);
    divide(x0, y0, x1, y);
    divide(x0, y + 1, x1, y1 + 1);
  } else {
    m_grid->connect(x, y, RIGHT);
    divide(x0, y0, x, y1);
    divide(x + 1, y0, x1 + 1, y1);
  }
}

} // namespace maze

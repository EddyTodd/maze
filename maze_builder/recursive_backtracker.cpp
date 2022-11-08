#include "recursive_backtracker.hpp"

namespace maze {

Grid &RecursiveBacktracker::build(unsigned int width, unsigned int height) {
  m_grid = new Grid(width, height);
  explore(rand() % width, rand() % height);
  return *m_grid;
}

void RecursiveBacktracker::explore(unsigned int x, unsigned int y) {
  Direction directions[4] = {UP, DOWN, LEFT, RIGHT};
  shuffleDirections(directions);
  for (Direction dir : directions) {
    if (!m_grid->canConnect(x, y, dir))
      continue;

    unsigned int x1 = x;
    unsigned int y1 = y;

    switch (dir) {
    case UP:
      y1--;
      break;
    case DOWN:
      y1++;
      break;
    case LEFT:
      x1--;
      break;
    case RIGHT:
      x1++;
      break;
    default:;
    }

    if (!(*m_grid)[x1][y1]) {
      m_grid->connect(x, y, dir);
      explore(x1, y1);
    }
  }
}

void RecursiveBacktracker::shuffleDirections(Direction *directions) {
  Direction tmp;
  unsigned char rndChar;
  for (unsigned int i = 3; i > 0; --i) {
    rndChar = rand() % (i + 1);
    tmp = directions[i];
    directions[i] = directions[rndChar];
    directions[rndChar] = tmp;
  }
}

} // namespace maze

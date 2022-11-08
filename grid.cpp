#include "grid.hpp"

namespace maze {

void Grid::connect(unsigned int x, unsigned int y, const Direction dir) {
  grid[x * HEIGHT + y] |= dir;

  switch (dir) {
  case UP:
    grid[x * HEIGHT + y - 1] |= DOWN;
    break;
  case DOWN:
    grid[x * HEIGHT + y + 1] |= UP;
    break;
  case LEFT:
    grid[(x - 1) * HEIGHT + y] |= RIGHT;
    break;
  case RIGHT:
    grid[(x + 1) * HEIGHT + y] |= LEFT;
    break;
  default:
    break;
  }
}

bool Grid::canConnect(unsigned int x, unsigned int y, Direction dir) const {
  switch (dir) {
  case UP:
    return x >= 0 && x < WIDTH && y > 0 && y < HEIGHT;
  case DOWN:
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT - 1;
  case RIGHT:
    return x >= 0 && x < WIDTH - 1 && y >= 0 && y < HEIGHT;
  case LEFT:
    return x > 0 && x < WIDTH && y >= 0 && y < HEIGHT;
  default:
    return false;
  }
}

} // namespace maze

#include "sidewinder.hpp"

namespace maze {

Grid &Sidewinder::build(unsigned int width, unsigned int height) {
  m_grid = new Grid(width, height);
  for (unsigned int i = 0; i < width - 1; i++)
    m_grid->connect(i, 0, RIGHT);
  for (unsigned int y = 1; y < height; y++) {
    unsigned int s = 0;
    for (int x = 0; x < width - 1; x++) {
      if (rand() & 1) {
        m_grid->connect(rand() % (x - s + 1) + s, y, UP);
        s = x + 1;
      } else {
        m_grid->connect(x, y, RIGHT);
      }
    }
    m_grid->connect(rand() % (width - s) + s, y, UP);
  }
  return *m_grid;
}

} // namespace maze

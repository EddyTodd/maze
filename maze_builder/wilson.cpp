#include "wilson.hpp"

namespace maze {

Grid &Wilson::build(unsigned int width, unsigned int height) {
  m_grid = new Grid(width, height);
  m_set.insert(std::move(Cell(0, 0)));
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (m_set.find(std::move(Cell(x, y))) != m_set.end())
        continue;
      loop(x, y);
    }
  }
  return *m_grid;
}

bool Wilson::loop(unsigned int x, unsigned int y) {
  Cell c(x, y);
  if (m_set.find(c) != m_set.end()) {
    return true;
  } else if (m_pathSet.find(c) != m_pathSet.end()) {
    m_cut = std::move(c);
    return false;
  }
  Direction d;
  while (true) {
    d = (Direction)(1 << rand() % 4);
    if (m_grid->canConnect(x, y, d))
      break;
  }
  unsigned int x1 = x;
  unsigned int y1 = y;
  switch (d) {
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
  default:
    break;
  }
  m_pathSet.insert(c);
  if (loop(x1, y1)) {
    m_grid->connect(x, y, d);
    m_set.insert(c);
    m_pathSet.erase(c);
    return true;
  } else {
    m_pathSet.erase(c);
    if (m_cut == c)
      return loop(x, y);
    return false;
  }
}

} // namespace maze

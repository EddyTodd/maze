#include "random_fusion.hpp"

namespace maze {

Grid& RandomFusion::build(unsigned int width, unsigned int height) {
  m_grid = new Grid(width, height);
  m_dsf = new unsigned int[width * height];
  for (int i = 0; i < width * height; ++i)
    m_dsf[i] = i;

  unsigned int hLength = (width - 1) * height, vLength = width * (height - 1);
  m_horizontalEdges = createAndShuffle(hLength);
  m_verticalEdges = createAndShuffle(vLength);

  int vCount = 0, hCount = 0;
  while (hCount < hLength && vCount < vLength) {
    if (rand() & 1)
      findDown(vCount++);
    else
      findRight(hCount++);
    if (vCount == vLength)
      while (hCount < hLength)
        findRight(hCount++);
    else if (hCount == hLength)
      while (vCount < vLength)
        findDown(vCount++);
  }
  return *m_grid;
}

unsigned int *RandomFusion::createAndShuffle(unsigned int len) {
  auto *arr = new unsigned int[len];
  for (int i = 0; i < len; i++)
    arr[i] = i;

  unsigned int tmp;
  unsigned int rndInt;
  for (unsigned int i = len; i > 1; --i) {
    rndInt = rand() % i;
    tmp = arr[i - 1];
    arr[i - 1] = arr[rndInt];
    arr[rndInt] = tmp;
  }
  return arr;
}

void RandomFusion::findDown(unsigned int vCount) {
  unsigned int x = m_verticalEdges[vCount] % m_grid->WIDTH;
  unsigned int y = m_verticalEdges[vCount] / m_grid->WIDTH;
  if (find(x, y) != find(x, y + 1)) {
    m_grid->connect(x, y, DOWN);
    join(x, y, x, y + 1);
  }
}

void RandomFusion::findRight(unsigned int hCount) {
  unsigned int x = m_horizontalEdges[hCount] % (m_grid->WIDTH - 1);
  unsigned int y = m_horizontalEdges[hCount] / (m_grid->WIDTH - 1);
  if (find(x, y) != find(x + 1, y)) {
    m_grid->connect(x, y, RIGHT);
    join(x, y, x + 1, y);
  }
}

unsigned int RandomFusion::find(unsigned int n) {
  return m_dsf[n] == n ? n : (m_dsf[n] = find(m_dsf[n]));
}

unsigned int RandomFusion::find(unsigned int x, unsigned int y) {
  return find(y * m_grid->WIDTH + x);
}

void RandomFusion::join(unsigned int x0, unsigned int y0, unsigned int x1,
                        unsigned int y1) {
  m_dsf[find(x0, y0)] = find(x1, y1);
}

} // namespace maze

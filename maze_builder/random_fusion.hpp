#pragma once

#include "maze_builder.hpp"
#include <iostream>

namespace maze {

class RandomFusion : public MazeBuilder {
public:
  RandomFusion(){};
  RandomFusion(RandomFusion &other) {}
  RandomFusion(RandomFusion &&other) noexcept {}
  ~RandomFusion() {
    delete m_dsf;
    delete m_horizontalEdges;
    delete m_verticalEdges;
  }

private:
  unsigned int *m_dsf;
  unsigned int *m_horizontalEdges;
  unsigned int *m_verticalEdges;

  virtual Grid &build(unsigned int width, unsigned int height);
  static unsigned int *createAndShuffle(unsigned int len);
  void findDown(unsigned int vCount);
  void findRight(unsigned int hCount);
  unsigned int find(unsigned int n);
  unsigned int find(unsigned int x, unsigned int y);
  void join(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1);
};

} // namespace maze

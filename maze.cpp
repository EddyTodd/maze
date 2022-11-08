#include "maze.hpp"
#include <fstream>

namespace maze {

void Maze::generateImage(const std::string &imageName) {
  unsigned int w = WIDTH << 1 | 1;
  unsigned int h = HEIGHT << 1 | 1;

  std::ofstream img(imageName + ".pbm");
  img << "P1\n" << w << " " << h << "\n";

  const char *BLACK = "1 ";
  const char *WHITE = "0 ";

  for (unsigned int x = 0; x < w; x++)
    img << BLACK;
  img << "\n";
  for (unsigned int y = 0; y < HEIGHT; y++) {
    img << BLACK;
    for (unsigned int x = 0; x < WIDTH; x++) {
      img << WHITE;
      grid[x][y] & RIGHT ? img << WHITE : img << BLACK;
    }
    img << "\n";
    img << BLACK;
    for (unsigned int x = 0; x < WIDTH; x++) {
      grid[x][y] & DOWN ? img << WHITE : img << BLACK;
      img << BLACK;
    }
    img << "\n";
  }
  for (unsigned int x = 0; x < w; x++)
    img << BLACK;
  img << "\n";

  img.flush();
  img.close();
}

} // namespace maze
#include <iostream>
#include <vector>

const int WIDTH = 10;
const int HEIGHT = 10;

int main() {
  std::vector<std::vector<int>> terrain(HEIGHT, std::vector<int>(WIDTH, 0));

  for (int y = 0; y < HEIGHT; ++y) {
    for (int x = 0; x < WIDTH; ++x) {
      terrain[y][x] = 1;
      std::cout << terrain[y][x] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

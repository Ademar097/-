#include <iostream>
#include <vector>

const int WIDTH = 10;
const int HEIGHT = 10;
const int DEPTH = 10;

int main() {
  std::vector<std::vector<std::vector<int>>> terrain(HEIGHT, std::vector<std::vector<int>>(WIDTH, std::vector<int>(DEPTH, 0)));
  
  for (int y = 0; y < HEIGHT; ++y) {
    for (int z = 0; z < DEPTH; ++z) {
      for (int x = 0; x < WIDTH; ++x) {
        terrain[y][x][z] = 1;
        std::cout << terrain[y][x][z] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  
  return 0;
}

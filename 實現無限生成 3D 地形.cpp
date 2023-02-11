#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::vector<std::vector<int>>> generate_terrain() {
    std::vector<std::vector<std::vector<int>>> terrain;
    for (int x = 0; x < 10; ++x) {
        std::vector<std::vector<int>> column;
        for (int y = 0; y < 10; ++y) {
            std::vector<int> layer;
            for (int z = 0; z < 10; ++z) {
                layer.push_back(rand() % 2);
            }
            column.push_back(layer);
        }
        terrain.push_back(column);
    }
    return terrain;
}

void print_terrain(const std::vector<std::vector<std::vector<int>>>& terrain) {
    for (int x = 0; x < terrain.size(); ++x) {
        for (int y = 0; y < terrain[0].size(); ++y) {
            for (int z = 0; z < terrain[0][0].size(); ++z) {
                std::cout << terrain[x][y][z] << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(NULL));
    std::vector<std::vector<std::vector<int>>> terrain = generate_terrain();
    print_terrain(terrain);
    return 0;
}

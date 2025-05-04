
#include <iostream>
#include <algorithm>
#include <vector>

enum class Direction {
    DOWN,
    RIGHT
};

using List = std::vector<int>;
using Matrix = std::vector<std::vector<int>>;
using Directions = std::vector<Direction>;
using Path = std::vector<std::vector<Direction>>;

class Grid {
    Matrix m;

    public:
    Grid() {
        int rows, cols;
        std::cin >> rows >> cols;
        m.resize(rows, std::vector<int>(cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> m[i][j];
            }
        } 
    }

    Grid(char h) {
        m = {
            {5, 1, 1},
            {2, 4, 7},
            {2, 4, 5},
            {5, 6, 3}
        };
    }

    Matrix getMatrix();
    int getRows();
    int getCols();
    Directions findMinimumCostPath(Matrix);
};

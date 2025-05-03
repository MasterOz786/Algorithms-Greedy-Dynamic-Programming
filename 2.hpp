
#include <iostream>
#include <vector>

enum class Direction {
    DOWN,
    RIGHT
};

class _Grid {
    int **arr = nullptr;
    int rows = 0, cols = 0;

    public:
    _Grid() {
        std::cout << "Rows? ";
        std::cin >> rows;
        std::cout << "Cols? ";
        std::cin >> cols;
        
        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }

    std::vector<Direction> findMinimumCostPath(std::vector<std::vector<int>> grid);
};

using Grid = std::vector<std::vector<int>>;
using Directions = std::vector<Direction>;

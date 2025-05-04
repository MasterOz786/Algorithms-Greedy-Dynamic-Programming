
#include "2.hpp"

Matrix Grid::getMatrix() {
    return this->m;
}

Directions Grid::findMinimumCostPath(Matrix m) {
    int rows = m.size();
    int cols = m[0].size();

    Matrix dp(rows, List(cols));
    Path from(rows, Directions(cols));
    
    dp[0][0] = m[0][0];
    // first set the first row
    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j-1] + m[0][j];
        from[0][j] = Direction::RIGHT;
    }
    // then the first column
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + m[i][0];
        from[i][0] = Direction::DOWN;
    }

    // rest of the dp table
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + m[i][j];
                from[i][j] = Direction::DOWN;
            } else {
                dp[i][j] = dp[i][j - 1] + m[i][j];
                from[i][j] = Direction::RIGHT; 
            }
        }
    }
    
    // reconstruct the path
    Directions directions;
    int i = rows - 1, j = cols - 1;
    while (i > 0 || j > 0) {
        Direction d = from[i][j];
        directions.push_back(d);
        
        // if direction is down then go up else move left
        d == Direction::DOWN? i-- : j--;
    }

    // reverse to get the actual path
    std::reverse(directions.begin(), directions.end());
    return directions;
}

int main() {
    Grid g;
    Directions path = g.findMinimumCostPath(g.getMatrix());

    for (Direction d : path) {
        std::cout << (d == Direction::DOWN ? "DOWN" : "RIGHT") << " ";
    }

    return 0;
}

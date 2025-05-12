# 🧩 Pathfinding & Interval Coverage Algorithms

This repository contains two C++ console-based mini-projects:

1. **Minimum Cost Grid Path Finder** – Finds the optimal path from top-left to bottom-right of a grid using Dynamic Programming.
2. **Red Interval Coverage of Blue Intervals** – Determines the minimal number of red intervals needed to fully cover a set of blue intervals.

---

## �� Project 1: Minimum Cost Grid Path Finder

### 📌 Overview

Finds the **minimum-cost path** from the top-left to bottom-right in a 2D grid, using only `DOWN` and `RIGHT` moves. The solution uses **Dynamic Programming (DP)** to calculate cumulative costs efficiently.

### 💡 Example Input

```
4 3
5 1 1
2 4 7
2 4 5
5 6 3
```

### 🚀 Sample Output

```
DOWN DOWN RIGHT RIGHT DOWN
```

### 🛠️ How It Works

- **Input**: Grid dimensions + elements
- **DP Table**: Computes minimum costs for each cell
- **Path Tracking**: Tracks the direction to reach each cell
- **Backtracking**: Reconstructs the path from destination to source
- **Output**: List of directions taken

### 🧠 Concepts

- 2D Dynamic Programming
- Backtracking for path reconstruction
- Vectors, enums, and STL utilities

---

## 📘 Project 2: Minimum Red Interval Coverage

### 📌 Overview

Given two sets of time intervals (red and blue), this program determines the **minimum number of red intervals** required to completely cover each blue interval.

### 💡 Example Intervals

```cpp
red =  { {0, 4}, {2, 5}, {4, 8}, {9, 10}, {10, 12}, {11, 12} };
blue = { {0, 2}, {5, 5}, {7, 10}, {11, 13} };
```

### 🚀 Sample Output

```
[Sorted Red Timeline]
{0 4} {2 5} {4 8} {9 10} {10 12} {11 12}
[Sorted Blue Timeline]
{0 2} {5 5} {7 10} {11 13}
3
{2 5}
{4 8}
{11 12}
```

### 📊 Visualization

The project now includes a Python script (`test_intervals.py`) that generates visual representations of the interval coverage problem. The script:

- Creates PDF visualizations of intervals
- Highlights selected red intervals that cover blue intervals
- Includes test cases for verification
- Uses matplotlib for clear, professional graphs

### 🛠️ How It Works

- **Sorting**: Red and blue intervals are sorted based on start times
- **Greedy Strategy**: For each blue interval, the best red interval that can fully cover it is selected
- **Result**: Number of red intervals selected and which ones
- **Visualization**: Generates PDF graphs showing the coverage

### 📚 Concepts

- Greedy Algorithms
- Interval Sorting & Selection
- STL vectors and custom comparator logic
- Data visualization with Python

---

## 📂 File Structure

```
├── main.cpp           // Entry point for both projects
├── 2.hpp             // Grid class header (Project 1)
├── 2.cpp             // Grid logic implementation (Project 1)
├── 1.hpp             // Interval class definition (Project 2)
├── 1.cpp             // Interval coverage implementation (Project 2)
├── test_intervals.py // Visualization and testing script
```

---

## 🔧 Build & Run

To compile and run the C++ projects:
```bash
g++ main.cpp 2.cpp -o pathfinder
./pathfinder
```

To generate interval visualizations:
```bash
python3 test_intervals.py
```

> The visualization script requires matplotlib and numpy.

---

## ✅ Requirements

- C++11 or higher
- GCC/G++ Compiler
- Python 3.x with matplotlib and numpy (for visualizations)

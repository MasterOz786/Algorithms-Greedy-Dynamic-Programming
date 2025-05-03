
#include <iostream>
#include <vector>

class Interval {
    public:
        int x;
        int y;
};

std::ostream& operator<<(std::ostream& out, const Interval& interval) {
    out << '(' << interval.x << ' ' << interval.y << ')';
    return out;
}

int minimumRedIntervalsToCoverBlue(std::vector<Interval> red, std::vector<Interval> blue) {
    return 1;
}

void printTimeline(std::vector<Interval> timeline) {
    for (auto interval: timeline) {
        std::cout << interval << ' ';
    }
    std::cout << '\n';    
}

void checkOverlapInTimelines(std::vector<Interval> red, std::vector<Interval> blue) {
    printTimeline(red);
    printTimeline(blue);    
    return;
}

int main() {
    std::vector<Interval> red = { {0, 4}, {2, 5}, {4, 8}, {9, 10}, {10, 12}, {11, 12} };
    std::vector<Interval> blue = { {0, 2}, {5, 5}, {7, 10}, {11, 13} };    

    checkOverlapInTimelines(red, blue);

    return 0;
}


#include "1.hpp"
#include <algorithm>

_Timeline sortTimeline(const _Timeline& timeline) {
    _Timeline newTimeline = timeline;
    std::sort(newTimeline.begin(), newTimeline.end());
    return newTimeline;
}

std::pair<int, _Timeline> minimumRedIntervalsToCoverBlue(const _Timeline& _red, const _Timeline& _blue) {
    _Timeline red = _red;
    _Timeline blue = _blue;
    int i = 0;
    int count = 0;
    int n = red.size();
    
    _Timeline resultant;
    for (const auto& b: blue) {
        int start_b = b.x, end_b = b.y;
        int best_end = -1;
        
        while (i < n && red[i].x <= start_b) {
            if (red[i].y >= end_b) {
                best_end = std::max(best_end, red[i].y);
            }
            ++i;
        }
        
        if (best_end < end_b) {
            continue;
        }
        resultant.push_back(red[i]);
        count++;
    }
    
    return std::make_pair(count, resultant);
}

void printTimeline(const _Timeline& timeline) {
    for (auto interval: timeline) {
        std::cout << interval << ' ';
    }
    std::cout << '\n';
}

void checkOverlapInTimelines(const _Timeline& red, const _Timeline& blue) {
    printTimeline(sortTimeline(red));
    printTimeline(sortTimeline(blue));

    std::pair<int, _Timeline> res = minimumRedIntervalsToCoverBlue(sortTimeline(red), sortTimeline(blue));
    std::cout << res.first << '\n';
    for (auto intv: res.second) {
        std::cout << intv << '\n';
    }
    return;
}

int main() {
    std::vector<Interval> red = { {0, 4}, {2, 5}, {4, 8}, {9, 10}, {10, 12}, {11, 12} };
    std::vector<Interval> blue = { {0, 2}, {5, 5}, {7, 10}, {11, 13} };
    // _Timeline red = { {0, 4}, {2, 5}, {1, 8}, {4, 10}, {3, 12}, {6, 12} };
    // _Timeline blue = { {0, 2}, {5, 5}, {7, 10}, {11, 13} };    

    checkOverlapInTimelines(red, blue);

    return 0;
}

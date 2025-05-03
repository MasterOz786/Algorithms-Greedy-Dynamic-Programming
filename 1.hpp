#pragma once

#include <iostream>
#include <vector>

struct Interval {
    int x;
    int y;

    bool operator<(const Interval& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }

    friend std::ostream& operator<<(std::ostream& out, const Interval& interval) {
        out << '(' << interval.x << ' ' << interval.y << ')';
        return out;
    }
    
};

using _Interval = const Interval&;
using _Timeline = std::vector<Interval>;
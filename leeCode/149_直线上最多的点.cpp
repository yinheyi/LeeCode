#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct slope {
    int x;
    int y;
};

bool operator<(const slope& lhs, const slope& rhs) {
    return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y);
}

static int gcd(int dividend, int divisor) {
    if (divisor == 0) {
        cerr << "在请最大公约数的函数内, 输入错误,除数为0. " << endl;
        return -1;
    }

    const int remainder = dividend % divisor;
    if (remainder == 0) {
        return divisor > 0 ? divisor : divisor;
    }
    return gcd(divisor, remainder);
}

slope GetSlope(const vector<int>& point1, const vector<int>& point2) {
    slope result = { point1[0] - point2[0], point1[1] - point2[1] };
    if (result.y == 0) {
        result.x = 1;
    } else {
        int greatstCommonDivisor = gcd(result.x, result.y);
        result.x /= greatstCommonDivisor;
        result.y /= greatstCommonDivisor;
    }
    return result;
}

bool IsSamePoint(const vector<int>& point1, const vector<int>& point2) {
    return point1[0] == point2[0] && point1[1] == point2[1];
}

int GetMaxPoint(int repeatNum, const map<slope, int>& map) {
    if (map.size() == 0) {
        return repeatNum + 1;
    }

    int maxNum = 0;
    for (auto& item : map) {
        maxNum = max(maxNum, item.second);
    }
    return maxNum + repeatNum;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 2) {
            return points.size();
        }

        for (size_t i = 0; i < points.size() - 1; ++i) {
            int repeatNum = 0;
            map<slope, int> slp2Point2Num;
            for (size_t j = i + 1; j < points.size(); ++j) {
                if (IsSamePoint(points[i], points[j])) {
                    ++repeatNum;
                    continue;
                }

                slope curSlope = GetSlope(points[i], points[j]);
                if (slp2Point2Num.count(curSlope) == 0) {
                    slp2Point2Num[curSlope] = 2;
                } else {
                    ++slp2Point2Num[curSlope];
                }
            }
            maxPointNums = max(maxPointNums, GetMaxPoint(repeatNum, slp2Point2Num));
        }
        return maxPointNums;
    }

private:
    int maxPointNums = 0;
};

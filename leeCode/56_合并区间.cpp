#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
                [](const vector<int>& first, const vector<int>& second)
                {return first.front() < second.front();});

        vector<vector<int>> outputs;
        if (intervals.empty()) {
            return outputs;
        }

        outputs.push_back(intervals.front());
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (CanMerge(outputs.back(), intervals[i])) {
                outputs.back().back() = intervals[i].back();
            } else {
                outputs.push_back(intervals[i]);
            }
        }
        return outputs;
    }
private:
    bool CanMerge(const vector<int>& first, const vector<int>& second) {
        return second.front() >= first.front() && second.front() <= first.back();
    }
};

int main()
{
    return 0;
}

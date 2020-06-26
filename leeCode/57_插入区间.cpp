class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        size_t inserPosition = intervals.size();
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (newInterval.front() < intervals[i].front()) {
                inserPosition = i;
                break;
            }
        }
        intervals.insert(intervals.begin() + inserPosition, newInterval);
        return merge(intervals);
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> outputs;
        if (intervals.empty()) {
            return outputs;
        }

        outputs.push_back(intervals.front());
        for (size_t i = 0; i < intervals.size(); ++i) {
            if (CanMerge(outputs.back(), intervals[i])) {
                outputs.back().back() = max(outputs.back().back(), intervals[i].back());
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

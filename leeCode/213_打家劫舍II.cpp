#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }

        int first = robHelper(vector<int>(nums.begin(), nums.end() - 1));
        int second = robHelper(vector<int>(nums.begin() + 1, nums.end()));
        return first > second ? first : second;
    }

private:
    int robHelper(const vector<int>& nums) {
        int stole = 0;
        int notStole = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int newStole = notStole + nums[i];
            notStole = stole > notStole ? stole : notStole;
            stole = newStole;
        }
        return stole > notStole ? stole : notStole;
    }
};

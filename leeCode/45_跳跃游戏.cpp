class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        const int length = nums.size();
        int curPosition = 0;
        int count = 0;
        while (true) {
            if (curPosition + nums[curPosition] >= length - 1) {
                ++count;
                break;
            }

            int optimalStep = 0;
            int maxDistance = 0;
            for (int i = 1; i <= nums[curPosition]; ++i) {
                if (i + nums[curPosition + i] > maxDistance) {
                    optimalStep = i;
                    maxDistance = i + nums[curPosition + i];
                }
            }
            curPosition += optimalStep;
            ++count;
        }
        return count;
    }
};

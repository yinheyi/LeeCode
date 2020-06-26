class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums.front();
        int currentSum = maxSum;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (currentSum < 0) {
                currentSum = nums[i];
            } else {
                currentSum += nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

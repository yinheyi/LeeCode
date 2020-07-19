class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> outputs;
        vector<int> curSet;
        DFS(0, nums.size(), nums, curSet, outputs);
        return outputs;
    }

    void DFS(size_t start ,size_t end, const vector<int>& nums,
             vector<int>& curSet, vector<vector<int>>& outputs)
    {
        outputs.push_back(curSet);
        for (size_t i = start; i < end; ++i) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            curSet.push_back(nums[i]);
            DFS(i + 1, end, nums, curSet, outputs);
            curSet.pop_back();
        }
    }
};

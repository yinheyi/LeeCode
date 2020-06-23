class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        searchFlag.resize(nums.size(), false);
        DFS(nums);
        return outputs;
    }

private:
    void DFS(const vector<int>& nums)
    {
        bool allsearched = true;
        for (size_t i = 0; i < searchFlag.size(); ++i) {
            if (!searchFlag[i]) {
                allsearched = false;
                current.push_back(nums[i]);
                searchFlag[i] = true;
                DFS(nums);
                current.pop_back();
                searchFlag[i] = false;
            }
        }
        if (allsearched) {
            outputs.push_back(current);
        }
    }

    vector<vector<int>> outputs;
    vector<int> current;
    vector<bool> searchFlag;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        const size_t middle = (nums.size() - 1) >> 1;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = sortedArrayToBST(vector<int>(nums.begin(), nums.begin() + middle));
        root->right = sortedArrayToBST(vector<int>(nums.begin() + middle + 1, nums.end()));
        return root;
    }
};

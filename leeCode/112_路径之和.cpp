class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr &&
            root->right == nullptr) {
            return root->val == sum;
        }

        return (root->left && hasPathSum(root->left, sum - root->val)) ||
               (root->right && hasPathSum(root->right, sum - root->val));
    }
};

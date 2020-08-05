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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;
        DFS(root, 0, sum);
        return sum;
    }

    void DFS(TreeNode* root, int curValue, int& sum)
    {
        curValue = curValue * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += curValue;
            return;
        }
        if (root->left != nullptr) {
            DFS(root->left, curValue, sum);
        }
        if (root->right != nullptr) {
            DFS(root->right, curValue, sum);
        }
    }
};

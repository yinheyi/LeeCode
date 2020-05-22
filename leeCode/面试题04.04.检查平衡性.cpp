#define MAX(x, y) ((x) > (y) ? (x) : (y))

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        int depth;
        return isBalanced(root, depth);
    }

private:
    bool isBalanced(TreeNode* root, int& depth)
    {
        if (root == NULL) {
            depth = 0;
            return true;
        }

        int leftDepth = 0;
        int rightDepth = 0;
        bool isBalance = isBalanced(root->left, leftDepth) && isBalanced(root->right, rightDepth);
        if (isBalance) {
            depth = MAX(leftDepth, rightDepth) + 1;
            return true;
        } else {
            return false;
        }
    }
};


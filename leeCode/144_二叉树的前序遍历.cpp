#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        while (root != nullptr) {
            result.push_back(root->val);
            stk.push(root);
            root = root->left;
        }

        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            top = top->right;
            while (top != nullptr) {
                result.push_back(top->val);
                stk.push(top);
                top = top->left;
            }
        }
        return result;
    }
};

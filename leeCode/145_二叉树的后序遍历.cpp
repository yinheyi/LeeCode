class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }

        TreeNode* lastVisited = nullptr;
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            if (top->right == nullptr || top->right == lastVisited) {
                result.push_back(top->val);
                lastVisited = top;
                stk.pop();
            } else {
                top = top->right;
                while (top != nullptr) {
                    stk.push(top);
                    top = top->left;
                }
            }
        }
        return result;
    }
};

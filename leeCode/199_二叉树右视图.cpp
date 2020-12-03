/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        first_.push(root);
        while (!first_.empty() || !second_.empty()) {
            if (!first_.empty()) {
                result.push_back(DoIt(first_, second_));
            } else {
                result.push_back(DoIt(second_, first_));
            }
        }

        return result;
    }

private:
    int DoIt(queue<TreeNode*>& notEmptyQueue, queue<TreeNode*>& emptyQueue) {
        int res = notEmptyQueue.front()->val;
        while (!notEmptyQueue.empty()) {
            TreeNode* front = notEmptyQueue.front();
            if (front->right != nullptr) {
                emptyQueue.push(front->right);
            }
            if (front->left != nullptr) {
                emptyQueue.push(front->left);
            }
            notEmptyQueue.pop();
        }
        return res;
    }

    queue<TreeNode*> first_;
    queue<TreeNode*> second_;
};

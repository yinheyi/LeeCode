#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if (S.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(S));
        string leftStr = GetLeftStr(S);
        Process(leftStr);
        string rightStr = GetRightStr(S);
        Process(rightStr);
        root->left = recoverFromPreorder(leftStr);
        root->right = recoverFromPreorder(rightStr);
        return root;
    }

private:
    void Process(string& str)
    {
        string output;
        bool control = true;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '-') {
                if (control) {
                    control = false;
                    continue;
                } else {
                    output.push_back('-');
                }
            } else {
                control = true;
                output.push_back(str[i]);
            }
        }
        str = output;
    }

    string GetLeftStr(const string& input)
    {
        size_t first = GetFirst_Index(input);
        if (first == -1) {
            return string("");
        }
        size_t second = GetSecond_Index(input);
        if (second == -1) {
            return input.substr(first);
        } else {
            return input.substr(first, second - first);
        }
    }

    string GetRightStr(const string& input)
    {
        size_t second = GetSecond_Index(input);
        if (second == -1) {
            return string("");
        } else {
            return input.substr(second);
        }
    }

    size_t GetFirst_Index(const string& input)
    {
        if (input.size() < 3) {
            return -1;
        }
        for (size_t i = 1; i < input.size(); ++i) {
            if (input[i] == '-') {
                return i;
            }
        }
        return -1;
    }

    size_t GetSecond_Index(const string& input)
    {
        size_t firstIndex = GetFirst_Index(input);
        if (firstIndex == -1) {
            return -1;
        }

        for (size_t i = firstIndex + 1; i < input.size() - 1;  ++i) {
            if (input[i] == '-' && input[i-1] != '-' && input[i+1] != '-') {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution solver;
    string str;
    while (cin >> str) {
        solver.recoverFromPreorder(str);
    }
    return 0;
}

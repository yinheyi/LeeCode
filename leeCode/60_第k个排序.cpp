#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n; ++i) {
            str.push_back('0' + i);
        }
        DFS(str, k);
        return result;
    }

    void DFS(string& input, int k)
    {
        if (count >= k) {
            return;
        }

        if (curStr.size() == input.size()) {
            ++count;
            result = curStr;
        }

        for (size_t i = 0; i < input.size(); ++i) {
            if (input[i] != '#') {
                curStr.push_back(input[i]);
                input[i] = '#';
                DFS(input, k);
                input[i] = curStr.back();
                curStr.pop_back();
            }
        }
    }

private:
    int count = 0;
    string result;
    string curStr;
};


int main()
{
    Solution solver;
    string result = solver.getPermutation(1, 23232434);
    cout << result << endl;
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int start = GetStartNum(k, n);
        vector<int> output;
        DFS(start, k, n, output);
        return results;
    }
private:
    int GetStartNum(int k, int n) {
        int start = 9 - k + 2;
        int end = 9;
        int sum = (start + end) * (k - 1) / 2;
        if (sum >= n) {
            return 1;
        } else {
            return n - sum;
        }
    }
    void DFS(int start, int k, int n, vector<int>& output) {
        if (k == 1) {
            if (n >= start && n < 10) {
                output.push_back(n);
                results.push_back(output);
                output.pop_back();
            }
            return;
        }

        for (int i = start; i <= n / k; ++i) {
            output.push_back(i);
            DFS(i + 1, k - 1, n - i, output);
            output.pop_back();
        }
    }
    vector<vector<int>> results;
};

int main()  {
    int k, n;
    vector<vector<int>> result;
    while (true) {
        cin >> k >> n;
        Solution solver;
        result = solver.combinationSum3(k, n);
        if (result.empty()) {
            cout << "empty" << endl;
            continue;
        }
        for (size_t i = 0; i < result.size(); ++i) {
            vector<int>& item = result[i];
            for (size_t j = 0; j < item.size(); ++j) {
                cout << item[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

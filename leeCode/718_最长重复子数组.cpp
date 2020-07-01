class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> bp(A.size() + 1, vector<int>(B.size() + 1, 0));
        int maxValue = 0;
        for (size_t i = 1; i <= A.size(); ++i) {
            for (size_t j = 1; j <= B.size(); ++j) {
                bp[i][j] = (A[i-1] == B[j-1]) ? bp[i-1][j-1] + 1 : 0;
                maxValue = max(maxValue, bp[i][j]);
            }
        }
        return maxValue;
    }
};

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            int temp = b;
            b = (b ^ nums[i]) & ~a;
            a = (a ^ nums[i]) & temp;
        }
        return b;
    }
};

int main()
{
    vector<int> inputs = {0, 1, 0, 1,0, 1, 99};
    Solution solver;
    int result = solver.singleNumber(inputs);
    cout << result << endl;
    return 0;
}

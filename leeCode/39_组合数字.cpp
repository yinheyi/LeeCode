#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int output = 0;
        int start = 0;
        int end = height.size() - 1;

        while (start < end) {
            if (height[start] <= height[end]) {
                if (height[start + 1] < height[start]) {
                    output += height[start] - height[start + 1];
                    height[start + 1] = height[start];
                    ++start;
                }
            } else {
                if (height[end - 1] < height[end]) {
                    output += height[end] - height[end - 1];
                    height[end - 1] = height[end];
                    --end;
                }
            }
        }

        return output;
    }
};

int main()
{
    return 0;
}

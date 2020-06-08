
int maxArea(const vector<int>& height)
{
    int max = 0;
    int left = 0;
    int right = static_cast<int>(height.size()) - 1;
    while (left < right) {
        max = Max(max, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return max;
}

int Max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

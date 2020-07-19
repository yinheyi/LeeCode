class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int resultIndex = m + n - 1;
        int nums1Index = m - 1;
        int nums2Index = n - 1;

        while (resultIndex >= 0) {
            const int num1 = nums1Index < 0 ? 0x80000000 : nums1[nums1Index];
            const int num2 = nums2Index < 0 ? 0x80000000 : nums2[nums2Index];
            if (num1 > num2) {
                nums1[resultIndex] = num1;
                --nums1Index;
            } else {
                nums1[resultIndex] = num2;
                --nums2Index;
            }
            --resultIndex;
        }
    }
};

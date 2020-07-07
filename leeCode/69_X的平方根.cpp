class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        int begin = 0;
        int end = x;

        while (begin < end - 1) {
            int middle = (begin + end) / 2;
            if (x / middle == middle) {
                return middle;
            }
            if (x / middle > middle) {
                begin =　middle;
            } else {
                end = middle;
            }
        }
        return begin;
    }
};

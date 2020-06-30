class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            vector<int> a(1, 0);
            return a;
        }

        digits.insert(digits.begin(), 0);
        digits.back() += 1;
        for (size_t i = digits.size(); i > 1;--i) {
            if (digits[i-1] == 10) {
                digits[i-1] = 0;
                digits[i-2] += 1;
            }
        }
        if (digits.front() == 0) {
            return vector<int>(digits.begin() + 1, digits.end());
        } else {
            return digits;
        }
    }
};

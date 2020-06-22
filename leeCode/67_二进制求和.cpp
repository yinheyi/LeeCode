class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0;
        size_t maxLength = max(a.size(), b.size());
        string result;
        for (size_t i = 0; i < maxLength; ++i) {
            int aValue = i < a.size() ? a[i] - '0' : 0;
            int bValue = i < b.size() ? b[i] - '0' : 0;
            int carry = (aValue + bValue) / 2;
            int newValue = (aValue + bValue) % 2;
            result.push_back(newValue + '0');
        }
        if (carry) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int pp = 1;
        int p = s[0] > '0' ? 1 : 0;
        for (size_t i = 1; i < s.size(); ++i) {
            int cur = s[i] > '0' ? p : 0;
            const int val = (s[i-1] - '0') * 10 + s[i] - '0';
            if (10 <= val && val  <= 26) {
                cur += pp;
            }
            if (cur == 0) {
                return 0;
            }
            pp = p;
            p = cur;
        }
        return p;
    }
};

#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return isIsomorphic1(s, t) && isIsomorphic1(t, s);
    }
    bool isIsomorphic1(string s, string t) {
        m.clear();
        for (size_t i = 0; i < s.size(); ++i) {
            if (m.count(s[i]) == 0) {
                m[s[i]] = t[i];
            } else {
                if (m[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    map<char, char> m;
};

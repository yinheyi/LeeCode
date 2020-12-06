#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        if (container.find(n) != container.end()) {
            return false;
        }
        container.insert(n);
        return isHappy(GetNext(n));
    }

private:
    int GetNext(int n) {
        int result = 0;
        while (n) {
            const int remainder = n % 10;
            result += remainder * remainder;
            n /= 10;
        }
        return result;
    }
    unordered_set<int> container;
};

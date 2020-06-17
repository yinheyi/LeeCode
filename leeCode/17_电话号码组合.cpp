#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        Traversal(digits);
        return outputs;
    }

protected:
    void Traversal(const string& digits)
    {
        if (digits.empty()) {
            if (!currentStr.empty()) {
            outputs.push_back(currentStr);
            }
            return;
        }

        const string& chars = digitToChars[digits[0] - '0'];
        for (size_t i = 0; i < chars.size(); ++i) {
            currentStr.push_back(chars[i]);
            Traversal(digits.substr(1));
            currentStr.pop_back();
        }
    }

private:
    vector<string> outputs;
    string currentStr;
    vector<string> digitToChars{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main()
{
    return 0;
}

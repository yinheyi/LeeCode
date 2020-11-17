#include <iostream>
#include <string>

using namespace std;

void ReverseString(const string& input, string& output) {
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != ' ' || (!output.empty() && output.back() != ' ')) {
            output.push_back(input[i]);
        }
    }

    if (!output.empty() && output.back() == ' ') {
        output.pop_back();
    }

    const size_t length = output.size();
    for (size_t i = 0; i < length / 2; ++i) {
        swap(output[i], output[length - i - 1]);
    }
}

void ReverseWord(string& input, size_t start ,size_t end) {
    for (; start < (end + start) / 2; ++start, --end) {
        swap(input[start], input[end - 1]);
    }
}


class Solution {
public:
    string reverseWords(string s) {
        string output;
        ReverseString(s, output);

        size_t start = 0;
        for (size_t i = 0; i < output.size(); ++i) {
            if (output[i] == ' ') {
                ReverseWord(output, start, i);
                start = i + 1;
            }
        }
        ReverseWord(output, start, output.size());

        return output;
    }
};

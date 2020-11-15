#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <stdexcept> 

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (IsValidOperator(tokens[i])) {
                if (operands.size() < 2) {
                    cerr << "输入存在错误." << endl;
                    return -1;
                }
                const int b = operands.top();
                operands.pop();
                const int a = operands.top();
                operands.pop();
                operands.push(Compute(a, b, tokens[i]));
            } else {
                int num = 0;
                try {
                    num = stoi(tokens[i]);
                } catch (const invalid_argument& e) {
                    cerr << "输入的数字不合法, 无法转换!" << endl;
                    return -1;
                }
                operands.push(num);
            }
        }

        if (operands.size() != 1) {
            cerr << "操作符号少了吧. 最后栈中还存在数据. " << endl;
            return -1;
        }
        return operands.top();
    }

private:
    bool IsValidOperator(const string& str) {
        if (str.size() > 1) {
            return false;
        }
        return str[0] == '+' || str[0] == '-' ||
               str[0] == '*' || str[0] == '/';
    }

    int Compute(int a, int b, const string& op) {
        switch (op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0;
        }
    }

private:
    stack<int> operands;
};

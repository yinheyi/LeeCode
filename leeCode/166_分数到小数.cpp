#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator) {

        long numerator = numerator1;
        long denominator = denominator1;

        if (numerator < 0 && denominator > 0 ) {
            numerator = -numerator;
            output += "-";
        } else if (denominator < 0 && numerator > 0) {
            denominator = -denominator;
            output += "-";
        }

        while (true) {
            long result = numerator / denominator;
            long remainder = numerator % denominator;
            output += to_string(result);

            // 保存结果, 并且余数为0时,可以结束掉.
            if (remainder == 0) {
                break;
            }

            // 把当前被除数对应的结果的起始下标保存到map中.
            if (hasPoint) { 
                num2Index[numerator] = output.size() - 1;
                cout << "保存:" << "key: " << numerator << ", value: " << output.size() - 1 << endl;
            }

            // 如果有必要,加上小数点
            if (!hasPoint) {
                output.push_back('.');
                hasPoint = true;
            }

            numerator = remainder * 10;

            // 出现循环时, 加上括号后,可以退出.
            if (num2Index.count(numerator) == 1) {
                output.insert(output.begin() + num2Index[numerator], '(');
                output.push_back(')');
                break;
            }

        }
        return output;
    }
private:
    bool hasPoint = false;
    string output;
    map<long, size_t> num2Index;
};

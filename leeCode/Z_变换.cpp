#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert1(string s, int numRows) {
        vector<string> temp(numRows);
        string res;
        if(s.empty() || numRows < 1) return res;
        if(numRows == 1) return s;
        for(int i = 0; i < s.size(); i++){
            int ans = i / (numRows-1);
            int cur = i % (numRows-1);
            if(ans % 2 == 0){  //结果为偶数或0
                temp[cur].push_back(s[i]); //按余数正序保存
            }
            if(ans % 2 != 0){  //结果为奇数
                temp[numRows-cur-1].push_back(s[i]); //按余数倒序保存
            }
        }
       for(int i = 0; i < temp.size(); i++){
               res += temp[i];
        }
        return res;
    }

string convert(string s, int numRows)
{
    if (numRows == 1 && s.size() <= numRows) {
        return s;
    }
    const int strSize = static_cast<int>(s.size());
    const int column = 1 + (strSize - numRows + numRows - 1 - 1) / (numRows - 1);
    vector<vector<char>> Table(numRows, vector<char>(column, ' '));

    int charCount = 0;
    for (int i = 0; i < numRows && charCount < strSize; ++i, ++charCount) {
        Table[i][0] = s[charCount];
    }

    int columnIndex = 1;
    for (int columnIndex = 1; columnIndex < column && charCount < strSize; ++columnIndex) {
        if ((columnIndex & 0x01) == 0x01) {
            for (int rowIndex = numRows - 2; rowIndex >= 0 && charCount < strSize; --rowIndex, ++charCount) {
                Table[rowIndex][columnIndex] = s[charCount];
            }
        } else {
            for (int rowIndex = 1; rowIndex < numRows && charCount < strSize; ++rowIndex, ++charCount) {
                Table[rowIndex][columnIndex] = s[charCount];
            }
        }
    }

    string result;
    for (int rowIndex = 0; rowIndex < numRows; ++rowIndex) {
        for (int columnIndex = 0; columnIndex < column; ++columnIndex) {
            if (Table[rowIndex][columnIndex] != ' ') {
                result.push_back(Table[rowIndex][columnIndex]);
            }
        }
    }

    cout << s << endl;
    cout << result << endl;
    return result.size() == s.size() ? result : "hello ,world!";
}


int main()
{
    string input;
    int rows;
    while (cin >> input >> rows) {
    cout << convert1(input, rows) << endl;
    }
    return 0;
}

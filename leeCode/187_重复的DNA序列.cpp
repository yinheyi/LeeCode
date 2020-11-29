#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> repeatedDNA;
        if (s.size() <= 10) {
            return repeatedDNA;
        }

        for (size_t i = 0; i <= s.size() - 10; ++i) {
            ++container[s.substr(i, 10)];
        }

        for (const auto& item : container) {
            if (item.second > 1) {
                repeatedDNA.push_back(item.first);
            }
        }
        return repeatedDNA;
    }
private:
    unordered_map<string, int> container;
};


/* 方法二:自己构建字符串的hash值.
class KeyCreator {
public:
    explicit KeyCreator(const string& str) : strData(str) {
        if (str.size() < 10) {
            nextPos = str.size();
        } else {
            string initBinaryStr;
            for (size_t i = 0; i < 9; ++i) {
                initBinaryStr += ConvertDNAToBinaray(str[i]);
            }
            key = bitset<20>(initBinaryStr);
            nextPos = 9;
        }
    }

    bool HasNextKey() {
        return nextPos < strData.size();
    }

    unsigned long next() {
        key <<= 2;
        string newBit = ConvertDNAToBinaray(strData[nextPos++]);
        bitset<20> newKey(newBit);
        key |= newKey;
        return key.to_ulong();
    }

private:
    string ConvertDNAToBinaray (char ch) {
        switch (ch) {
            case 'A': return "00";
            case 'C': return "01";
            case 'G': return "10";
            case 'T': return "11";
            default:  return "";
        }
    }

    size_t nextPos = 0;
    string strData;
    bitset<20> key;
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        size_t start = 0;
        vector<string> repeatedDNA;
        KeyCreator hash(s);
        while (hash.HasNextKey()) {
            if (++container[hash.next()] > 1) {
                repeatedDNA.push_back(s.substr(start, 10));
            }
            ++start;
        }
        return repeatedDNA;
    }
private:
    unordered_map<unsigned long, int> container;
};

*/

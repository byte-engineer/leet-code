// https://leetcode.com/problems/roman-to-integer/

#include <iostream>
#include <unordered_map>

using std::string;

class Solution
{
public:
    static int romanToInt(string s)
    {
        std::unordered_map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;

        int stoke = 0;
        char prevCode = '\0';

        for (auto currentCode : s) {
            if (currentCode == 'V' and prevCode == 'I') {
                stoke += 4 - 1;
                continue;
            } else if (currentCode == 'X' and prevCode == 'I') {
                stoke += 9 - 1;
                continue;
            } else if (currentCode == 'L' and prevCode == 'X') {
                stoke += 40 - 10;
                continue;
            } else if (currentCode == 'C' and prevCode == 'X') {
                stoke += 90 - 10;
                continue;
            } else if (currentCode == 'D' and prevCode == 'C') {
                stoke += 400 - 100;
                continue;
            } else if (currentCode == 'M' and prevCode == 'C') {
                stoke += 900 - 100;
                continue;
            } else {
                stoke += table[currentCode];
            }
            prevCode = currentCode;
        }
        return stoke;
    }
};

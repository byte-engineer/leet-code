// https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <string>

using std::string;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        string stringified = std::to_string(x);
        string flipped = "";

        for (auto iter = stringified.rbegin(); iter != stringified.rend(); ++iter)
        {
            flipped += *iter;
        }
        return stringified == flipped;
    }
};
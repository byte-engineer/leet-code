// https://leetcode.com/problems/divide-two-integers/

#include <iostream>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int count = 0;
        dividend = std::abs(dividend);
        divisor = std::abs(divisor);

        while (dividend > 0) {
            dividend -= divisor;
            count++;
        }
        return count;
    }
};



int main() {
    
}
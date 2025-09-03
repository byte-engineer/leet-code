#include <iostream>
#include <limits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }

        // promote before taking abs to avoid UB
        long long a = std::abs((long long)dividend);
        long long b = std::abs((long long)divisor);

        long long result = 0;
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        // safe: result is long long, no overflow risk on negation
        if ((dividend < 0) ^ (divisor < 0)) result = -result;

        // clamp back into int
        if (result > std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        if (result < std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();
        return (int)result;
    }
};

int main() {
    Solution sol;
    std::cout << sol.divide(10, 3) << std::endl;     // 3
    std::cout << sol.divide(-7, 2) << std::endl;     // -3
    std::cout << sol.divide(-2147483648, 2) << std::endl; // -1073741824
}

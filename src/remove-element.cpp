// https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>

using std::vector;

// array = [1,2,2,4,5,6,7,7,9]      value = 7
// answer => 7

class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        unsigned int counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[counter] = nums[i];
                counter++;
            }  
        }
        return counter;
    }
};


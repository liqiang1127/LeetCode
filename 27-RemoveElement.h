//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_REMOVEELEMENT27_H
#define LEETCODE_REMOVEELEMENT27_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; //[0,k)存储非val的元素
        for (int i = 0; i < nums.size() ; ++i) {
            if(nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};

#endif //LEETCODE_REMOVEELEMENT27_H

//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_REMOVEDUPLICATES_H
#define LEETCODE_REMOVEDUPLICATES_H

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int k = 1; //[0,k)存放不重复的元素
        //由于元素已经有序 只比较 nums[k-1] 和当前元素就可以了
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] != nums[k-1])
                nums[k++] = nums[i];
        }
        return k;
    }
};

#endif //LEETCODE_REMOVEDUPLICATES_H

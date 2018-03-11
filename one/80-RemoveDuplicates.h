//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_REMOVEDUPLICATES80_H
#define LEETCODE_REMOVEDUPLICATES80_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int j=0,k=1;//[j,k)表示不重复的某一元素 默认第一个不重复了
        for (int i = 1; i < nums.size() ; ++i) {
            if(nums[i] == nums[k-1]){
                if( k-j < 2){
                    nums[k++] = nums[i];
                }
            } else { //nums[i] != nums[k-1]
                nums[k] = nums[i];
                j=k;
                k++;
            }
        }
        return  k;
    }
};

#endif //LEETCODE_REMOVEDUPLICATES80_H

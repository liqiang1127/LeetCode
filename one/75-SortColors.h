//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_SORTCOLORS75_H
#define LEETCODE_SORTCOLORS75_H

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        //利用三路快排的思想
        //循环不变量[0,zero] == 0 [zero+1,i-1] ==1  [i,two-1]为 当前处理的元素 [two,n-1] == 2
        int zero = -1,two=nums.size();
        int i = 0;
        while (i < two){
            if(nums[i] == 1){
                i++;
            }else if(nums[i] == 2){
                swap(nums[i],nums[--two]);
            }else{ //nums[i] == 0
                swap(nums[i++],nums[++zero]);
            }
        }
    }
};

#endif //LEETCODE_SORTCOLORS75_H

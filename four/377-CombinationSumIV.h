//
// Created by liqiang on 2018/3/17.
//

#ifndef LEETCODE_377_COMBINATIONSUMIV_H
#define LEETCODE_377_COMBINATIONSUMIV_H

#include <iostream>
#include <vector>

using namespace std;

//完全背包问题 填满就行
//状态定义
//f(i,c) = f(i , c-nums[i]) || f( i-1 , c)
class Solution {

private:
public:
    int combinationSum4(vector<int>& nums, int target) {

    }
};


#endif //LEETCODE_377_COMBINATIONSUMIV_H

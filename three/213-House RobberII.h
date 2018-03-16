//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_213_HOUSE_ROBBERII_H
#define LEETCODE_213_HOUSE_ROBBERII_H

//参考198
#include <iostream>
#include <vector>

using namespace std;

//最后的结果一定是以下2中情况之一 1.偷第一间 2.不偷第一间

//如果偷第一间 那么最后一间不能偷 结果在[0...n-2]中偷
//如果不偷第一间 那么结果在[1..n-1]中偷 转换成198
//比较这2种情况 得出结论
class Solution {
private:
    int subRob(vector<int> &nums,int start,int end){
        vector<int> memo(nums.size(),-1);
        //memo[i] 记录 [start...i]的最大偷窃金额
        memo[start] = nums[start];
        for (int i = start + 1; i <= end ; ++i) {
            //计算memo[i]
            for (int j = i; j >= start ; --j) {
                memo[i] = max(memo[i] , nums[j] + ( j - 2 >=start ? memo[j-2] : 0));
            }
        }
        return memo[end];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        return max(subRob(nums,0,n-2),subRob(nums,1,n-1));
    }
};

#endif //LEETCODE_213_HOUSE_ROBBERII_H

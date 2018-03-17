//
// Created by liqiang on 2018/3/17.
//

#ifndef LEETCODE_300_LIS_H
#define LEETCODE_300_LIS_H


#include <iostream>
#include <vector>

using namespace std;

//状态定义 f(i) 代表 [0..i]中最长子序列的长度 并且一定要包含i这个数字
//或者说 f(i) 代表 以i结尾的最长子序列的长度
//状态转移方程 f(i) = max(1 + f(j){ nums[j] < nums[i]  &&  j < i} , f(i))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        if( n == 0)
            return 0;
        //初始化 每个元素构成一个长度为1的递增序列
        vector<int> memo(n,1);

        int maxLength = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i ; ++j) {
                if(nums[j] < nums[i])
                    memo[i] = max(memo[i] , memo[j]+1);
            }
            if(maxLength < memo[i] )
                maxLength = memo[i];
        }
        return maxLength;
    }
};
#endif //LEETCODE_300_LIS_H

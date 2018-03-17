//
// Created by liqiang on 2018/3/17.
//

#ifndef LEETCODE_416_PARTITIONEQUALSUBSETSUM_H
#define LEETCODE_416_PARTITIONEQUALSUBSETSUM_H

#include <vector>
#include <iostream>

using namespace std;


//问题分析 实际上这题是一个背包问题  能不能在[0...n]个中挑选数字 装满一个大小为sum/2的背包
//状态定义 f(i,c) 表示在 [0...i]中挑选数组 能否装满 容量为c的背包
//对于当前的i 可以选也可以不选 当选择当前的数字 其他数字能不能装满 c-i的背包 2者的成立一者即可
//状态转移 f(i,c) = f(i-1,c) ||  f(i-1,c - i);

//参考0-1背包问题
//动态规划
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        if( n == 0)
            return 0;

        int sum = 0;
        for (int i = 0; i < n ; ++i)
            sum += nums[i];

        if(sum % 2 != 0)
            return false;

        vector<int> memo(sum/2+1,-1);

        //考虑第一行
        for (int j = 0; j <= sum/2 ; ++j)
            memo[j] = ( j == nums[0] ? 1:0);

        for (int i = 1; i < n ; ++i) {
            for (int j = sum/2; j >= nums[i]  ; --j) {
                memo[j] = memo[j] == 1 || memo[j-nums[i]] == 1;
            }
        }

        return memo[sum/2] == 1;
    }
};


//记忆化搜索
//class Solution {
//private:
//    // -1 当前位置没考虑过  1 当前位置为真 0 当前位置为假
//    vector<vector<int>> memo;
//    bool tryPartition(vector<int> &nums,int index,int sum){
//        //sum == 0 说明当前的情况下可以装满
//        if(sum == 0)
//            return true;
//
//        //如果 sum < 0 或者 已经没有可放的元素了 返回false
//        if(sum < 0 || index < 0)
//            return false;
//
//        if(memo[index][sum] != -1)
//            return memo[index][sum] == 1;
//
//        //以下逻辑 对应 状态转移方程
//        memo[index][sum] =( tryPartition(nums,index-1,sum)
//               || tryPartition(nums,index-1,sum - nums[index])) ? 1 : 0;
//
//        return memo[index][sum] == 1;
//    }
//public:
//    bool canPartition(vector<int>& nums) {
//        int n = nums.size();
//        if( n == 0)
//            return false;
//
//        int sum = 0;
//        for (int i = 0; i < n ; ++i)
//            sum += nums[i];
//
//        //和都不是双数  怎么分也不可能分成2个相等的部分的
//        if( sum % 2 != 0)
//            return false;
//
//        memo = vector<vector<int>>(n,vector<int>(sum/2+1,-1));
//
//        return tryPartition(nums,n-1,sum/2);
//    }
//};
#endif //LEETCODE_416_PARTITIONEQUALSUBSETSUM_H

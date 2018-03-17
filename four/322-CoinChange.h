//
// Created by liqiang on 2018/3/17.
//

#ifndef LEETCODE_322_COINCHANGE_H
#define LEETCODE_322_COINCHANGE_H

#include <iostream>
#include <vector>

using namespace std;

//状态定义
//f(i,amount)为定义为[0...i]中选择硬币价值为amount最少的硬币数目
//状态转移 放i和不放i
//f(i,a) = min(f(i,a-coins[i])+1,f(i-1,a))

//dp[n]为amount为n的change数目，那么我们从dp[1]开始就可以DP到dp[n]，迭代关系式为，dp[n] = min(dp[n], dp[n-coins[m]]+1)

// 0-1背包是从后向前 完全背包是从前往后

//动态规划
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if(amount < 0) return -1;
//        vector<int> cnt(amount+1, amount+1);
//        cnt[0] = 0;
//        for(int i=1; i<=amount; ++i) {
//            for(int j=0; j<coins.size(); ++j) {
//                if(i>=coins[j]) {
//                    cnt[i] = min(cnt[i], cnt[i-coins[j]] + 1);
//                }
//            }
//        }
//        return (cnt[amount]==amount+1) ? -1 : cnt[amount];
//    }
//};

//记忆化搜索
class Solution {
private:
    vector<vector<int>> memo;
    int max;
    int tryChange(vector<int> &coins,int index,int amount){
        if(amount == 0)
            return 0;
        if(index < 0 || amount < 0)
            return max;

        if(memo[index][amount] != -1)
            return memo[index][amount];

        memo[index][amount] = min(tryChange(coins,index-1,amount) , tryChange(coins,index,amount-coins[index])+1);

        return memo[index][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        if(n == 0)
            return 0;

        memo = vector<vector<int>>(n,vector<int>(amount+1,-1));
        max = amount+1;

        int res = tryChange(coins,n-1,amount);

        return res == max? -1 : res;
    }
};

#endif //LEETCODE_322_COINCHANGE_H

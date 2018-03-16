//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_309_BESTTIMETOBUYSELLSTOCKCOOLDOWN_H
#define LEETCODE_309_BESTTIMETOBUYSELLSTOCKCOOLDOWN_H

#include <iostream>
#include <vector>

using namespace std;
//对于买来说，当天是否买取决于买了之后是否比之前买所剩余的利润大，即状态转移方程为：
//buy[i] = max(buy[i-1], sell[i-2] - prices[i]);
//对于卖来说，同样当天是否将这只股票卖掉取决于卖掉能否获得更大的利润，状态转移方程为：
//sell[i] = max(sell[i-1], sell[i-1] + prices[i]);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)
            return 0;
        vector<int> buy(n,0);
        vector<int> sell(n,0);

        //sell[i]第i天卖出获得最大利润
        sell[0] = 0;
        //buy[i]第i天买入获得最大的利润 第一天就买利润是负的
        buy[0] = -prices[0];

        for (int i = 1; i < n; ++i) {
            //交易之间不能交叉
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            //
            buy[i] = max(buy[i-1], (i-2 < 0? 0: sell[i-2]) - prices[i]);

        }
        return sell[n-1];
    }
};

#endif //LEETCODE_309_BESTTIMETOBUYSELLSTOCKCOOLDOWN_H

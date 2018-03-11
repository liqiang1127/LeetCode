//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_MINIMUMSIZESUBARRAYSUM209_H
#define LEETCODE_MINIMUMSIZESUBARRAYSUM209_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
//滑动窗口
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //找最短 初试设为一个长的取不到的值
        int l = 0, r = -1;// [l,r] 包含最短的子串
        int sum = 0;
        int res = nums.size() + 1;
        while (l < nums.size()) {
            if ( r+1 < nums.size() && sum < s) {
                r++;
                sum += nums[r];
            } else {
                sum -= nums[l];
                l++;
            }
            if (sum >= s)
                res = min(res, r - l + 1);
        }
        if (res == nums.size() + 1)
            return 0;
        return res;
    }
};

#endif //LEETCODE_MINIMUMSIZESUBARRAYSUM209_H

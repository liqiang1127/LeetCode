//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_16_3SUMCLOSEST_H
#define LEETCODE_16_3SUMCLOSEST_H

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    //算法思路:先排序，确定一个数以后，在剩下的数中，用指针对撞，不断逼近target并统计最小差值出现时的和！
    //利用先排序，在指针对撞的思路可以将O(n^3)的算法降低到O(n^2)
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;//记录最小差值更新的时候的和
        int minDiff = INT_MAX;//记录最小差值
        if(nums.size() < 3)
            return res;
        for (int i = 0; i < nums.size() - 2 ; ++i) {
            //这里使用指针对撞 不断逼近 target
            int l=i+1,r=nums.size()-1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if( sum == target)
                    //如果相等了 不用看了 0为最小差值 不会有更小的结果
                    return sum;
                //当sum不等于target
                //比较差值 更新差值
                int diff = sum > target ? sum - target : target - sum;
                //当差值比最小差值还小
                if(diff < minDiff){
                    minDiff = diff;
                    res = sum;
                }else
                //调整数值 逼近target
                if(sum > target)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
};

#endif //LEETCODE_16_3SUMCLOSEST_H

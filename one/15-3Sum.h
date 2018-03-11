//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_3SUM_15_H
#define LEETCODE_3SUM_15_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//算法思想：先排序，确定好1个数以后 在剩余的数字中 使用指针对撞 确定另外2个数字
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        //返回的vector
        for (int i = 0; i < nums.size() ; ++i) {
            // 如果当前数字大于0了 那么就不必做下去了
            // == 0 不能退出循环可能有{0 0 0}这种组合
            if(nums[i] > 0)
                break;
            int l = i+1,r = nums.size() -1;//指针对撞
            int targetSum = 0 - nums[i];

            while ( l < r){
                //目标数字
                int sum = nums[l]+nums[r];

                if( sum == targetSum ){
                    vector<int> triplet{nums[i],nums[l],nums[r]};
                    res.push_back(triplet);

                    //以下至关重要 去重复 避免 l++ r--之后遇到相同的元素
                    while ( l < r && nums[l] == triplet[1])
                        l++;
                    while ( r < r && nums[r] == triplet[2])
                        r--;
                } else if(sum > targetSum){
                    r--;
                } else {
                    l++;
                }
            }
            //i 也是一样 重复的跳过
            while ( i < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return  res;
    }
};

#endif //LEETCODE_3SUM_15_H

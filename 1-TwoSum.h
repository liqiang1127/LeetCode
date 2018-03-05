//
// Created by liqiang on 2018/3/2.
//

#ifndef LEETCODE_TWOSUM_H
#define LEETCODE_TWOSUM_H

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         //查找表技术应用
        //不能一次全存进map 一次全进去 会导致 覆盖的问题
        unordered_map<int,int> map;//  key-数字  value-索引
        for (int i = 0; i < nums.size() ; ++i) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                //找到了complement
                int res[2] = {map[complement],i};
                return vector<int>(res,res+2);
            }
            map.insert(make_pair(nums[i],i));
        }

    }
};
#endif //LEETCODE_TWOSUM_H

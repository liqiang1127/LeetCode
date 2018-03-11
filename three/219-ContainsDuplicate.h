//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_219_CONTAINSDUPLICATE_H
#define LEETCODE_219_CONTAINSDUPLICATE_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //滑动窗口+查找表
        //只关心有没有  用set就可以了
        // r - l <= k
        //record 最多存储 k 个元素
        unordered_set<int> record;
        for (int i = 0; i < nums.size() ; ++i) {
            if(record.find(nums[i]) != record.end())
                //找到了某个相等的元素
                return true;
            //否则没找到
            record.insert(nums[i]);
            if(record.size() > k)
                record.erase(nums[i-k]);
        }
        return false;
    }
};

#endif //LEETCODE_219_CONTAINSDUPLICATE_H

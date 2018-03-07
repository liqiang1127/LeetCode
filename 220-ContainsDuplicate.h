//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_220_CONTAINSDUPLICATE_H
#define LEETCODE_220_CONTAINSDUPLICATE_H

#include <iostream>
#include <vector>
#include <set>


using namespace std;

//时间复杂度 O(n)
//空间复杂度 O(k)
class Solution {
public:
    //参考219
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        for (int i = 0; i < nums.size() ; ++i) {
            //在窗口中存在一个大于等于nums[i]的数，并且这个数小于等于 nums[i] + t
            //那个这个数和nums[i]的绝对差值 肯定小于t
            //leetcode 这题 有也越界的坑
            if(record.lower_bound( (long long)nums[i] - (long long)t) != record.end() && *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t)
                return true;

            record.insert(nums[i]);
            if(record.size() > k)
                record.erase(nums[i - k]);
        }
        return false;
    }
};

#endif //LEETCODE_220_CONTAINSDUPLICATE_H

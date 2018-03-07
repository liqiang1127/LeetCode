//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_217_CONTAINSDUPLICATE_H
#define LEETCODE_217_CONTAINSDUPLICATE_H

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
        for (int i = 0; i < nums.size() ; ++i) {
            if(record.find(nums[i]) != record.end()){
                return true;
            }
            record.insert(nums[i]);
        }
        return false;
    }
};

#endif //LEETCODE_217_CONTAINSDUPLICATE_H

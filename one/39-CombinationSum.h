//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_39_COMBINATIONSUM_H
#define LEETCODE_39_COMBINATIONSUM_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    //这个和传统的组合问题 不一样在于 当前元素可以选择多次 所以start每次从i开始 不是从i+1开始
    vector<vector<int>> res;
    void findCombinations(vector<int>& candidates,int target,int start,vector<int>& p){
        if(target == 0){
            res.push_back(p);
            return;
        }

        for (int i = start; i < candidates.size() ; ++i) {
            target -= candidates[i];
            if(target >= 0){
                p.push_back(candidates[i]);
                findCombinations(candidates,target,i,p);
                target += candidates[i];
                p.pop_back();
            }else{
                target += candidates[i];
                continue;
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty() || target == 0)
            return res;
        res.clear();
        vector<int> p;
        findCombinations(candidates,target,0,p);
        return res;
    }
};

#endif //LEETCODE_39_COMBINATIONSUM_H

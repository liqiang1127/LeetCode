//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_40_COMBINATIONSUMII_H
#define LEETCODE_40_COMBINATIONSUMII_H

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;


class Solution {

private:
    vector<vector<int>> res;
    //
    void findCombinations(vector<int>& candidates, int target,int start,vector<int> & p){
        if(target == 0){
            res.push_back(p);
            return;
        }
        if(target < 0){
            return;
        }

        //在组合问题中 不设置used[]数组
        for (int i = start; i < candidates.size(); ++i) {
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            p.push_back(candidates[i]);
            findCombinations(candidates,target - candidates[i],i+1,p);
            p.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty() || target == 0)
            return res;
        sort(candidates.begin(),candidates.end());
        vector<int> p;
        findCombinations(candidates,target,0,p);
        return res;
    }
};

#endif //LEETCODE_40_COMBINATIONSUMII_H

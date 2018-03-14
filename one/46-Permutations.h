//
// Created by liqiang on 2018/3/12.
//

#ifndef LEETCODE_46_PERMUTATIONS_H
#define LEETCODE_46_PERMUTATIONS_H
#include<iostream>
#include <vector>

using namespace std;


class Solution {
private:
    vector<vector<int>> res;

    void dfs(vector<int> &nums,int count,vector<int> &p,vector<bool> &used){
        if(count == nums.size()){
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size() ; ++i) {
            if(!used[i]){//第i个数字没被用过
                p.push_back(nums[i]);
                used[i] = true;
                dfs(nums,count+1,p,used);
                p.pop_back();
                used[i] = false;
            }
        }
    }
public:
    //排列问题 元素各不相同
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.empty())
            return res;
        vector<int> p;
        vector<bool> used(nums.size(),false);
        dfs(nums,0,p,used);
        return res;
    }
};
#endif //LEETCODE_46_PERMUTATIONS_H

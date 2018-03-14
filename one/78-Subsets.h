//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_78_SUBSETS_H
#define LEETCODE_78_SUBSETS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<vector<int>> subs;
    //在nums里面寻找元素个数为n的子集
    void findSubsets(vector<int> &num,int n,int start,vector<int> &p){
        if(n==0){
            subs.push_back(p);
            return;
        }

        for (int i = start; i < num.size(); ++i) {
            p.push_back(num[i]);
            findSubsets(num,n-1,i+1,p);
            p.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(vector<int>());
        if(nums.empty())
            return res;
        res.push_back(nums);
        for (int i = 1; i < nums.size() ; ++i) {
            subs.clear();
            vector<int> p;
            findSubsets(nums,i,0,p);
            for(auto vec : subs){
                res.push_back(vec);
            }
        }

        return res;
    }
};

#endif //LEETCODE_78_SUBSETS_H

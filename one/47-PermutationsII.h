//
// Created by liqiang on 2018/3/12.
//

#ifndef LEETCODE_47_PERMUTATIONSII_H
#define LEETCODE_47_PERMUTATIONSII_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& used, vector<vector<int> >& sol, vector<int>& ans){
        if(ans.size() == nums.size()){
            sol.push_back(ans);
            return;
        }
        for(int i = 0; i < used.size(); i++){
            if(used[i]){
                continue;
            }
            //这里!used[i-1]和used[i-1]都可以其效果但是有!效率更高!!!这是难点
            //原理:由于已经排好序了,原则上取相同数字做第一位只能取第一个数字
            //如果当前元素是重复的但是不是第一个 就可以取
            //如果当前元素前面有一个重复元素 但是没被取过 那一定是这个数的所有排列都已经讨论过了 回溯的时候 由true变成了false 那当前元素由于重复也没必要作为
            // 打头元素讨论了
            if(i>0 && nums[i-1] == nums[i] && !used[i-1]) continue;

            used[i] = true;
            ans.push_back(nums[i]);
            dfs(nums,used,sol,ans);
            ans.pop_back();
            used[i] = false;
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        vector<vector<int> > sol;
        vector<int> ans;
        dfs(nums,used,sol,ans);
        return sol;
    }
};

//class Solution {
//private:
//    vector<vector<int>> res;
//    unordered_set<string> record;
//    void dfs(vector<int> &nums,int count,vector<int> &p,vector<bool> used){
//        if(count == nums.size()){
//            string key = vectorContentStr(p);
//            if(record.find(key) == record.end()){
//                res.push_back(p);
//                record.insert(key);
//                return;
//            }
//        }
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if(!used[i]){
//                p.push_back(nums[i]);
//                used[i] = true;
//                dfs(nums,count+1,p,used);
//                p.pop_back();
//                used[i] = false;
//            }
//        }
//    }
//
//    string vectorContentStr(vector<int> vec){
//        string res= "";
//        for(auto i : vec){
//            res+=to_string(i);
//        }
//        return res;
//    }
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        if(nums.empty())
//            return res;
//        vector<bool> used(nums.size(),false);
//        vector<int> p;
//        dfs(nums,0,p,used);
//        return res;
//    }
//};

#endif //LEETCODE_47_PERMUTATIONSII_H

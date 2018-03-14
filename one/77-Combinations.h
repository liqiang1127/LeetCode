//
// Created by liqiang on 2018/3/12.
//

#ifndef LEETCODE_77_COMBINATIONS_H
#define LEETCODE_77_COMBINATIONS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void dfs(int n,int k,int start,vector<int> &p){
        if(p.size() ==  k){
            res.push_back(p);
            return;
        }

        //组合数 前面考虑过得后面就不能再考虑了
        //start之前的在前面都考虑过了
        //剪枝优化 还有k-p.size()个空位 所以在[i...n]中至少要有k-p.size()个位置
        // n - i + 1 >= k - p.size() =>  i <= n - (k - p.size()) + 1
        for (int i = start; i <= n - (k - p.size()) + 1 ; ++i) {
            p.push_back(i);
            dfs(n,k,i+1,p);
            p.pop_back();
        }

    }
public:
    //计算 C(n,k);
    vector<vector<int>> combine(int n, int k) {
        if(n == 0 || k == 0 || k > n)
            return res;
        vector<int> p;
        dfs(n,k,1,p);
        return res;
    }
};

#endif //LEETCODE_77_COMBINATIONS_H

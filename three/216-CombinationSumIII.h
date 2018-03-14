//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_216_COMBINATIONSUMIII_H
#define LEETCODE_216_COMBINATIONSUMIII_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    //在0-9中挑选 k个 使得和为n
    void findConbinations(int k,int n,int start,vector<int> &p){

        if(k == 0){
            if(n == 0 ){
                res.push_back(p);
            }
                return;
        }
        if( n < 0)
            return;
        for (int i = start; i < 10 ; ++i) {
            p.push_back(i);
            findConbinations(k-1,n-i,i+1,p);
            p.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> p;
        findConbinations(k,n,1,p);
        return res;
    }
};

#endif //LEETCODE_216_COMBINATIONSUMIII_H

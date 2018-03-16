//
// Created by liqiang on 2018/3/14.
//

#ifndef LEETCODE_70_CLIMBINGSTAIRS_H
#define LEETCODE_70_CLIMBINGSTAIRS_H

#include <iostream>
#include <vector>

using namespace std;



class Solution {
private:
    int memoSearch(int n,vector<int> &res){
        if( n == 1 || n == 0)
            return 1;

        if(res[n] == -1)
            res[n] = memoSearch(n-1,res) + memoSearch(n-2,res);

        return res[n];
    }
public:
    int climbStairs(int n) {
        vector<int> res(n+1,-1);
        return memoSearch(n,res);
    }
};


//class Solution {
//public:
//    int climbStairs(int n) {
//        vector<int> mome(n+1,0);
//        mome[0] = 1;
//        mome[1] = 1;
//        for (int i = 2; i <= n ; ++i) {
//            mome[n] = mome[n-1] + mome[n-2];
//        }
//        return mome[n];
//    }
//};

#endif //LEETCODE_70_CLIMBINGSTAIRS_H

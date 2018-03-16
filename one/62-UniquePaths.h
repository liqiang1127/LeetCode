//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_62_UNIQUEPATHS_H
#define LEETCODE_62_UNIQUEPATHS_H

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m,vector<int>(n,-1));
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if( i == 0 && j == 0)
                    memo[i][j] = 1;
                else if( i == 0)
                    memo[i][j] = memo[i][j-1];
                else if( j == 0)
                    memo[i][j] = memo[i-1][j];
                else
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[m-1][n-1];
    }
};

//记忆化搜索
//class Solution {
//private:
//    vector<vector<int>> memo;
//    int findPath(int i,int j){
//        if(memo[i][j] != -1)
//            return memo[i][j];
//        int res = 0;
//        if(i==0 && j==0){
//            res = 1;
//        } else if(i == 0){
//            res = findPath(i,j-1);
//        } else if(j == 0){
//            res = findPath(i-1,j);
//        }else {
//            res = findPath(i-1,j) + findPath(i,j-1);
//        }
//        memo[i][j] = res;
//        return res;
//    }
//public:
//    int uniquePaths(int m, int n) {
//        memo = vector<vector<int>>(m,vector<int>(n,-1));
//        return findPath(m-1,n-1);
//    }
//};

#endif //LEETCODE_62_UNIQUEPATHS_H

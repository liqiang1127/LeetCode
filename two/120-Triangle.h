//
// Created by liqiang on 2018/3/14.
//

#ifndef LEETCODE_120_TRIANGLE_H
#define LEETCODE_120_TRIANGLE_H

#include <iostream>
#include <vector>

using namespace std;

//按照递归、记忆化搜索、动态规划的顺序去求解

//动态规划 - 自底向上
//class Solution {
//public:
//    //第三版 动态规划
//    int minimumTotal(vector<vector<int>>& triangle) {
//        //从倒数第二行开始
//        for (int i = triangle.size()-2; i >= 0 ; i-- ) {
//            for (int j = 0; j <= i ; ++j) {
//                triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1]) + triangle[i][j];
//            }
//        }
//        return triangle[0][0];
//    }
//};

//记忆化搜索 - 自顶向下
class Solution {
private:
    vector<vector<int>> memo;
    //求一个n层数塔的最小路径和
    //i是层数 j是列数
    int mini(int i,int j,vector<vector<int>>& triangle){
        if( i == triangle.size() - 1){
            //做到最底层了
            memo[i][j] = triangle[i][j];
            return triangle[i][j];
        }
        if(memo[i][j] != INT_MAX)
            return memo[i][j];
        memo[i][j] = min(mini(i+1,j,triangle),mini(i+1,j+1,triangle)) + triangle[i][j];
        return memo[i][j];
    }
public:
    //第二版 记忆化搜索
    int minimumTotal(vector<vector<int>>& triangle) {
        memo = vector<vector<int>>(triangle.size(),vector<int>(triangle.size(),INT_MAX));
        return mini(0,0,triangle);
    }
};



//递归版本 超时 处于中间的递归实例会多次计算
//class Solution {
//private:
//
//    //求一个n层数塔的最小路径和
//    //i是层数 j是列数
//    int mini(int i,int j,vector<vector<int>>& triangle){
//        if( i == triangle.size() - 1){
//            //做到最底层了
//            return triangle[i][j];
//        }
//        return min(mini(i+1,j,triangle),mini(i+1,j+1,triangle)) + triangle[i][j];
//    }
//public:
//    //第一版 递归
//    int minimumTotal(vector<vector<int>>& triangle) {
//        return mini(0,0,triangle);
//    }
//};

#endif //LEETCODE_120_TRIANGLE_H

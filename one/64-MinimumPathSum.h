//
// Created by liqiang on 2018/3/14.
//

#ifndef LEETCODE_64_MINIMUMPATHSUM_H
#define LEETCODE_64_MINIMUMPATHSUM_H

#include <iostream>
#include <vector>

using namespace std;


//动态规划 - 自底向上
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size() ; ++i) {
            for (int j = 0; j < grid[0].size() ; ++j) {
                if( i == 0 && j == 0)
                    continue;
                else if(i == 0){
                    grid[i][j] = grid[i][j-1] + grid[i][j] ;
                }else if( j == 0){
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }else {
                    grid[i][j] = min(grid[i][j-1],grid[i-1][j]) + grid[i][j];
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};




//记忆化搜索 - 自顶向下
//class Solution {
//private:
//    vector<vector<int>> memo;
//    //查找能到(x,y)位置最小和
//    int findMiniPath(vector<vector<int>>& grid,int i, int j){
//        if( i == 0 && j == 0){
//            memo[0][0] = grid[0][0];
//            return memo[0][0];
//        }
//
//        if(memo[i][j] != -1)
//            return memo[i][j];
//
//        if( i == 0){
//            //已经到了第0行
//            memo[i][j] = findMiniPath(grid,i,j-1) + grid[i][j];
//        }else if( j == 0 ){
//            //到了第0列
//            memo[i][j] =  findMiniPath(grid,i-1,j) + grid[i][j];
//        } else
//            memo[i][j] =  min(findMiniPath(grid,i,j-1),findMiniPath(grid,i-1,j)) + grid[i][j];
//        return memo[i][j];
//    }
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        if(grid.size() == 0){
//            return 0;
//        }
//        //记忆
//        memo = vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),-1));
//        return findMiniPath(grid,grid.size()-1,grid[0].size()-1);
//    }
//};

////第一版本递归
//class Solution {
//private:
//    //查找能到(x,y)位置最小和
//    int findMiniPath(vector<vector<int>>& grid,int i, int j){
//        if( i == 0 && j == 0){
//            return grid[0][0];
//        }
//
//        if( i == 0 ){
//            //已经到了第0行
//            return findMiniPath(grid,i,j-1) + grid[i][j];
//        }
//        if( j == 0){
//            //到了第0列
//            return findMiniPath(grid,i-1,j) + grid[i][j];
//        }
//        return min(findMiniPath(grid,i,j-1),findMiniPath(grid,i-1,j)) + grid[i][j];
//    }
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        if(grid.size() == 0){
//            return 0;
//        }
//        return findMiniPath(grid,grid.size()-1,grid[0].size()-1);
//    }
//};

#endif //LEETCODE_64_MINIMUMPATHSUM_H

//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_63_UNIQUEPATHSII_H
#define LEETCODE_63_UNIQUEPATHSII_H

#include <vector>
#include <iostream>

using namespace std;

//参考62题
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if( i == 0 && j == 0){
                    obstacleGrid[i][j] = 1;
                }else if(i == 0){
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                }else if(j == 0){
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                }else {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};

#endif //LEETCODE_63_UNIQUEPATHSII_H

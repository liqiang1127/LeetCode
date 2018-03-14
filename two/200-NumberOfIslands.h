//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_200_NUMBEROFISLANDS_H
#define LEETCODE_200_NUMBEROFISLANDS_H

#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<bool>> visited;
    int m,n;

    void floodfill(vector<vector<char>> &grid,int x,int y){
        visited[x][y] = true;
        for (int i = 0; i < 4 ; ++i) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if(inArea(newx,newy) && !visited[newx][newy] && grid[newx][newy] == '1')
                floodfill(grid,newx,newy);
        }
    }

    bool inArea(int x,int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        m = grid.size();
        if(m==0)
            return 0;
        n = grid[0].size();
        if(n==0)
            return 0;
        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size() ; ++j) {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    floodfill(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
#endif //LEETCODE_200_NUMBEROFISLANDS_H

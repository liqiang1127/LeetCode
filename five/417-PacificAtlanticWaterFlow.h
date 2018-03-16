//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_417_PACIFICATLANTICWATERFLOW_H
#define LEETCODE_417_PACIFICATLANTICWATERFLOW_H

#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<pair<int,int>> res;
    int m,n;

    void floodfill(vector<vector<int>>& matrix,int x,int y,vector<vector<int>>& map){
        map[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];

            if(inArea(newx,newy) && matrix[x][y] <= matrix[newx][newy] && map[newx][newy] != 1){
                floodfill(matrix,newx,newy,map);
            }
        }
    }

    bool inArea(int x,int y){
        return x >=0 && x < m && y >= 0 && y < n;
    }
public:
    //算法思路:从邻接太平洋的边入手，将能流入太平洋的点设置为1 默认-1
    //对大西洋同理 比较2个map 把都能到的 存入结果集
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        if(m == 0)
            return res;
        n = matrix[0].size();
        if(n == 0)
            return res;

        vector<vector<int>> map1 (m,vector<int>(n,-1));
        vector<vector<int>> map2 (m,vector<int>(n,-1));
        //从第0行入手
        for (int j = 0; j < n ; ++j) {
            floodfill(matrix,0,j,map1);
        }

        //从第0列入手
        for (int i = 0; i <m ; ++i) {
            floodfill(matrix,i,0,map1);
        }

        //从第m-1行入手
        for (int j = 0; j < n; ++j) {
            floodfill(matrix,m-1,j,map2);
        }

        //从第n-1列
        for (int i = 0; i < m; ++i) {
            floodfill(matrix,i,n-1,map2);
        }

        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(map1[i][j] == 1 && map2[i][j] == 1)
                    res.push_back(make_pair(i,j));
            }
        }
        return res;
    }
};

#endif //LEETCODE_417_PACIFICATLANTICWATERFLOW_H

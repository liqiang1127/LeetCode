//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_130_SURROUNDEDREGIONS_H
#define LEETCODE_130_SURROUNDEDREGIONS_H

#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    int m,n;
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

    void floodfill(vector<vector<char>>& board,int x,int y){
        board[x][y] = '*';
        for (int i = 0; i < 4 ; ++i) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];

            if(inArea(newx,newy) && board[newx][newy] == 'O')
                floodfill(board,newx,newy);
        }
    }

    bool inArea(int x,int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0)
            return;
        n = board[0].size();
        //从边界入手 对边界上的O做floodfill 暂时替换成*

        for (int j = 0; j < n; ++j) {
            // 行等于0
            int i = 0;
            if(board[i][j] == 'O')
                floodfill(board,i,j);
        }
        for (int j = 0; j < n; ++j) {
            // 行等于m-1
            int i = m-1;
            if(board[i][j] == 'O')
                floodfill(board,i,j);
        }
        for (int i = 0; i < m; ++i) {
            // 列等于 0
            int j = 0;
            if(board[i][j] == 'O')
                floodfill(board,i,j);
        }
        for (int i = 0; i < m; ++i) {
            // 列等于n-1
            int j = n-1;
            if(board[i][j] == 'O')
                floodfill(board,i,j);
        }

        //转换
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n; ++j) {
                if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};
#endif //LEETCODE_130_SURROUNDEDREGIONS_H

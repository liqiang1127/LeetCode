//
// Created by liqiang on 2018/3/14.
//

#ifndef LEETCODE_51_N_QUEENS_H
#define LEETCODE_51_N_QUEENS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col,dia1,dia2;//列,对角线放没放皇后

    //在n皇后问题中，摆放index行的皇后 row[i][j]表示第i行第j列放置Q
    void putQueen(int n,int index,vector<int> &row){
        if(index == n){
            //全都摆放完成
            res.push_back(generateBoard(n,row));
            return;
        }
        //dia2[index-i+n-1] 主对角线  横坐标-纵坐标 是定值 +n-1保证下标为正的
        //在index行尝试摆放Queen i表示列
        for (int i = 0; i < n ; ++i) {
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                //index行 i列可以放
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                row.push_back(i);
                //递归的去摆放下一行
                putQueen(n,index+1,row);
                //回溯
                row.pop_back();
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
            }
        }
    }

    vector<string> generateBoard(int n,vector<int> &row){
        vector<string> board(n,string(n,'.'));
        for (int i = 0; i < n ; ++i) {
            board[i][row[i]] = 'Q';
        }
        return board;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n==0){
            return res;
        }
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1,false);
        dia2 = vector<bool>(2*n-1,false);

        vector<int> row;
        putQueen(n,0,row);
        return res;
    }
};

#endif //LEETCODE_51_N_QUEENS_H

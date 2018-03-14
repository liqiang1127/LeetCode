//
// Created by liqiang on 2018/3/14.
//

#ifndef LEETCODE_52_N_QUEENSII_H
#define LEETCODE_52_N_QUEENSII_H

#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    int res;
    vector<bool> col,dia1,dia2;

    void putQueen(int n,int index){
        if(index == n){
            res += 1;
            return;
        }

        //在第index行摆放Queen i是列
        for (int i = 0; i < n; ++i) {
            //index行 i列可以放
            if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
                col[i] = true;
                dia1[index+i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n,index+1);
                col[i] = false;
                dia1[index+i] = false;
                dia2[index-i+n-1] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        res = 0;
        if(n==0)
            return res;
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n-1, false);
        dia2 = vector<bool>(2*n-1, false);

        putQueen(n,0);

        return res;
    }
};

#endif //LEETCODE_52_N_QUEENSII_H

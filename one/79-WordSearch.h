//
// Created by liqiang on 2018/3/13.
//

#ifndef LEETCODE_79_WORDSEARCH_H
#define LEETCODE_79_WORDSEARCH_H

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    //位移偏移量
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    vector<vector<bool>> visited;
    //从board[startx][starty]这个位置开始寻找word[index...word.size())
    bool searchWord(vector<vector<char>> &board,string &word,int index,int startx,int starty){
        if(index == word.size() - 1){
            //当考虑到最后一个字母时
            return board[startx][starty] == word[index];
        }

        if(board[startx][starty] == word[index]){
            visited[startx][starty] = true;
            //从这个点的4个相邻的区域继续判断
            for (int i = 0; i < 4; ++i) {
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                //新的这个点在合法区域内 并且没被访问过
                if(inArea(newx,newy) && !visited[newx][newy]){
                    //递归寻找 后面的也全都找到了 返回上层找到了
                    if(searchWord(board,word,index+1,newx,newy))
                        return true;
                }
            }
            //四个点都没找到下一个对应的字母 把这个点放回去 返回false;
            visited[startx][starty] = false;
        }

        return false;
    }

    bool inArea(int x,int y){
        return x >=0 && x < m && y >= 0 && y < n;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();//行数
        n = board[0].size();//列数
        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        for (int i = 0; i < m ; ++i) {
            for (int j = 0; j < n ; ++j) {
                //更换起始点
                if (searchWord(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};

#endif //LEETCODE_79_WORDSEARCH_H

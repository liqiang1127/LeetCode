//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_279_PERFECTSQUARES_H
#define LEETCODE_279_PERFECTSQUARES_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//动态规划
class Solution {
public:
    int numSquares(int n) {
        vector<int> memo = vector<int>(n+1,-1);
        memo[0] = 0;
        memo[1] = 1;

        for (int i = 2; i <= n ; ++i) {
            int res = INT_MAX;
            for (int j = 1; i-j*j >= 0 ; ++j) {
                res = min( res , memo[i-j*j] + 1);
            }
            memo[i] = res;
        }
        return memo[n];
    }
};


//记忆化搜索
//class Solution {
//private:
//    vector<int> memo;
//    //计算平方数加和为n,返回最少的平方数数量
//    int searchSquares(int n){
//        if( n == 0){
//            return 0;
//        }
//        if(memo[n] != -1)
//            return memo[n];
//        int res = INT_MAX;
//        for (int i = 1; n - i*i >=0 ; ++i) {
//            res = min(res,searchSquares(n-i*i) + 1);
//        }
//        memo[n] = res;
//        return res;
//    }
//public:
//    int numSquares(int n) {
//        memo = vector<int>(n+1,-1);
//        return searchSquares(n);
//    }
//};

//递归
//class Solution {
//private:
//    //计算平方数加和为n时,最少的平方数数量
//    int searchSquares(int n){
//        if( n == 0){
//            return 0;
//        }
//        int res = INT_MAX;
//        for (int i = 1; n - i*i >=0 ; ++i) {
//            res = min(res,searchSquares(n-i*i) + 1);
//        }
//        return res;
//    }
//public:
//    int numSquares(int n) {
//        return searchSquares(n);
//    }
//};

//class Solution {
//public:
//    //利用图的广度优先遍历
//    int numSquares(int n) {
//        // first - num  second - steps
//        //这个节点的数字 和 走了几步走到这个位置
//        queue<pair<int,int>> q;
//
//        vector<bool> visited(n+1,false);
//        q.push(make_pair(n,0));
//        visited[n] = true;
//        while (q.size()){
//            int num = q.front().first;
//            int step = q.front().second;
//            q.pop();
//
//            for (int i = 1;   ; ++i) {
//                int a = num - i*i;
//                if(a < 0)
//                    break;
//                if(a == 0)
//                    return step+1;
//                //把可以通过num减一次平方数到达的数字存入队列
//                if(!visited[a]){
//                    q.push(make_pair(a,step+1));
//                    visited[a] = true;
//                }
//            }
//        }
//
//    }
//};

#endif //LEETCODE_279_PERFECTSQUARES_H

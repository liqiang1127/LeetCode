//
// Created by liqiang on 2018/3/17.
//

#ifndef LEETCODE_KNAPACK01_H
#define LEETCODE_KNAPACK01_H

#include <iostream>
#include <vector>

using namespace std;


//定义f(n,c)状态为 将[0...n]中的物品放入容量为c的背包所能容纳的最大价值 并不是0到n所有的都放进去
//对于第i个物品 可以放可以不放
//状态转移方程 f(i,c) = max{ f(i-1,c) , v[i] + f(i-1,c-w[i]) }



//动态规划 优化2 只申请1行的空间 自后向前
//空间复杂度 O(2C) = O(C)
class Knaspack01{
public:
    int knaspack01(vector<int> &w,vector<int> &v,int C){
        int n = w.size();
        if(n==0)
            return 0;

        //只开辟一行空间 列数为容量+1
        vector<int> memo (C+1,-1);

        //初始化 i = 0 的情况
        for (int i = 0; i <= C ; ++i)
            memo[i] = ( i >= w[0] ? v[0] : 0);

        //从后向前的计算 f(i,c)
        for (int i = 1; i < n  ; ++i) {
            for (int j = C; j >= w[i] ; --j) {
                memo[j] = max(memo[j],v[j] + memo[j-w[i]]);
            }
        }
        return memo[C];
    }
};

//动态规划 优化1 只申请2行的空间
//空间复杂度 O(2C) = O(C)
//class Knaspack01{
//public:
//    int knaspack01(vector<int> &w,vector<int> &v,int C){
//        int n = w.size();
//        if(n==0)
//            return 0;
//        //行是物品编号  列是背包的容量
//        vector<vector<int>> memo = vector<vector<int>>(2,vector<int>(C+1,-1));
//
//        //对平凡子问题处理
//        //当 i = 0 只有0号物品的时候 考虑各种背包容量的情况
//        for (int j = 0; j <= C ; ++j) {
//            memo[0][j] = ( j >= w[0] ? v[0] : 0 );
//        }
//
//        for (int i = 1; i < n ; ++i) {
//            //考虑第i个物品
//            for (int j = 0; j <= C ; ++j) {
//                //从c = 0开始考虑
//                //后面可能要用到 j!=C 的数据 比如下一行
//                memo[i%2][j] = memo[(i-1)%2][j];
//                if( j >= w[i%2])
//                    max(memo[i%2][j], v[i%2] + memo[(i-1)%2][j-w[i%2]]);
//            }
//        }
//        return memo[(n-1)%2][C];
//    }
//};




// 0-1 动态规划
//时间复杂度 O(n*C)
//空间复杂度 O(n*C)
//class Knaspack01{
//public:
//    int knaspack01(vector<int> &w,vector<int> &v,int C){
//        int n = w.size();
//        if(n==0)
//            return 0;
//        //行是物品编号  列是背包的容量
//        vector<vector<int>> memo = vector<vector<int>>(n,vector<int>(C+1,-1));
//
//        //对平凡子问题处理
//        //当 i = 0 只有0号物品的时候 考虑各种背包容量的情况
//        for (int j = 0; j <= C ; ++j) {
//            memo[0][j] = ( j >= w[0] ? v[0] : 0 );
//        }
//
//        for (int i = 1; i < n ; ++i) {
//            //考虑第i个物品
//            for (int j = 0; j <= C ; ++j) {
//                //从c = 0开始考虑
//                //后面可能要用到 j!=C 的数据 比如下一行
//                memo[i][j] = memo[i-1][j];
//                if( j >= w[i])
//                    max(memo[i][j], v[i] + memo[i-1][j-w[i]]);
//            }
//        }
//        return memo[n-1][C];
//    }
//};


// 0-1 背包记忆化搜索
//class Knaspack01{
//private:
//
//    vector<vector<int>> memo;
//    //index - 当前考虑到第几个了
//    //用[0...index]的物品，填充容积为c的背包的最大价值
//    int bestValue(vector<int> &w,vector<int> &v,int c,int index){
//
//        //当没有物品 或者 没有容积了
//        if(index < 0  || c <= 0)
//            return 0;
//
//        //memo 由index c 共同确定 (重叠子问题)
//        if(memo[index][c] != -1){
//            return memo[index][c];
//        }
//
//        int res = bestValue(w,v,index-1,c) ;
//        if(c >= w[index])
//            res = max( res , v[index] + bestValue(w,v,c-w[index],index-1));
//        memo[index][c] = res;
//        return res;
//
//    }
//public:
//    int knaspack01(vector<int> &w,vector<int> &v,int C){
//        int n = w.size();
//        if(n==0)
//            return 0;
//
//        //行是物品编号  列是背包的容量
//        memo = vector<vector<int>>(n,vector<int>(C+1,-1));
//        return bestValue(w,v,C,n-1);
//    }
//};

#endif //LEETCODE_KNAPACK01_H

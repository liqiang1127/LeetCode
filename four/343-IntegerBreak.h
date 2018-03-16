//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_343_INTEGERBREAK_H
#define LEETCODE_343_INTEGERBREAK_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
public:
    int integerBreak(int n) {
        vector<int> memo = vector<int>(n + 1, -1);
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int res = -1;
            for (int j = 1; j <= i-1 ; ++j) {
                res = max3(res,j * (i-j), j * memo[i-j]);
            }
            memo[i] = res;
        }
        return memo[n];
    }
};

//class Solution {
//private:
//    vector<int> memo;
//    //分割n(至少分割2部分)产生的最大乘积
//    int breakInteger(int n){
//        //当n = 1 的时候无法分割成2部分 直接返回1
//        if( n == 1)
//            return 1;
//        if(memo[n] != -1)
//            return memo[n];
//        int res = -1;
//        for (int i = 1; i <= n-1; ++i) {
//            //从1~n-1 作为第一分割的数 进行递归
//            //由于我们函数的定义 至少分割两部分 所以要多考虑一种 i * (n-i)的情况
//            //res = max( res,i * breakInteger(n-i));
//            //以4为例 只比较2个数 2*2比2*f(2)大的出现错误
//            res = max3(res,i * (n - i), i*breakInteger(n-i));
//            memo[n] = res;
//        }
//        return res;
//    }
//
//    int max3(int a,int b,int c){
//        return max(a,max(b,c));
//    }
//
//public:
//    int integerBreak(int n) {
//        memo = vector<int>(n+1,-1);
//        return breakInteger(n);
//    }
//};


//class Solution {
//private:
//    //分割n(至少分割2部分)产生的最大乘积
//    int breakInteger(int n){
//        //当n = 1 的时候无法分割成2部分 直接返回1
//        if( n == 1)
//            return 1;
//        int res = -1;
//        for (int i = 1; i <= n-1; ++i) {
//            //从1~n-1 作为第一分割的数 进行递归
//            //由于我们函数的定义 至少分割两部分 所以要多考虑一种 i * (n-i)的情况
//            //res = max( res,i * breakInteger(n-i));
//            //以4为例 只比较2个数 2*2 是 比2*f(2)大的出现错误
//            res = max3(res,i * (n - i), i*breakInteger(n-i));
//        }
//        return res;
//    }
//
//    int max3(int a,int b,int c){
//        return max(a,max(b,c));
//    }
//
//public:
//    int integerBreak(int n) {
//        return breakInteger(n);
//    }
//};

#endif //LEETCODE_343_INTEGERBREAK_H

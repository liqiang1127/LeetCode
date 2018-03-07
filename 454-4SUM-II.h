//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_454_4SUM_II_H
#define LEETCODE_454_4SUM_II_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //算法思路：将C,D中的元素22组合 存入map中，再去AB循环，找加和为0的可能情况
    //为什么可以这么做？
    //1.N的规模不大 500 n^2 = 250,000 允许算法为n^2
    //2.只需要返回可能组合数目，不要求返回组合具体情况
    //空间复杂度 O(n^2) 时间复杂度 O(n^2)
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;//key-加和结果  value-次数
        for (int i = 0; i < C.size() ; ++i) {
            for (int j = 0; j < D.size(); ++j) {
                map[C[i]+D[j]]++;
                //加和为某个数 有多少种组合
            }
        }

        int count = 0;
        for (int i = 0; i < A.size() ; ++i) {
            for (int j = 0; j < B.size() ; ++j) {
                if(!(map.find(- A[i] - B[j]) == map.end())){
                    //找到了可能的组合
                    count+=map[-A[i]-B[j]];
                }
            }
        }

        return count;
    }
};

#endif //LEETCODE_454_4SUM_II_H

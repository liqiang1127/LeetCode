//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_447_NUMBEROFBOOMERANGS_H
#define LEETCODE_447_NUMBEROFBOOMERANGS_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//算法思路：从公共点i入手，分别计算别的点到这个点的距离，以距离作为key，存入map中，value计数
//如果到点i的距离为x的点有3个 i，j，k的点对可以有3*2个
class Solution {
private:
    //返回点之间距离，可能存在溢出
    int distance(pair<int,int> p1,pair<int,int> p2){
        return (p1.first - p2.first)*(p1.first - p2.first)
                + (p1.second - p2.second) * (p1.second - p2.second);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.size() < 3)
            return 0;

        int res = 0;
        for (int i = 0; i < points.size() ; ++i) {
            //以当前元素作为i点 计算其他点到这个点的距离 存入map
            unordered_map<int,int> map;
            for (int j = 0; j < points.size() ; ++j) {
                if(i!=j)
                    map[distance(points[i],points[j])]++;
            }
            for(auto val : map)
                res += val.second*(val.second-1);
        }
        return res;
    }
};
#endif //LEETCODE_447_NUMBEROFBOOMERANGS_H

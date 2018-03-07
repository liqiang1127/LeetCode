//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_149_MAXPOINTS_H
#define LEETCODE_149_MAXPOINTS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    struct Point {
        int x;
        int y;
        Point() : x(0), y(0) {}
        Point(int a, int b) : x(a), y(b) {}
    };

    //算法思路：以点为核心，枚举以该点为起点的向量，将向量作为key存入map value统计数量
    //两个目前不理解的地方：1.为什么处以最大公约数 可以判断共线 2.这里为什么不能用unorder_map
    int maxPoints(vector<Point>& points) {
        int maxCount = 0;//返回值
        //只有直接返回点的数目
        if(points.size() < 3)
            return points.size();

        for (int i = 0; i < points.size() ; ++i) {
            int localCount = 0;//除去sameCo和这个点本身以外的最多共线统计量
            int sameCo = 0;//统计坐标相同的不同点数目
            map<pair<int,int>,int> map;
            //找和i点共线的点
            for (int j = 0; j < points.size(); ++j) {
                if(i!=j){
                    //坐标相同的不同点肯定和这个点共线
                    if(points[i].x == points[j].x && points[i].y == points[j].y)
                        sameCo ++;
                    else{
                        int a = points[i].x - points[j].x;
                        int b = points[i].y - points[j].y;
                        int g = gcd(a,b);//向量
                        map[make_pair(a/g,b/g)] ++;
                        localCount = max(localCount,map[make_pair(a/g,b/g)]);
                    }
                }
            }
            //比较最多和i共线 + i本身 + 坐标相同
            maxCount = max(localCount + sameCo + 1,maxCount);
        }
        return maxCount;
    }
private:
    //求最大公约数
    int gcd(int a,int b){
        if(a < b)
            swap(a,b);
        while (b!=0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
#endif //LEETCODE_149_MAXPOINTS_H

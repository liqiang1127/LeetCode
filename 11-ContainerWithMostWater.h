//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_CONTAINERWITHMOSTWATER_11_H
#define LEETCODE_CONTAINERWITHMOSTWATER_11_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int A(vector<int>& height,int i,int j){
        int w = i > j ? i-j:j-i;
        int h = height[i] < height[j] ? height[i] : height[j];
        return w*h;
    }
public:
    int maxArea(vector<int>& height) {
        //算法思路:当双指针在运动过程中，底是在缩小的 而且缩小的单位都是1
        //所以我们每次舍弃较短的高（动态规划）
        int l=0,r=height.size()-1;
        int ret = 0;
        while (l < r){
            int temp = A(height,l,r);
            if(temp > ret)
                ret = temp;
            if(height[l] < height[r])
                l++;
            else{
                r--;
            }
        }
        return ret;
    }
};

#endif //LEETCODE_CONTAINERWITHMOSTWATER_11_H

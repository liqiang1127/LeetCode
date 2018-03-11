//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_KTHLARGESTELEMENT215_H
#define LEETCODE_KTHLARGESTELEMENT215_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Solution {
private:
    //闭区间 [l,r]
    int partition(vector<int>& nums,int l, int r){
        //设置随机标杆元素 防止算法退化成O(n)
        swap(nums[l],nums[rand()%(r-l+1)+l]);
        //选择标杆元素
        int v = nums[l];
        //[l+1,j] < v     [j+1,i-1] >= v
        int j = l;
        for (int i = l+1; i <= r  ; ++i) {
            if(nums[i] < v){//这里不能等于 等于会执行大量swap操作 降低性能 导致超时
                swap(nums[i],nums[++j]);
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Kth problem
        // 算法思路:每次快速排序的partition操作都会将标杆元素至于正确的位置 并返回其索引p
        // 通过比较 索引与传入的k的大小以及循环可以确定第k大元素
        srand(time(NULL));
        int p = partition(nums,0,nums.size()-1);
        //标记排好序以后第k大的元素应该出现的位置
        int f = nums.size() - k;
        while( p != f){
            if( p > f)
                //所求的索引在p的前面
                p = partition(nums,0,p-1);
            else{
                //所求的索引在p的后面
                p = partition(nums,p+1,nums.size()-1);
            }
        }
        return nums[p];
    }
};

#endif //LEETCODE_KTHLARGESTELEMENT215_H

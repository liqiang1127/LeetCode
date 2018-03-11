//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_MERGESORTEDARRAY88_H
#define LEETCODE_MERGESORTEDARRAY88_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        int res[m+n];
//        int i=0,j=0;//在nums1 和 nums2 里面的索引
//        int index = 0; //res中的索引
//
//        while (index < m+n){
//            if(i >= m){
//                res[index++] = nums2[j++];
//            }else if( j >= n){
//                res[index++] = nums1[i++];
//            }else if(nums1[i] < nums2[j]){
//                res[index++] = nums1[i++];
//            } else{
//                res[index++] = nums2[j++];
//            }
//        }
//        for (int k = 0; k < m+n ; ++k) {
//            nums1[k] = res[k];
//        }
//    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //从后往前考虑
        int i = m-1;//nums1的索引
        int j = n-1;//nums2的索引
        int index = m+n-1;//结果的索引
        while (index >= 0){
            if( i < 0){
                //nums1 遍历完了
                nums1[index--] = nums2[j--];
            }else if( j < 0){
                nums1[index--] = nums1[i--];
            }else if( nums1[i] > nums2[j]){
                nums1[index--] = nums1[i--];
            }else {
                nums1[  index--] = nums2[j--];
            }
        }
    }
};
#endif //LEETCODE_MERGESORTEDARRAY88_H

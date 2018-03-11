//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_INTERSECTION_349_H
#define LEETCODE_INTERSECTION_349_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //排序后
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int l=0,r=0;
        unordered_set<int> set;

        while ( l < nums1.size() && r < nums2.size()){
            if( nums1[l] == nums2[r]){
                set.insert(nums1[l]);
                l++;
                r++;
            } else if(nums1[l] > nums2[r]){
                r++;
            }else {
                l++;
            }
        }

        vector<int> res(set.begin(),set.end());
        return res;
    }
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        //标记
//        unordered_set<int> record(nums1.begin(),nums1.end());
//
//        unordered_set<int> resultSet;
//        for (int i = 0; i <nums2.size() ; ++i) {
//            if( record.find(nums2[i]) != record.end()){
//                resultSet.insert(nums2[i]);
//            }
//        }
//        vector<int> resulteVec(resultSet.begin(),resultSet.end());
//        return resulteVec;
//    }
};
#endif //LEETCODE_INTERSECTION_349_H

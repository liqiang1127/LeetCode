//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_INTERSECT_350_H
#define LEETCODE_INTERSECT_350_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       //排序以后用双索引

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int l=0,r=0;
        vector<int> res;

        while ( l < nums1.size() && r < nums2.size()){
            if(nums1[l] == nums2[r]){
                res.push_back(nums1[l]);
                l++;
                r++;
            } else if( nums1[l] > nums2[r]){
                r++;
            } else {
                l++;
            }
        }
        return res;
    }
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int,int> record;
//        for (int i = 0; i < nums1.size(); ++i) {
//            //c++中 没有的话 会自己insert 有的话直接更新
//            record[nums1[i]]++;
//        }
//
//        vector<int> resultVec;
//        for (int i = 0; i < nums2.size() ; ++i) {
//            if(record[nums2[i]] > 0){//这里不能用find 就算减到0 依然算找到了 但实际上这个元素不是并集中的元素了
//                resultVec.push_back(nums2[i]);
//                record[nums2[i]]--;
//            }
//        }
//        return resultVec;
//    }
};

#endif //LEETCODE_INTERSECT_350_H

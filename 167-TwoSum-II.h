//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H
#define LEETCODE_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//双指针对撞
class Solution {
public:
    //数组已经排好序了
    vector<int> twoSum(vector<int>& numbers, int target) {
        assert(numbers.size() >= 2);
        int l=0,r=numbers.size()-1;
        vector<int> vec;
        while (l < r){
            if(numbers[l]+numbers[r] == target){
                vec.push_back(l+1);
                vec.push_back(r+1);
                return vec;
            } else if(numbers[l]+numbers[r] < target)
                l++;
            else//  numbers[l]+numbers[r] > target
                r--;
        }
    }
};

#endif //LEETCODE_TWO_SUM_II_INPUT_ARRAY_IS_SORTED_H

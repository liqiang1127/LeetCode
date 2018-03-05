//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_MOVEZEROS_H
#define LEETCODE_MOVEZEROS_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0; //[0,k)存储所有非0元素
        for (int i = 0; i < nums.size() ; ++i) {
            if(nums[i]){
                if(i!=k)
                    swap(nums[i],nums[k++]);
                else
                    k++;
            }
        }

    }
};
#endif //LEETCODE_MOVEZEROS_H

//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_18_4SUM_H
#define LEETCODE_18_4SUM_H

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    //算法思路：排序后，确定2个数，在剩下的数中，使用指针对撞。参考twoSum
    //必要的减枝操作减少复杂度
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4)
            return res;

        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < n-3 ; ++i) {
            //相同元素跳过
            if(i>0&&nums[i]==nums[i-1]) continue;
            //如果当前的数 加上最大的3个数还小于target 进入下一次循环
            if(nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            //如果当前的数 加上紧接着的3个数 还大于target 退出循环 再怎么加也不可能比这个还小了
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            //此时默认选取了nums[i]这个数
            for (int j = i+1; j < n-2 ; ++j) {
                //同样的道理剪枝
                int target2 = target - nums[i];
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if(nums[j] + nums[n-2] + nums[n-1] < target2) continue;
                if(nums[j] + nums[j+1] + nums[j+2] > target2) break;
                int l = j+1,r=n-1;
                while (l < r){
                    int target3 = target2 - nums[j];
                    if(nums[l] + nums[r] == target3){
                        vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                        res.push_back(temp);
                        while ( l < r && nums[l] == temp[2])
                            l++;
                        while ( l < r && nums[r] == temp[3])
                            r--;
                    }else if(nums[l] + nums[r] < target3){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return res;
    }
};
#endif //LEETCODE_18_4SUM_H

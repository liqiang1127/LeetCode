//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_198_HOUSEROBBER_H
#define LEETCODE_198_HOUSEROBBER_H
//状态定义 记某个状态 [x...nums.size()) => 考虑偷窃x到size-1之间的房子
//x只是作为起点 不一定会去偷取x
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0)
            return 0;
        vector<int> memo(n,-1);
        //memo[i] 表示考虑抢劫 nums[0,i]所能获得的最大收益
        memo[0] = nums[0];
        for (int i = 1; i < n ; ++i) {
            for (int j = i; j >= 0 ; --j) {
                memo[i] = max(memo[i] , nums[j] + ( j-2 < 0 ? 0:memo[j-2]));
            }
        }
        return memo[n-1];
    }
};





//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        if( n == 0)
//            return 0;
//        //memo[i] 表示考虑抢劫 nums[i...n-1)所能获得的最大收益
//        vector<int> memo = vector<int>(n,-1);
//        memo[n-1] = nums[n-1];
//
//        for (int i = n - 2; i >= 0 ; --i) {
//            //memo[i]
//            for (int j = i; j < n ; ++j) {
//                memo[i] = max(memo[i], nums[j] + ( j+2 < n ? memo[j+2] : 0));
//            }
//        }
//        return memo[0];
//    }
//};


//class Solution {
//private:
//    vector<int> memo;
//    //考虑抢劫 [index...nums.size())这个范围的房子
//    int tryRob(vector<int> &nums,int index){
//        //没有房子可以偷了
//        if(index >= nums.size())
//            return 0;
//
//        if(memo[index] != -1)
//            return memo[index];
//        int res = -1;
//        for (int i = index; i < nums.size() ; ++i) {
//            res = max(res,nums[i] + tryRob(nums,i+2));
//        }
//        memo[index] = res;
//        return res;
//    }
//public:
//    int rob(vector<int>& nums) {
//        memo = vector<int>(nums.size(),-1);
//        return tryRob(nums,0);
//    }
//};

#endif //LEETCODE_198_HOUSEROBBER_H

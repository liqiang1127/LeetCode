//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_HAPPYNUMBER_202_H
#define LEETCODE_HAPPYNUMBER_202_H

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int nextNumber(int n){
        int sum = 0;
        while (n!=0){
            int p = n % 10;
            n = n / 10;
            sum+=p*p;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n!=1){
            if(set.find(n) != set.end()){
                //出现一个重复的数字说明出现循环了 但是没有1出现 退出
                return false;
            }else {
                set.insert(n);
            }
            n = nextNumber(n);
        }
        return true;
    }
};
#endif //LEETCODE_HAPPYNUMBER_202_H

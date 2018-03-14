//
// Created by liqiang on 2018/3/12.
//

#ifndef LEETCODE_401_BINARYWATCH_H
#define LEETCODE_401_BINARYWATCH_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    //解题思路：先分别计算小时灯亮i个 分钟灯亮num-i个的各种情况 再组合
    //原型：组合问题 不需要used标记 它是按顺序从前往后的过程
private:
    vector<int> hours{1,2,4,8};
    vector<int> minutes{1,2,4,8,16,32};

    //n - 要选多少个 light-对应的亮灯数组 p-存放结果 count-累计已经选择的等的数量从0开始 sum-累加器
    void generateTimes(int n,int start,int sum,int count,vector<int> lights,vector<int> &p){
        if(count == n){
            //已经挑选了n个 把组合结果存入p中
            p.push_back(sum);
            return;
        }
        //相当于在lights.size里面选n个灯形成组合
        for (int i = start; i <lights.size(); ++i) {
            sum+=lights[i];
            generateTimes(n,i+1,sum,count+1,lights,p);
            sum-=lights[i];
        }
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if(num == 0){
            res.emplace_back("0:00");
            return res;
        }
        vector<int> hVec;
        vector<int> mVec;
        for (int i = 0; i <= num ; ++i) {
            if(i > 4) {
                break;
            }
            hVec.clear();
            mVec.clear();
            generateTimes(i,0,0,0,hours,hVec);
            generateTimes(num-i,0,0,0,minutes,mVec);
            for(int hs : hVec){
                if( hs > 11) continue;
                for(int ms : mVec){
                    if( ms > 59) continue;
                    string mTime = ms > 9? to_string(ms) : "0"+to_string(ms);
                    string time  = to_string(hs) +":"+ mTime;
                    res.push_back(time);
                }
            }
        }
        return res;
    }
};
#endif //LEETCODE_401_BINARYWATCH_H

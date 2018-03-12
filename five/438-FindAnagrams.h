//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_FINDANAGRAMS_H
#define LEETCODE_FINDANAGRAMS_H

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;//储存结果
        if(s.size() == 0)
            return res;

        //以下处理
        //s是源字母 p是目标字母
        int l = 0,r = -1;//[l,r]滑动窗口
        int diff = p.size(); //标识差异度
        //当差异度 == 0 && 元素个数 == p.size() 认为这个子串是一个解
        //统计词频(hash)
        int feq[256] = {0};
        //s为空 直接返回

        for (int i = 0; i < p.size() ; ++i) {
            feq[p[i]] ++;
        }

        while ( r+1 < s.size() ){
            r++;
            if(feq[s[r]] > 0)
                diff--;
            feq[s[r]] -- ;
            if(diff == 0)
                res.push_back(l);
            if(p.length() == r-l+1){
                //当feq >=0 认为我们弹出了一个p中的元素
                if(feq[s[l]] >= 0)
                    diff++;
                feq[s[l]] ++;
                l++;
            }
        }
        return res;
    }
};

#endif //LEETCODE_FINDANAGRAMS_H

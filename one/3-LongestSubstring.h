//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_LONGESTSUBSTRING_3_H
#define LEETCODE_LONGESTSUBSTRING_3_H

#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};//统计字符频率
        int l = 0,r = -1;//[l,r]包含结果字符串
        int res = 0;//最长子串的长度
        while ( l < s.size() ){
            if( r+1 < s.size() && freq[s[r+1]] == 0)//第r+1位置的字母没有统计过
                //我们就r++ 把这个字母包含进去 并且更新字符频率
                //注意是先加 目的是 统计s[r+1]这个位置的频率
                freq[s[++r]] ++;
            else //r+1 这个位置的字母已经存在了 那么我们缩减 l
                freq[s[l++]] --;
            //这里为什么能直接max
            //进if分支 长度增加了 自然要更新res
            //如果进else分支 剔除了l位置 就算l位置不是r+1位置的字母 由于长度-1 res不变  进而直接进入下次循环
            res = max(res,r-l+1);
        }
        return res;
    }
};

#endif //LEETCODE_LONGESTSUBSTRING_3_H

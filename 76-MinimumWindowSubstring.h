//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_MINIMUMWINDOWSUBSTRING_76_H
#define LEETCODE_MINIMUMWINDOWSUBSTRING_76_H

#include <iostream>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        // s - source  t - target
        if(s.length() == 0 || t.length() > s.length()){
            return "";
        }

        //初始化
        int freq[256] = {0};
        for (int i = 0; i < t.size(); ++i) {
            freq[t[i]]++;
        }

        int l = 0,r = -1;//[l,r]为滑动窗口存储结果
        int len = s.size()+1; //初试长度 为 一个取不到大值
        int diff = t.size(); //差异度
        string res = "";

        while (r + 1 < s.size()){
            //先执行 ++r  再执行 freq ++
            if(freq[s[++r]]-- > 0)
                diff--;

            while ( diff == 0) {
                if (r - l + 1 < len) {
                    res = s.substr(l, r - l + 1);
                    len = res.size();
                }
                //先执行 freq ++
                //再执行 l ++
                if (freq[s[l++]]++ == 0)
                    diff++;
            }
        }
        return res;

    }


//     string minWindow(string s, string t) {
//         if (s.length() == 0 || t.length() > s.length()) {
//             return "";
//         }
//         // 初始化freq
//         int freq[256] = {0};
//         for (char c : t) { ++freq[c]; }
//
//         int l = 0, // 指向substring的左指针
//             h = 0,   // 指向substring的右指针
//             cnt = 0; // check whether the substring is valid
//
//         int len = INT_MAX; // substring的长度
//         string res = "";
//         while (h < s.length()) {
//             // 先移动h, 并相应减去freq的值
//             // 只要freq位置上的值大于0, 就说明符合条件(遇到了t中的字符, )
//             if (freq[s[h++]]-- > 0) { ++cnt; }
//
//             while (cnt == t.length()) {
//                 // 这里更新minimum的情况
//                 if (h - l < len) {
//                     res = s.substr(l, h - l);
//                     len = res.length();
//                 }
//                 // 这里移动l
//                 // 如果发现等于0, 则说明找回了一个t的字符, 那么cnt就减去. (因为+1后会大于0)
//                 if (freq[s[l++]]++ == 0) { --cnt; }
//             }
//         }
//         return res;
//     }
};

#endif //LEETCODE_MINIMUMWINDOWSUBSTRING_76_H

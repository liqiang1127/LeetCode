//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_REVERSESTRING_344_H
#define LEETCODE_REVERSESTRING_344_H

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int l=0,r=s.size()-1;
        while (l<r)
            swap(s[l++],s[r--]);
        return s;
    }
};

#endif //LEETCODE_REVERSESTRING_344_H

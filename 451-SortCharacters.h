//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_SORTCHARACTERS_451_H
#define LEETCODE_SORTCHARACTERS_451_H

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        unordered_map<char, int> hash;
        vector<string> vec(len+1, "");
        for(auto ch: s) hash[ch]++;
        //在vec[val.second]后面 val.second 次的 val.first
        for(auto val: hash) vec[val.second].append(val.second, val.first);
        string ans;
        for(int i = len; i > 0; i--)
            ans += vec[i];
        return ans;
    }
};
#endif //LEETCODE_SORTCHARACTERS_451_H

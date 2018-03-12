//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_SORTCHARACTERS_451_H
#define LEETCODE_SORTCHARACTERS_451_H

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
        // map key-sac码  value-字符出现的次数
        unordered_map<char, int> hash;
        //索引是字符出现的次数
        vector<string> vec(len+1, "");
        //分别统计每个字符出现的次数
        for(auto ch: s) hash[ch]++;
        //在vec[val.second]后面 val.second 次的 val.first
        //在vec对应的次数索引后面连字符串 这样出现次数同样字符就连接到一起了
        for(auto val: hash) vec[val.second].append(val.second, val.first);
        string ans;
        for(int i = len; i > 0; i--)
            ans += vec[i];
        return ans;
    }
};
#endif //LEETCODE_SORTCHARACTERS_451_H

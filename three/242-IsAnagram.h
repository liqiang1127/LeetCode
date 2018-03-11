//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_ISANAGRAM_242_H
#define LEETCODE_ISANAGRAM_242_H

#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<int,int> map;
        for (int i = 0; i < s.size() ; ++i) {
            map[s[i]]++;
        }

        for (int i = 0; i < t.size()  ; ++i) {
            map[t[i]]--;
            if(map[t[i]] < 0){
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODE_ISANAGRAM_242_H

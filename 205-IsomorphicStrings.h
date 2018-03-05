//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_ISOMORPHICSTRINGS_205_H
#define LEETCODE_ISOMORPHICSTRINGS_205_H

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //和290思路一样 注意一个value 映射 2个key就行了
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> map;
        unordered_set<int> set;

        if(s.size() != t.size())
            return false;
        if(s.size()==1)
            return true;

        for (int i = 0; i < s.size() ; ++i) {
            if(map.find(s[i]) != map.end()){
                //找到了这个key 比较内容
                if(map[s[i]] != t[i])
                    return false;
            } else {
                //没找到这个key
                if(set.find(t[i]) != set.end())
                    // 新的key对应了一个老的value 一对多 返回假
                    return false;
                map.insert(make_pair(s[i],t[i]));
                set.insert(t[i]);
            }
        }
        return true;
    }
};

#endif //LEETCODE_ISOMORPHICSTRINGS_205_H

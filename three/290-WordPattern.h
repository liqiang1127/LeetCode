//
// Created by liqiang on 2018/3/5.
//

#ifndef LEETCODE_WORDPATTERN_290_H
#define LEETCODE_WORDPATTERN_290_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;


class Solution {
private:
    vector<string> splitWithSpace(string s){
        vector<string> vec;
        int start = 0,end = 0;
        for (; end < s.size() ; ++end) {
            if(s[end]==' '){
                vec.push_back(s.substr(start,end - start));
                start = end+1;
            }
        }
        vec.push_back(s.substr(start,end - start));
        return vec;
    }
public:
    //注意 一个 value 匹配多个 key
    //测试用例
    //string pattern = "abba";
    //string s = "dog dog dog dog";
    //这里别让 a b都匹配了dog
    bool wordPattern(string pattern, string str) {
        vector<string> vec  = splitWithSpace(str);
        unordered_map<int,string> map;

        //set存放已经被匹配过得string
        unordered_set<string> set;

        //数目都不相等 直接返回假
        if(pattern.size() != vec.size())
            return false;


        for (int i = 0; i < pattern.size() ; ++i) {
            if(map.find(pattern[i]) != map.end()){
                //这个key出现过了 比较内容
                if(map[pattern[i]].compare(vec[i])){
                    return false;
                }
            }else{
                //这个key没出现过 绑定key和str
                //检查这个string 有没有被匹配过了 避免新的key 匹配到已经匹配过的string
                if(set.find(vec[i]) != set.end())
                    return false;
                map.insert(make_pair(pattern[i],vec[i]));
                set.insert(vec[i]);
            }
        }
        return true;
    }
};

#endif //LEETCODE_WORDPATTERN_290_H

//
// Created by liqiang on 2018/3/6.
//

#ifndef LEETCODE_49_GROUPANAGRAMS_H
#define LEETCODE_49_GROUPANAGRAMS_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    //算法思路：将string里面的字符按字典序排序后作为key存储 value为vector<string>
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>  res;
        unordered_map<string,vector<string>> map;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            //有就在后面插入
            //没有就创建空的再插入 这是c++的特性
            map[temp].push_back(str);
        }

        for(auto var : map)
            res.push_back(var.second);

        return res;
    }
//public:
//    //算法思路：利用质数数组 做hash 产生key
//    vector<vector<string>> groupAnagrams(vector<string>& strs) {
//        //26个字母 对26个质数
//        int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
//
//        vector<vector<string>> res;
//        unordered_map<int,int> map;//key-单词的hash码  value-这个单词所在的vector在res中索引
//        for(auto str : strs){
//            //计算key
//            int key = 1;
//            for(auto c:str){
//                key *= prime[c-'a'];
//            }
//            if(map.find(key) == map.end()){
//                //没找到这个key 说明里面没有它的同构单词
//                vector<string> vec;
//                vec.push_back(str);
//                map.insert(make_pair(key,res.size()));
//                res.push_back(vec);
//            }else {
//                //找到了这个key 就去取这个key对应的vector的索引
//                int index = map[key];
//                vector<string>* vec = &res[index];
//                vec->push_back(str);
//            }
//        }
//        return res;
//    }
};

#endif //LEETCODE_49_GROUPANAGRAMS_H

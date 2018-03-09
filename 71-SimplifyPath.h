//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_71_SIMPLIFYPATH_H
#define LEETCODE_71_SIMPLIFYPATH_H

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    vector<string> split(string s,char key){
        string temp ="";
        vector<string> ret;
        for (int i = 0; i < s.size() ; ++i) {
            if(s[i] != key){
                temp += s[i];
            } else {
                if(temp != ""){
                    ret.push_back(temp);
                    temp = "";
                }
            }
        }
        //把缓存的最后一个str压入 这样可能导致最后一个为""
        ret.push_back(temp);
        return ret;
    }
public:
    string simplifyPath(string path) {
        vector<string> strs = split(path,'/');
        stack<string> stack;

        for (auto str : strs) {
            if(str == ".." && stack.size()){
                stack.pop();
            }else{
                if(str == "." || str ==".." || str =="")
                    continue;
                else{
                    //能到这里一定是目录了
                    stack.push(str);
                }
            }
        }
        string ret = "";
        while (stack.size()){
            ret = "/" + stack.top() + ret;
            stack.pop();
        }
        return ret==""?"/":ret;
    }
};

#endif //LEETCODE_71_SIMPLIFYPATH_H

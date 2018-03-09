//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_20_VALIDPARENTHESES_H
#define LEETCODE_20_VALIDPARENTHESES_H

#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    //栈的基本使用
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                stack.push(s[i]);
            } else {
                //如果第一个就是右括号 那肯定是错的 坑
                if(!stack.size())
                    return false;
                //是右括号 待匹配
                char c = s[i];
                //c字符正确的匹配字符
                char match;
                if(c==')'){
                    match = '(';
                } else if(c==']'){
                    match = '[';
                }else{
                    match = '{';
                }
                char toMatch = stack.top();
                stack.pop();
                if(match != toMatch)
                    return false;
            }
        }
        //坑
        if(stack.size())
            return false;
        return true;
    }
};

#endif //LEETCODE_20_VALIDPARENTHESES_H

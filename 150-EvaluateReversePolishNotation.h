//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_150_EVALUATEREVERSEPOLISHNOTATION_H
#define LEETCODE_150_EVALUATEREVERSEPOLISHNOTATION_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    int stringToInt(string s){
        int ret = 0;
        int base = 1;
        bool neg = false;
        for (int i = s.size()-1; i >= 0 ; --i) {
            if(s[i] == '-')
                neg = true;
            else{
                int a = s[i]-'0';//获取数字
                ret = ret + a*base;
                base *= 10;
            }
        }
        return neg?-ret:ret;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for (int i = 0; i < tokens.size() ; ++i) {
            //判断是不是数字
            string str = tokens[i];
            if(str=="+" || str=="-" || str=="*" || str == "/"){
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                int res = 0;
                if(str=="+"){
                    res = a+b;
                }else if(str=="-"){
                    res = a-b;
                }else if(str=="*"){
                    res = a*b;
                }else{
                    res = a/b;
                }
                stack.push(res);
            }else{
                int num = stringToInt(tokens[i]);
                stack.push(num);
            }
        }
        return stack.top();
    }
};

#endif //LEETCODE_150_EVALUATEREVERSEPOLISHNOTATION_H

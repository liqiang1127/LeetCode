//
// Created by liqiang on 2018/3/3.
//

#ifndef LEETCODE_VALIDPALINDROME125_H
#define LEETCODE_VALIDPALINDROME125_H

#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    bool alphanumeric(char c){
        if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            return  true;
        return false;
    }

    bool equal(char c1,char c2){
        //大写在前面
        int dis = 'a' - 'A';
        if(c1==c2)
            return true;
        if((c1>='a'&&c1<='z')||(c1>='A'&&c1<='Z')){
            if((c1>='a'&&c1<='z')&&(c1-dis==c2))//c1 小写
                return true;
            else if(c1 + dis == c2)
                 return true;
        }
        return false;
    }

public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        while ( l < r ){
            while ( l < s.size() && !alphanumeric(s[l]) ) l++;
            while ( r >= 0 && !alphanumeric(s[r]) ) r--;
            if( l >= r)
                //可能整个串里面 没有一个字母数字 或者 只是在中间有一个 处理一下这种情况
                return true;
            if(!equal(s[l],s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

#endif //LEETCODE_VALIDPALINDROME125_H

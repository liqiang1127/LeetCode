//
// Created by liqiang on 2018/3/12.
//

#ifndef LEETCODE_131_PALINDROMEPARTITIONING_H
#define LEETCODE_131_PALINDROMEPARTITIONING_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    //vec 存放已经分割好的回文字符串
    void dfs(const string s,int start, vector<string> &vec){
        if(start == s.size()){
            res.push_back(vec);
            return;
        }

        for (int i = start; i < s.size() ; ++i) {
            string seg = s.substr(start,i-start+1);
            if(checkPalindrome(seg)){
                vec.push_back(seg);
                dfs(s,i+1,vec);
                vec.pop_back();
            }
        }
    }

    bool checkPalindrome(string s){
        int l = 0,r = s.size()-1;
        while ( l <= r){
            if(s[l] != s[r] )
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        if(s=="")
            return res;
        vector<string> vec;
        dfs(s,0,vec);
        return res;
    }
};
#endif //LEETCODE_131_PALINDROMEPARTITIONING_H

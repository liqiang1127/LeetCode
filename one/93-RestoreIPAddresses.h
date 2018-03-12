//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_93_RESTOREIPADDRESSES_H
#define LEETCODE_93_RESTOREIPADDRESSES_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> res;
    //s源字符串 index开始的索引 ip暂时储存结果的容器
    void dfs(const string &s,int index,vector<string> &ip){
        if(ip.size() == 4 && index == s.size()){
            res.push_back(ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3]);
            return;
        }
        //剪枝 剩余的字符太多了 多到剩下的每个ip部分都3位都不够 就返回
        if(s.size() - index > (4-ip.size())*3)
            return;
        //  同理太少了  每个一位都不够 也返回
        if(s.size() - index < 4-ip.size())
            return;

        int num = 0;
        for (int i = index; i < index+3 && i < s.size() ; ++i) {
            num = num*10 + (s[i]-'0');

            if( num > 255) break;

            //c++的substr 第一个参数是起始位置 第二个参数是长度（包括起始位置）
            string ipSeg = s.substr(index, i-index+1);
            ip.push_back(ipSeg);
            dfs(s,i+1,ip);
            //回溯的时候 把刚刚推进去的元素减掉
            ip.pop_back();

            if(num == 0) break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s=="")
            return res;
        vector<string> ip;
        dfs(s,0,ip);
        return res;
    }
};

#endif //LEETCODE_93_RESTOREIPADDRESSES_H

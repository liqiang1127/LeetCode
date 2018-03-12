//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_17_LETTERCOMBINATIONSPHONE_NUMBER_H
#define LEETCODE_17_LETTERCOMBINATIONSPHONE_NUMBER_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"


using namespace std;

class Solution {
private:
    const string latters[10]{
            " ",//0
            "",//1
            "abc",//2
            "def",//3
            "ghi",//4
            "jkl",//5
            "mno",//6
            "pqrs",//7
            "tuv",//8
            "wxyz"//9
    };
    vector<string> res;
    //s保存[0,index-1]的某个解
    //处理digits[index]位置的数字，和s组合成[0,index]的解
    //index标记当前做到数字的第几位了
    void findCombinations(const string &digits,int index, const string &s){
        if(index == digits.size()){
            //处理完成
            //保存结果s
            res.push_back(s);
            return;
        }
        char c = digits[index];//当前处理的数字
        string latter = latters[c-'0'];//当前处理的数字对应的字符串
        for (int i = 0; i < latter.size() ; ++i) {
            //挑一个字母
            findCombinations(digits,index+1,s+latter[i]);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits=="")
            return res;
        findCombinations(digits,0,"");
        return res;
    }
};

#endif //LEETCODE_17_LETTERCOMBINATIONSPHONE_NUMBER_H

//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_91_DECODEWAYS_H
#define LEETCODE_91_DECODEWAYS_H

#include <iostream>

using namespace std;


//"A" 1 "Z" 26
//"A"
class Solution {
public:
    int numDecodings(string s) {
        int length=s.size();
        if(length==0)
            return 0;

        int current=s[0]=='0'?0:1;
        int last=1;
        for(int i=1;i<length;i++)
        {
            int tmp=current;
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                    current=last;
                else
                    return 0;
            }
            else if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')
                current+=last;

            last=tmp;
        }

        return current;
    }
};

#endif //LEETCODE_91_DECODEWAYS_H

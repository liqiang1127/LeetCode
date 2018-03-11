//
// Created by liqiang on 2018/3/4.
//

#ifndef LEETCODE_REVERSEVOWELS_345_H
#define LEETCODE_REVERSEVOWELS_345_H

#include <iostream>
using namespace std;

class Solution {
private:
    bool vowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while ( true ){
            while ( l < s.size() && !vowel(s[l])) l++;
            while ( r >= 0 && !vowel(s[r])) r--;
            if( l >= r)
                break;
            swap(s[l],s[r]);
            r--;
            l++;
        }
        return s;
    }
};

#endif //LEETCODE_REVERSEVOWELS_345_H

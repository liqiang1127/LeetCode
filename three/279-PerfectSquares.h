//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_279_PERFECTSQUARES_H
#define LEETCODE_279_PERFECTSQUARES_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    //利用图的广度优先遍历
    int numSquares(int n) {
        // first - num  second - steps
        //这个节点的数字 和 走了几步走到这个位置
        queue<pair<int,int>> q;

        vector<bool> visited(n+1,false);
        q.push(make_pair(n,0));
        visited[n] = true;
        while (q.size()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1;   ; ++i) {
                int a = num - i*i;
                if(a < 0)
                    break;
                if(a == 0)
                    return step+1;
                //把可以通过num减一次平方数到达的数字存入队列
                if(!visited[a]){
                    q.push(make_pair(a,step+1));
                    visited[a] = true;
                }
            }
        }

    }
};

#endif //LEETCODE_279_PERFECTSQUARES_H

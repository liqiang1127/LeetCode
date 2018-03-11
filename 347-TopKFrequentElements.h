//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_347_TOPKFREQUENTELEMENTS_H
#define LEETCODE_347_TOPKFREQUENTELEMENTS_H

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //topK 问题
    //小根堆
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        //key-num value-time
        unordered_map<int,int> freq;
        //统计词频
        for (int i = 0; i < nums.size() ; ++i)
            freq[nums[i]]++;
        //创建优先队列 这里的pair first是词频 second是num  底层小根堆
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(auto pair : freq){
            if(q.size()==k){
                //优先队列已经满了
                if( pair.second > q.top().first){
                    q.pop();
                    q.push(make_pair(pair.second,pair.first));
                }
            }else{
                q.push(make_pair(pair.second,pair.first));
            }
        }
        while (q.size()){
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
};
#endif //LEETCODE_347_TOPKFREQUENTELEMENTS_H

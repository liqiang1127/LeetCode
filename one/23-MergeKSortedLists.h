//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_23_MERGEKSORTEDLISTS_H
#define LEETCODE_23_MERGEKSORTEDLISTS_H

#include "../ListNode.h"
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution {
private:
    struct cmp{
        bool operator()(ListNode* l1,ListNode* l2){
            return l1->val > l2->val;
        }
    };
public:
    //topK
    //小根堆
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //这个list只是包含头结点
        if( lists.size() == 0){
            return nullptr;
        }
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;

        for(auto node:lists){
            if(node)
                q.push(node);
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;

        while (q.size()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;

            //当前节点不是最后一个节点 把这个节点的后续节点放入队列 继续
            if(cur->next)
                q.push(cur->next);
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

#endif //LEETCODE_23_MERGEKSORTEDLISTS_H

//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_83_REMOVEDUPLICATES_H
#define LEETCODE_83_REMOVEDUPLICATES_H

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        //对这种情况[]处理
        if(!head)
            return head;

        //当前节点 还有后继节点
        while(cur->next){
            if(cur->val == cur->next->val){
                ListNode* next = cur->next;
                cur->next = next->next;
                delete next;
            }
            else
                cur = cur->next;
        }

        return head;
    }
};

#endif //LEETCODE_83_REMOVEDUPLICATES_H

//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_61_ROTATELIST_H
#define LEETCODE_61_ROTATELIST_H

#include "../ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)
            return head;

        ListNode* tail = head;
        int len = 1;
        //计算list的长度 并且获得len
        while (tail->next){
            tail = tail->next;
            len++;
        }
        //连接成环
        tail->next = head;

        if( k%=len){
            for (int i = 0; i < len - k ; ++i) {
                tail = tail->next;
            }
        }
        head = tail->next;
        tail->next = nullptr;
        return head;
    }
};

#endif //LEETCODE_61_ROTATELIST_H

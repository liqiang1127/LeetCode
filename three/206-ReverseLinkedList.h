//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_206_REVERSELINKEDLIST_H
#define LEETCODE_206_REVERSELINKEDLIST_H

#include <iostream>
#include "../ListNode.h"

using namespace std;


class Solution {
    //创建头结点
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;

        while (cur->next != NULL){
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return new_head->next;
    }
    //不创建头结点
//public:
//    ListNode* reverseList(ListNode* head) {
//        ListNode* pre = NULL;
//        ListNode* cur = head;
//
//        while (cur){
//            ListNode* next = cur->next;
//
//            cur->next = pre;
//            pre = cur;
//            cur = next;
//        }
//
//        return pre;
//    }
};

#endif //LEETCODE_206_REVERSELINKEDLIST_H

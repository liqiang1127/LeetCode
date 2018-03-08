//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_25_REVERSENODES_H
#define LEETCODE_25_REVERSENODES_H

#include<iostream>
#include "ListNode.h"

using namespace std;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;

        while (pre->next){
            ListNode* cur = pre->next;
            ListNode* dect = cur;//这个节点来检测余下的元素是否够k个
            for (int i = 0; i < k-1; ++i) {
                dect  = dect->next;
                if(dect == nullptr){
                    ListNode* retNode = dummyHead->next;
                    delete dummyHead;
                    return  retNode;
                }
            }
            //转置区间内的节点
            for (int i = 0; i < k-1 ; ++i) {
                ListNode* move = cur->next;
                cur->next = move->next;
                move->next = pre->next;
                pre->next = move;
            }
            pre = cur;
        }
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return  retNode;
    }
};

#endif //LEETCODE_25_REVERSENODES_H

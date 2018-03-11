//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_143_REORDERLIST_H
#define LEETCODE_143_REORDERLIST_H

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
private:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        //采用加入虚拟头结点法
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* cur = head;
        while (cur->next){
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = dummyHead->next;
            dummyHead->next = move;
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }

public:
    void reorderList(ListNode* head) {
        //head为空 只有一个元素 只有2个元素的时候直接返回
        if(!head || !head->next || !head->next->next)
            return;

        ListNode* pre = NULL;
        ListNode* fast = head;
        ListNode* slow = head;

        //难点是如何切分list
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;

        slow = reverse(slow);

        //merge 要求无返回值 原地merge
        ListNode* cur = head;
        //没到在最后一个
        while (cur->next){
            ListNode* node = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = node;
            cur = node;
        }
        cur->next = slow;
    }
};

#endif //LEETCODE_143_REORDERLIST_H

//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_82_REMOVEDUPLICATES_H
#define LEETCODE_82_REMOVEDUPLICATES_H
#include <iostream>
#include "../ListNode.h"

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head;

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        ListNode* cur = head;

        while (cur){
            ListNode* curN = cur->next;
            if(curN && curN->val == cur->val){
                //值相等，用curN找到下一个不一样的节点
                while (curN && curN->val == cur->val)
                    curN = curN->next;
                cur = curN;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};
#endif //LEETCODE_82_REMOVEDUPLICATES_H

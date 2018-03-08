//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_19_REMOVENTHNODEFROMEND_H
#define LEETCODE_19_REMOVENTHNODEFROMEND_H

#include <iostream>
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
//Given a linked list, remove the nth node from the end of list and return its head.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //滑动窗口
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for (int i = 0; i < n+1 ; ++i) {
            q = q->next;
        }
        while (q){
            q = q->next;
            p = p->next;
        }
        //p就是待删除节点的前面的节点
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};

#endif //LEETCODE_19_REMOVENTHNODEFROMEND_H

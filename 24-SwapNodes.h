//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_24SWAPNODES_H
#define LEETCODE_24SWAPNODES_H

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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* pre = dummyHead;

        while (pre->next && pre->next->next){
            ListNode* node1 = pre->next;
            ListNode* node2 = pre->next->next;
            ListNode* next = node2->next;

            //交换node1 node2
            node2->next = node1;
            node1->next = next;
            pre->next = node2;

            //维护循环不变量
            pre = node1;
        }
        ListNode* ret = dummyHead->next;
        delete dummyHead;
        return ret;
    }
};
#endif //LEETCODE_24SWAPNODES_H

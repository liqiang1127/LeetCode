//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_92_REVERSELINKEDLIST2_H
#define LEETCODE_92_REVERSELINKEDLIST2_H

#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    //206的变种
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //创建一个
        ListNode* new_head = new ListNode(0);
        new_head ->next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m-1; ++i) {
            pre = pre->next;
        }

        ListNode* cur = pre->next;
        for (int i = 0; i < n - m ; ++i) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }

        return new_head->next;
    }
};

#endif //LEETCODE_92_REVERSELINKEDLIST2_H

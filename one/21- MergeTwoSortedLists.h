//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_21_MERGETWOSORTEDLISTS_H
#define LEETCODE_21_MERGETWOSORTEDLISTS_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummyHead = new ListNode(0);

        ListNode* cur = dummyHead;
        ListNode* lcur = l1;
        ListNode* rcur = l2;

        while (lcur || rcur){
            if(lcur && rcur){
                if(lcur->val < rcur->val){
                    cur->next = lcur;
                    lcur = lcur->next;
                }else {
                    cur->next = rcur;
                    rcur = rcur->next;
                }
            }else if(lcur){
                cur->next = lcur;
                return dummyHead->next;
            }else {
                cur->next = rcur;
                return dummyHead->next;
            }
            cur = cur->next;
        }
//        cur->next = NULL;
        return dummyHead->next;
    }
};

#endif //LEETCODE_21_MERGETWOSORTEDLISTS_H

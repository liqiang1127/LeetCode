//
// Created by liqiang on 2018/3/2.
//

#ifndef LEETCODE_ADDTWONUMBERS_H
#define LEETCODE_ADDTWONUMBERS_H

#include <iostream>
#include <vector>

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
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool flag = false;//进位标识符
        ListNode *ret = new ListNode(0);
        ListNode *p = ret;
        while (l1 || l2 || flag){
            int sum = 0;
            if(flag){
                sum+=1;
            }
            int val1 = l1==NULL?0:l1->val;
            int val2 = l2==NULL?0:l2->val;
            sum = sum + val1 + val2;
            if(sum > 9){
                sum %= 10;
                flag = true;
            } else {
                flag = false;
            }
            p->next = new ListNode(sum);
            p = p->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        return ret->next;
    }
};

#endif //LEETCODE_ADDTWONUMBERS_H

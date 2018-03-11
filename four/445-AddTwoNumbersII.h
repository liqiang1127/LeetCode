//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_445_ADDTWONUMBERSII_H
#define LEETCODE_445_ADDTWONUMBERSII_H

#include <iostream>
#include "../ListNode.h"
#include <stack>

using namespace std;

class Solution {
public:
    //使用辅助的数据结构实现
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while (l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        stack<int> result;
        int flag = 0;
        while (s1.size() || s2.size() || flag){
            int val1=0,val2=0,sum=0;

            sum+=flag;

            if(s1.size()){
                val1 = s1.top();
                s1.pop();
            }
            if(s2.size()){
                val2 = s2.top();
                s2.pop();
            }

            sum = sum + val1 + val2;

            if(sum>=10){
                flag = 1;
                sum%=10;
            } else {
                flag = 0;
            }

            result.push(sum);
        }

        ListNode* res = new ListNode(0);

        ListNode* l = res;
        while (result.size()){
            l->next = new ListNode(result.top());
            l = l->next;
            result.pop();
        }

        return res->next;
    }
};

#endif //LEETCODE_445_ADDTWONUMBERSII_H

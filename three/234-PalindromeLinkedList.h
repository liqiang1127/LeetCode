//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_234_PALINDROMELINKEDLIST_H
#define LEETCODE_234_PALINDROMELINKEDLIST_H

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
private:
    ListNode* reverse(ListNode* head){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* cur = head;
        while (cur->next){
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = dummyHead->next;
            dummyHead->next = move;
        }

        ListNode* ret  = dummyHead->next;
        delete dummyHead;
        return ret;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;

        //快慢指针获取中点
        while( fast && fast->next ){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;

        slow = reverse(slow);

        while (head && slow){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }
};

#endif //LEETCODE_234_PALINDROMELINKEDLIST_H

//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_LISTHELPER_H
#define LEETCODE_LISTHELPER_H

#include "ListNode.h"

namespace ListHelper{
    ListNode* createList(int arr[],int n){
        //创建头结点
        ListNode* head = new ListNode(arr[0]);

        ListNode* cur = head;
        for (int i = 1; i < n ; ++i) {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }

    void printList(ListNode* head){
        ListNode* cur = head;
        while (cur){
            cout<<cur->val<<" -> ";
            cur = cur->next;
        }
        cout<<"NULL"<<endl;
        return;
    }

    void deleteList(ListNode* head){
        ListNode* cur = head;
        while (cur){
            ListNode* delNode = cur;
            cur = cur->next;
            delete delNode;
        }
        return;
    }
}
#endif //LEETCODE_LISTHELPER_H

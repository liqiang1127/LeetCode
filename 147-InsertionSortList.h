//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_147_INSERTIONSORTLIST_H
#define LEETCODE_147_INSERTIONSORTLIST_H

#include<iostream>
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        //这里并没有链接head
        ListNode* p = dummyNode;
        ListNode* cur = head;//当前需要排序的点
        ListNode* next = nullptr;//下一个需要排序的

        while (cur){
            //保存一下下一个位置  不然后面插入的时候 cur就找不到了
            next = cur->next;
            //找到需要插入的位置的前一个节点
            while ( p->next && p->next->val < cur->val){
                p = p->next;
            }


            //cur 为 head的时候 会独立出这个节点
            cur->next = p->next;
            p->next = cur;

            //将探测的p 放回原先的位置
            p = dummyNode;
            cur = next;
        }
        ListNode* ret = dummyNode->next;
        delete dummyNode;
        return ret;
    }
};

#endif //LEETCODE_147_INSERTIONSORTLIST_H

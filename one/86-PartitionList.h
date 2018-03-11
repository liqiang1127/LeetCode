//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_86_PARTITIONLIST_H
#define LEETCODE_86_PARTITIONLIST_H

#include <iostream>
#include "../ListNode.h"
using namespace std;
/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //最后要用这2个节点拼接返回
        ListNode* l = new ListNode(0);//存放小于x
        ListNode* r = new ListNode(0);//存放大于等于x

        ListNode* lc = l;
        ListNode* rc = r;

        //这样写会使每次都在l或者r后面连上一个串
        while (head){
            if(head->val < x){
                lc->next = head;
                lc = lc->next;
            }else{
                rc->next = head;
                rc = rc->next;
            }
            head = head->next;
        }
        rc->next = NULL;//这步极为重要 防止出现循环
        lc->next = r->next;
        return l->next;
    }
};
#endif //LEETCODE_86_PARTITIONLIST_H

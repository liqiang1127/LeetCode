//
// Created by liqiang on 2018/3/8.
//

#ifndef LEETCODE_237_DELETENODEINLINKEDLIST_H
#define LEETCODE_237_DELETENODEINLINKEDLIST_H

#include <iostream>
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
public:
    void deleteNode(ListNode* node) {
        if(!node)
            return;
        //node为最后一个元素
        if(!node->next){
            delete node;
            return;
        }

        node->val = node->next->val;

        //现在删除node后面的节点就行了

        ListNode* delNode = node->next;
        node->next = delNode->next;
        delete delNode;
        return;
    }
};

#endif //LEETCODE_237_DELETENODEINLINKEDLIST_H

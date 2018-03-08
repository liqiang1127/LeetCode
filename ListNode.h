//
// Created by liqiang on 2018/3/7.
//

#ifndef LEETCODE_LISTNODE_H
#define LEETCODE_LISTNODE_H

#include <iostream>
using  namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif //LEETCODE_LISTNODE_H

//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_100_SAMETREE_H
#define LEETCODE_100_SAMETREE_H

#include "../TreeNode.h"
#include <iostream>

using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p && q){
            bool l = isSameTree(p->left,q->left);
            bool r = isSameTree(p->right,q->right);
            bool cur = p->val == q->val;
            return l&r&cur;
        }
        //一个null 一个不是null 直接返回false
        return false;
    }
};

#endif //LEETCODE_100_SAMETREE_H

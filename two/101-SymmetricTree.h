//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_101_SYMMETRICTREE_H
#define LEETCODE_101_SYMMETRICTREE_H

#include <iostream>
#include "../TreeNode.h"

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
private:
    bool symmetric(TreeNode* p,TreeNode* q){
        //递归到底
        if(!p && !q)
            return true;
        else if(p && q){
            //都不是空 比较一下值
            if(p->val != q->val)
                return false;
            //值相等进而去比较子子树
            return symmetric(p->left,q->right) && symmetric(p->right,q->left);
        } else {
            //一个空一个不空
            return false;
        }

    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return symmetric(root->left,root->right);
    }
};

#endif //LEETCODE_101_SYMMETRICTREE_H

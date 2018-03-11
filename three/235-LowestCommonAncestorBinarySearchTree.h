//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_235_LOWESTCOMMONANCESTORBINARYSEARCHTREE_H
#define LEETCODE_235_LOWESTCOMMONANCESTORBINARYSEARCHTREE_H

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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //在二叉排序树种
        //当p q分布在root两端 或者 p或q 其中一个是root的情况下 就找到了公共祖先
        if(!root)
            return nullptr;
        //换句或说 p q 分布在同一侧 就还没找到答案
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }

        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }

        return root;

    }
};
#endif //LEETCODE_235_LOWESTCOMMONANCESTORBINARYSEARCHTREE_H

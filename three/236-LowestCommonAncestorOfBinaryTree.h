//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_236_LOWESTCOMMONANCESTOROFBINARYTREE_H
#define LEETCODE_236_LOWESTCOMMONANCESTOROFBINARYTREE_H

#include <iostream>
#include "../TreeNode.h"

using namespace;

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
    //235的改编 235是针对BST 这里是对于任何一个二叉树
    //这题没AC
private:
    //在以root为根的查找二叉树中是否有node节点
    bool contain(TreeNode* root,TreeNode* node){
        if(!root)
            return false;
        bool b = false;
        if(root->val == node->val)
            b = true;
        return b || contain(root->left,node) || contain(root->right,node);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        //如果一个在左子树 一个在右子树 就找到了
        if(p->val == root->val || q->val == root->val)
            return root;
        //先在左子树中找
        bool lp = contain(root->left,p);
        bool lq = contain(root->left,q);
        bool rp = contain(root->right,p);
        bool rq = contain(root->right,q);
        if(p->val != q->val){
            if(lp && rp){
                //有重复的p
                if(lq){
                    return lowestCommonAncestor(root->left,p,q);
                }
                return lowestCommonAncestor(root->right,p,q);
            }
            if(lq && rq){
                //有重复的q
                if(lp){
                    return lowestCommonAncestor(root->left,p,q);
                }
                return lowestCommonAncestor(root->right,p,q);
            }
        }
        if(lp && lq){
            //两个都是真的 都在左边
            return lowestCommonAncestor(root->left,p,q);
        }
        if(!lp && !lq){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};


#endif //LEETCODE_236_LOWESTCOMMONANCESTOROFBINARYTREE_H

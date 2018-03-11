//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_226_INVERTBINARYTREE_H
#define LEETCODE_226_INVERTBINARYTREE_H

#include "../TreeNode.h"
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
};
#endif //LEETCODE_226_INVERTBINARYTREE_H

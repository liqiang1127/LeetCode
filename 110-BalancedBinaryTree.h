//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_110_BALANCEDBINARYTREE_H
#define LEETCODE_110_BALANCEDBINARYTREE_H

#include <iostream>
#include "TreeNode.h"

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
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max(depth(root->left),depth(root->right))+1;

    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        bool lTree = isBalanced(root->left);
        bool rTree = isBalanced(root->right);
        if(!lTree || !rTree)
            return false;

        int lDepth = depth(root->left);
        int rDepth = depth(root->right);
        bool cur = lDepth > rDepth ? lDepth - rDepth <=1 : rDepth - lDepth <=1;

        return cur && lTree && rTree;
    }
};

#endif //LEETCODE_110_BALANCEDBINARYTREE_H

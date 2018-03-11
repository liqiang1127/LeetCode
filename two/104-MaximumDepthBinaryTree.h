//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_104_MAXIMUMDEPTHBINARYTREE_H
#define LEETCODE_104_MAXIMUMDEPTHBINARYTREE_H

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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

#endif //LEETCODE_104_MAXIMUMDEPTHBINARYTREE_H

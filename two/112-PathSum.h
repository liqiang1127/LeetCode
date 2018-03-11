//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_112_PATHSUM_H
#define LEETCODE_112_PATHSUM_H
#include<iostream>
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
    bool hasPathSum(TreeNode* root, int sum) {
        //注意是从根到叶子节点
        if(!root)
            return false;

        //这已经是一个叶子节点
        if(!root->left && !root->right)
            return root->val == sum;

        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

#endif //LEETCODE_112_PATHSUM_H

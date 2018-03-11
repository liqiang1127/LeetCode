//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_98_VALIDATEBINARYSEARCHTREE_H
#define LEETCODE_98_VALIDATEBINARYSEARCHTREE_H

#include <iostream>
#include "../TreeNode.h"
#include <vector>

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
    //二叉排序树中序遍历结果是一个递增的序列
    //利用了排序二叉树的性质
private:
    void helper(TreeNode* root,vector<int>&result)//中序遍历
    {
        if (root == NULL)
            return;
        helper(root->left, result);
        result.push_back(root->val);
        helper(root->right, result);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int>result;
        helper(root, result);
        for (int i = 0; i < result.size()-1; i++)
        {
            if (result[i]>=result[i + 1])
                return false;
        }
        return true;
    }
};
#endif //LEETCODE_98_VALIDATEBINARYSEARCHTREE_H

//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_437_PATHSUMIII_H
#define LEETCODE_437_PATHSUMIII_H

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
    //思路：分为包含root和不包含root
    //递归套递归
private:
    //在root为根的二叉树种寻找包含root和为sum的路径，返回路径个数
    int findPath(TreeNode* node,int num){
        if(!node)
            return 0;
        int res = 0;
        if(node->val == num)
            res += 1;

        res += findPath(node->left,num - node->val);
        res += findPath(node->right,num - node->val);
        return res;
    }
public:
    //在以root为根的二叉树种，寻找和为sum的路径，返回路径个数
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        //
        int res = 0;
        //包含root
        res += findPath(root,sum);
        //处理不包含
        res += pathSum(root->left,sum);
        res += pathSum(root->right,sum);

        return res;
    }
};

#endif //LEETCODE_437_PATHSUMIII_H

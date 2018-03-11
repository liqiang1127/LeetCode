//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_111_MINIMUMDEPTHBINARYTREE_H
#define LEETCODE_111_MINIMUMDEPTHBINARYTREE_H

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
//如果有一个孩子不为空 那么这个点就不是叶子节点
//        if(root->right && root->left){
//            int minDepthLeft = minDepth(root->left);
//            int minDepthRight = minDepth(root->right);
//            return min(minDepthLeft,minDepthRight)+1;
//        }else if(root->left){
//            return minDepth(root->left)+1;
//        }else{
//            return minDepth(root->right)+1;
//        }
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int minDepthLeft = minDepth(root->left);
        int minDepthRight = minDepth(root->right);
        //左右孩子都是空返回1
        if (!root->left && !root->right)
            return 1;
            //左右孩子都不空
        else if (root->left && root->right) {
            return min(minDepthLeft, minDepthRight) + 1;
        } else {
            //有一个为空
            return max(minDepthLeft,minDepthRight)+1;
        }
    }
};

#endif //LEETCODE_111_MINIMUMDEPTHBINARYTREE_H

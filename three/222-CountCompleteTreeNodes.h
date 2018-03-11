//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_222_COUNTCOMPLETETREENODES_H
#define LEETCODE_222_COUNTCOMPLETETREENODES_H

#include <iostream>
#include <cmath>
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int h1 = 0,h2 = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        //对子树是满二叉树的情况进行优化 避免超市导致无法AC
        while (l){
            h1++;
            l = l->left;
        }
        while (r){
            h2++;
            r = r->right;
        }
        if(h1==h2) return pow(2,h1)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

#endif //LEETCODE_222_COUNTCOMPLETETREENODES_H

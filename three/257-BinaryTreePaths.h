//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_257_BINARYTREEPATHS_H
#define LEETCODE_257_BINARYTREEPATHS_H

#include "TreeNode.h"
#include <iostream>
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;

        //兄弟到底了
        if(!root->left && !root->right){
            res.push_back(to_string(root->val));
            return res;
        }

        //没到底就去找子树的路径
        vector<string> lres = binaryTreePaths(root->left);
        for(auto s : lres){
            res.push_back( to_string(root->val) +"->" +s);
        }
        vector<string> rres = binaryTreePaths(root->right);
        for(auto s:rres){
            res.push_back(to_string(root->val) + "->" + s);
        }

        return res;
    }
};
#endif //LEETCODE_257_BINARYTREEPATHS_H

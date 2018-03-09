//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        //pair first-node指针 second-level
        queue<pair<TreeNode*,int>> q;

        q.push(make_pair(root,0));

        while (q.size()){
            TreeNode* node = q.front().first;
            int lv = q.front().second;
            q.pop();

            if(lv == res.size()){
                //新的一层
                res.push_back(vector<int>());
            }
            res[lv].push_back(node->val);

            //把子树的节点放进去
            if(node->left)
                q.push(make_pair(node->left,lv+1));
            if(node->right)
                q.push(make_pair(node->right,lv+1));
        }
        return res;
    }
};
#endif //LEETCODE_102_BINARYTREELEVELORDERTRAVERSAL_H

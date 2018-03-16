//
// Created by liqiang on 2018/3/16.
//

#ifndef LEETCODE_337_HOUSEROBBERIII_H
#define LEETCODE_337_HOUSEROBBERIII_H

#include "../TreeNode.h"
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
//深度优先遍历
class Solution {
    //如果选了root 那么2个子节点肯定不能选
    //如果没选root 那么2个子节点可选可不选
    //这个函数的意义是 求出node节点的数偷取的最大值  ret[0] 选择该节点 ret[0] 不选择该节点
    vector<int> getMoney(TreeNode* node) {
        vector<int> ret(2,0);
        if(!node)
            return ret;
        vector<int> left = getMoney(node->left);
        vector<int> right = getMoney(node->right);
        ret[0] = left[1] + right[1] + node->val;
        ret[1] = max(left[0],left[1]) + max(right[0],right[1]);
        return ret;
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = getMoney(root);
        return max(res[1],res[0]);
    }
};


#endif //LEETCODE_337_HOUSEROBBERIII_H

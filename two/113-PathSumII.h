//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_113_PATHSUMII_H
#define LEETCODE_113_PATHSUMII_H


#include <iostream>
#include "../TreeNode.h"
#include <vector>
#include <stack>
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
    //在以root为根的子树中寻找和为sum的路径 有的话就把序列放在vec中返回 （用栈 保证逆序）
    vector<stack<int>> getPath(TreeNode* node,int sum){
        vector<stack<int>> res;
        if(!node)
            return res;
        if(!node->left && !node->right){
            //叶子节点
            if(node->val == sum){
                stack<int> s;
                s.push(node->val);
                res.push_back(s);
                return res;
            } else{
                return res;
            }
        }
        vector<stack<int>> lvec = getPath(node->left,sum - node->val);
        if(!lvec.empty()){
            for(auto s : lvec){
                s.push(node->val);
                res.push_back(s);
            }
        }
        vector<stack<int>> rvec = getPath(node->right,sum - node->val);
        if(!rvec.empty()){
            for(auto s : rvec){
                s.push(node->val);
                res.push_back(s);
            }
        }
        return res;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<stack<int>> vstack = getPath(root,sum);
        for(auto s:vstack){
            vector<int> vec;
            while (!s.empty()){
                vec.push_back(s.top());
                s.pop();
            }
            ret.push_back(vec);
        }
        return ret;
    }
};
#endif //LEETCODE_113_PATHSUMII_H

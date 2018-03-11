//
// Created by liqiang on 2018/3/10.
//

#ifndef LEETCODE_404_SUMLEFTLEAVES_H
#define LEETCODE_404_SUMLEFTLEAVES_H

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
class Solution {
private:
    void leftLeaves(vector<int> &vec,TreeNode* l,TreeNode* r){
        //2个都是空 return掉
        if(!l && !r)
            return;

        //左节点不为空
        if(l){
            //左节点是叶子节点
            if(!l->left && !l->right){
                vec.push_back(l->val);
            }
            leftLeaves(vec,l->left,l->right);
        }

        //右节点不为空
        if(r){
            leftLeaves(vec,r->left,r->right);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int> vec;
        if(!root)
            return 0;
        leftLeaves(vec,root->left,root->right);
        int sum = 0;
        for(auto a : vec)
            sum+=a;
        return sum;
    }
};

#endif //LEETCODE_404_SUMLEFTLEAVES_H

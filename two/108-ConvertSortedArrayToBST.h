//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_108_CONVERTSORTEDARRAYTOBST_H
#define LEETCODE_108_CONVERTSORTEDARRAYTOBST_H

#include "../TreeNode.h"
#include <vector>
#include <iostream>

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
    //闭区间[l,r]
    //每次都挑中点 作为返回节点
    TreeNode* helper(vector<int>& nums,int l,int r){
        if(l > r){
            return nullptr;
        }
        int mid = l + (r-l)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums,l,mid-1);
        node->right = helper(nums,mid+1,r);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        return helper(nums,0,nums.size()-1);
    }
};
#endif //LEETCODE_108_CONVERTSORTEDARRAYTOBST_H

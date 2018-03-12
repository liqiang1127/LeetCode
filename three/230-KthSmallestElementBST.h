//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_230_KTHSMALLESTELEMENTBST_H
#define LEETCODE_230_KTHSMALLESTELEMENTBST_H

#include <iostream>
#include "../TreeNode.h"
#include <queue>
#include <vector>
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
    void inOrder(TreeNode* node,vector<int> &nums,int k){
        if(!node)
            return;
        if(nums.size() > k)
            return;
        inOrder(node->left,nums,k);
        nums.push_back(node->val);
        inOrder(node->right,nums,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root,nums,k);
        return nums[k-1];
    }
//private:
//    struct cmp{
//        bool operator()(TreeNode* node1,TreeNode* node2){
//            return node1->val < node2->val;
//        }
//    };
//
//    void travel(priority_queue<TreeNode*,vector<TreeNode*>,cmp> &q,TreeNode* root,int k){
//        if(!root)
//            return;
//        //先序遍历
//        if(q.size() == k){
//            if(root->val < q.top()->val){
//                //这个元素进堆
//                q.pop();
//                q.push(root);
//                travel(q,root->right,k);
//            }
//            travel(q,root->left,k);
//        } else {
//            q.push(root);
//            travel(q,root->right,k);
//            travel(q,root->left,k);
//        }
//
//
//    }
//public:
//    //有一种是中序遍历将数据存入数组,返回第k大 比较简单
//    //这里练习一下大根堆 堆的容量是k个 那么堆顶就是第k小的（其余的元素都小于大根堆的堆顶） 这个思路基本可以用于所有树
//    //这里最大堆里面放int就行了 为了练习自定义比较器 故意写了传node
//    int kthSmallest(TreeNode* root, int k) {
//        priority_queue<TreeNode*,vector<TreeNode*>,cmp> q;
//        travel(q,root,k);
//        return q.top()->val;
//    }
};

#endif //LEETCODE_230_KTHSMALLESTELEMENTBST_H

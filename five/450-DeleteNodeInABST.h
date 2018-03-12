//
// Created by liqiang on 2018/3/11.
//

#ifndef LEETCODE_450_DELETENODEINABST_H
#define LEETCODE_450_DELETENODEINABST_H

#include "../TreeNode.h"

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
    //在以node为根的子树中寻找最小的节点 返回最小的节点的指针
    TreeNode* miniNode(TreeNode* node){
        if(node->left == NULL){
            return node;
        }
        return miniNode(node->left);
    }
    //在以node为根的子树中删除最小的节点 返回删除该节点后子树的根
    TreeNode* removeMini(TreeNode* node){
        if(node->left == NULL){
            //这个就是我们要的删除的最小节点
            TreeNode* rightNode = node->right;
            delete node;
            return rightNode;
        }
        node->left = removeMini(node->left);
        return node;
    }
public:
    //在以root为根的树中寻找key并删除 返回子树的根
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val > key){
            //key 在左子树中
            root->left = deleteNode(root->left,key);
            return root;
        }else if (root->val < key){
            //key 在右子树中
            root->right = deleteNode(root->right,key);
            return root;
        }else{
            //root->val == key
            //找到了要删除的节点
            //如果这个节点不是左孩子右孩子都有 那么很好处理 把仅有的孩子接过来就行了
            //左节点为空
            if(!root->left){
                TreeNode* rightNode = root->right;
                delete root;
                return rightNode;
            }
            if(!root->right){
                TreeNode* leftNode = root->left;
                delete root;
                return leftNode;
            }

            //都不是空
            TreeNode* delNode = root;
            //在右子树寻找最小的节点作为后继 这个节点将作为根返回
            TreeNode* successorNode = new TreeNode(miniNode(root->right)->val);

            successorNode->left = root->left;
            successorNode->right = removeMini(root->right);

            delete delNode;
            return successorNode;
        }
    }
};

#endif //LEETCODE_450_DELETENODEINABST_H

//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_94_BINARYTREEINORDERTRAVERSAL_H
#define LEETCODE_94_BINARYTREEINORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <stack>
#include "../TreeNode.h"
using namespace std;



struct Command{
    bool op;//true go;false otherOperate
    TreeNode* node;
    Command(TreeNode* treeNode,bool f):op(f),node(treeNode){};
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        stack<Command> stack;
        stack.push(Command(root,true));

        while(stack.size()){
            Command c = stack.top();
            stack.pop();

            if(!c.op){
                //otherOperate
                res.push_back(c.node->val);
            }else{
                //go
                if(c.node->right)
                    stack.push(Command(c.node->right,true));
                stack.push(Command(c.node,false));
                if(c.node->left)
                    stack.push(Command(c.node->left,true));
            }
        }
        return res;
    }
};

#endif //LEETCODE_94_BINARYTREEINORDERTRAVERSAL_H

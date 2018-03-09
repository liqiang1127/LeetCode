//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_145_BINARYTREEPOSTORDERTRAVERSAL_H
#define LEETCODE_145_BINARYTREEPOSTORDERTRAVERSAL_H

#include "TreeNode.h"
#include <stack>
#include <vector>

using namespace std;

struct Command{
    bool op;//true go  false operate
    TreeNode* node;
    Command(TreeNode* treeNode,bool s):op(s),node(treeNode){};
};

class Solution {
public:
    //不用递归 用迭代
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;

        //模仿系统的栈
        stack<Command> stack;

        stack.push(Command(root,true));

        while (stack.size()){
            Command c = stack.top();
            stack.pop();

            if(!c.op){
                //print 指令
                res.push_back(c.node->val);
            }else{
                //go指令 将即将执行的指令入栈
                stack.push(Command(c.node, false));
                if(c.node->right)
                    stack.push(Command(c.node->right,true));
                if(c.node->left)
                    stack.push(Command(c.node->left,true));
            }
        }
        return res;
    }
};

#endif //LEETCODE_145_BINARYTREEPOSTORDERTRAVERSAL_H

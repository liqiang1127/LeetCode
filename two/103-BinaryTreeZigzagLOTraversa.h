//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_103_BINARYTREEZIGZAGLOTRAVERSA_H
#define LEETCODE_103_BINARYTREEZIGZAGLOTRAVERSA_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "../TreeNode.h"

using namespace std;

class Solution {
private:
    void reverse(vector<int> &vec){
        stack<int> stack;
        for (int i = 0; i < vec.size(); ++i) {
            stack.push(vec[i]);
        }
        for (int i = 0; i < vec.size() ; ++i) {
            vec[i] = stack.top();
            stack.pop();
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));

        while (q.size()){
            TreeNode* node = q.front().first;
            int lv = q.front().second;
            q.pop();

            if(lv == ret.size())
                ret.push_back(vector<int>());
            ret[lv].push_back(node->val);

            if(node->left)
                q.push(make_pair(node->left,lv+1));
            if(node->right)
                q.push(make_pair(node->right,lv+1));
        }

        //要reverse一下
        for (int i = 1; i < ret.size() ; i+=2) {
            reverse(ret[i]);
        }
        return ret;
    }
};

#endif //LEETCODE_103_BINARYTREEZIGZAGLOTRAVERSA_H

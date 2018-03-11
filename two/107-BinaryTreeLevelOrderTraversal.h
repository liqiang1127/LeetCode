//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_107_BINARYTREELEVELORDERTRAVERSAL_H
#define LEETCODE_107_BINARYTREELEVELORDERTRAVERSAL_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "../TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;

        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));

        while (q.size()){
            TreeNode* node = q.front().first;
            int lv = q.front().second;
            q.pop();

            if(lv == res.size())
                res.push_back(vector<int>());
            res[lv].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left,lv+1));
            if(node->right)
                q.push(make_pair(node->right,lv+1));
        }
        //系统自带 好慢
//        reverse(res.begin(),res.end());
        stack<vector<int>> stack;
        for(auto vec : res)
            stack.push(vec);
        for (int i = 0; i < res.size(); ++i) {
            res[i] = stack.top();
            stack.pop();
        }
        return res;
    }
};
#endif //LEETCODE_107_BINARYTREELEVELORDERTRAVERSAL_H

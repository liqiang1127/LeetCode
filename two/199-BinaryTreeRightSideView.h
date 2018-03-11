//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H
#define LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;

        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));

        while (q.size()){
            TreeNode* node = q.front().first;
            int lv = q.front().second;
            q.pop();

            if(lv == res.size())
                res.push_back(node->val);
            else
                //后面的会覆盖
                res[lv] = node->val;

            if(node->left)
                q.push(make_pair(node->left,lv+1));
            if(node->right)
                q.push(make_pair(node->right,lv+1));
        }
        return res;
    }
};
#endif //LEETCODE_199_BINARYTREERIGHTSIDEVIEW_H

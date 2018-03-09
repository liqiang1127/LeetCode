//
// Created by liqiang on 2018/3/9.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_TREENODE_H

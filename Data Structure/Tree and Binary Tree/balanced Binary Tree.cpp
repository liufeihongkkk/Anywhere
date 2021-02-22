//
// Created by hp on 2/7/2021.
//
/*
 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。*/
#include <bits/stdc++.h>
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
public:
    Solution(){flag=true;}
    bool flag;
    int maxlength(TreeNode *root){
        if(root==NULL)
            return 0;
        else
            return max(maxlength(root->left),maxlength(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root!=NULL&&abs(maxlength(root->left)-maxlength(root->right))>1)
            flag=false;
        isBalanced(root->left);
        isBalanced(root->right);
        if(flag==false)
            return false;
        else
            return true;
    }
};
int main(){
    Solution s;
    return 0;
}
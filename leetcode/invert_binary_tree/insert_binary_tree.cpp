/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr_node = q.front();
        TreeNode* tmp_node;
        while(!q.empty()){
            if(curr_node->left != NULL)
                q.push(curr_node->left);
            if(curr_node->right != NULL)
                q.push(curr_node->right);
            //switch lchild and rchild
            tmp_node = curr_node->left;
            curr_node->left = curr_node->right;
            curr_node->right = tmp_node;
            q.pop();
            curr_node = q.front();
        }
        return root;
    }
};
//
// Created by 宋腾 on 16/1/18.
//

#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H

# include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class binary_tree {
public:
    void BuildBinaryTree(){

    }

    int MaxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left_max_depth = MaxDepth(root->left);
        int right_max_depth = MaxDepth(root->right);
        return left_max_depth >= right_max_depth ? left_max_depth + 1 : right_max_depth + 1;
    }

    int BreadthFirstSearch(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr_node = q.front();
        TreeNode* tmp_node;
        while(!q.empty()){
            if(curr_node->left != NULL)
                q.push(curr_node->left);
            if(curr_node->right != NULL)
                q.push(curr_node->right);
            cout<<q.front()->val<<endl;
            q.pop();
            curr_node = q.front();
        }
        return 0;
    }
//广度优先遍历一遍树,交换每个节点的左右子
    int InvertBinaryTree(TreeNode * root){
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
        return 0;
    }
};


#endif //LEETCODE_BINARY_TREE_H

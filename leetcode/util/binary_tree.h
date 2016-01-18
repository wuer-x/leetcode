//
// Created by 宋腾 on 16/1/18.
//

#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H

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
    void build_binary_tree(){
        
    }

    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        return left_max_depth >= right_max_depth ? left_max_depth + 1 : right_max_depth + 1;
    }
};


#endif //LEETCODE_BINARY_TREE_H

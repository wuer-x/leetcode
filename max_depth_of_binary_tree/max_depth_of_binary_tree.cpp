//
// Created by 宋腾 on 16/1/18.
//
#include <stddef.h>
#include <iostream>
#include <string>
#include "../util/binary_tree.h"

using namespace std;


class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left_max_depth = maxDepth(root->left);
        int right_max_depth = maxDepth(root->right);
        return left_max_depth >= right_max_depth ? left_max_depth + 1 : right_max_depth + 1;
    }
};


int main() {
    TreeNode left(19);
    TreeNode right(22);
    TreeNode root(21);
    root.left = &left;
    root.right = &right;
    binary_tree s;
    s.BreadthFirstSearch(&root);
    s.InvertBinaryTree(&root);
    s.BreadthFirstSearch(&root);
//    cout<<s.MaxDepth(&root)<<endl;





    return 0;

}

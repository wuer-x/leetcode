//
// Created by 宋腾 on 16/1/18.
//

#include "binary_tree.h"

int main() {
    int a[4] = {10, 20, 30, 0};
    TreeNode *root_p = new TreeNode(10);
    binary_tree *b = new binary_tree();
    convertArrayToBinaryTree(a, 0, 3, root_p);
    b->BreadthFirstSearch(root_p);
    return 0;
}
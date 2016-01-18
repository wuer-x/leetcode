//
// Created by 宋腾 on 16/1/18.
//
#include <stddef.h>
#include <iostream>

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
    Solution s;
    cout<<s.maxDepth(&root)<<endl;


    return 0;

}

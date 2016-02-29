//
// Created by 宋腾 on 16/2/1.
//
#include <stddef.h>
#include <queue>
#include "../util/binary_tree.h"

using namespace std;

/*

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) :val(x), left(NULL), right(NULL){}
};
*/

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> q_q;
        queue<TreeNode *> q_p;
        q_p.push(p);
        q_q.push(q);

        while ((!q_q.empty()) && (!q_p.empty())) {
            TreeNode *current_q = q_q.front();
            TreeNode *current_p = q_p.front();
            q_q.pop();
            q_p.pop();

            if (current_q == NULL && current_q == NULL) {
                continue;
            }
            else if (current_q != NULL && current_p != NULL && current_q->val == current_p->val) {
                q_q.push(current_q->left);
                q_q.push(current_q->right);

                q_p.push(current_p->left);
                q_p.push(current_p->right);
            }
            else {
                return false;
            }
        }

        return q_q.size() == q_p.size();
    }
};


int main() {
    int a[1] = {1};
//    int b[0] = {};

    TreeNode *p = new TreeNode(1);
    TreeNode *q = NULL;
//    TreeNode *q = new TreeNode(0);

    convertArrayToBinaryTree(a, 0, 4, p);
//    convertArrayToBinaryTree(b,0,4,q);

    Solution s;
    cout << boolalpha << s.isSameTree(p, q) << endl;


    return 0;
}

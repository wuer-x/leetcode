//
// Created by 宋腾 on 16/1/8.
//

#include <vector>
#include <iostream>
#include <iterator>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int main(){
//    TreeNode * root = new TreeNode(0);
    queue<int> v;

    cout<<to_string(v.size())<<endl;
    return 0;

}


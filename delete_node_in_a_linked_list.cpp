# define PI 3.15


#include <stddef.h>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {

    }
};

int main(){
    cout<<to_string(PI)<<endl;
    
    return 0;
}
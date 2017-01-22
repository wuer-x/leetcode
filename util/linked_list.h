//
// Created by 宋腾 on 16/1/26.
//

#ifndef LEETCODE_LINKED_LIST_H
#define LEETCODE_LINKED_LIST_H

#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class LinkedList{
public:
    void initLinkedList(vector<int>& nums, ListNode * head){
        ListNode * curr_last_node = head;

        for(vector<int>::iterator iter = nums.begin() ; iter != nums.end(); iter++){
            ListNode *tmp_node = new ListNode(*iter);
            curr_last_node->next = tmp_node;
            curr_last_node = tmp_node;
        }

    }
};

#endif //LEETCODE_LINKED_LIST_H

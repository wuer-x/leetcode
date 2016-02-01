//
// Created by 宋腾 on 16/1/26.
//

#include <iostream>
#include <vector>
#include "../util/linked_list.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end();)
        {
            if(*iter == val)
                nums.erase(iter);
            else
                ++iter;
        }
        return nums.size();
    }
};


int main(){

    vector<int> v ;
    v.assign(1,10);

    ListNode * head = new ListNode(0);
    LinkedList ll;
    ll.initLinkedList(v,head);

    cout<<"end of foo!"<<endl;


    return 0;
}


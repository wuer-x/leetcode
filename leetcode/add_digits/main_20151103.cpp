//
//  main.cpp
//  leetcode
//
//  Created by 宋腾 on 15/10/10.
//  Modified by 宋腾 on 15/11/03.
//  Add digit root
//  Copyright © 2015年 宋腾. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int rst = 0;
        rst = 1 + ((num - 1) % 9);
        return rst;
    }
};


int main(){
    Solution s ;
//    int i = 1;
    cout<<s.addDigits(22)<<endl;
    return 1;
}

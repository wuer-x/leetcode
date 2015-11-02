//
//  main.cpp
//  leetcode
//
//  Created by 宋腾 on 15/10/10.
//  Copyright © 2015年 宋腾. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int rst = 0;
        do{
            do{
                rst += num % 10;
                num = num / 10;
            }while (num != 0);
            num = rst;
            rst = 0;
        }while(num >= 10);
        return num;
    }
};


int main(){
    Solution s ;
//    int i = 1;
    cout<<s.addDigits(4294967295/2)<<endl;
    return 1;
}

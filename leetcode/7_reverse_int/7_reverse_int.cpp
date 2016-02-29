//
// Created by 宋腾 on 16/2/28.
//

#include<iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long rst = 0;
        int input = x;

        while (input != 0) {
            rst = input % 10 + rst * 10;
            if (abs(rst) > (2147483644)) {
                return 0;
            }
            input = input / 10;
        }


        return (int) rst;
    }
};


int main() {
    Solution *s = new Solution();
    cout << s->reverse(-0) << endl;

    return 0;
}
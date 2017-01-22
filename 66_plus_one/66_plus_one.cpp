//
// Created by 宋腾 on 16/2/29.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int>::iterator it;
        bool is_9 = true;
// is like 999999
        for (it = digits.begin(); it != digits.end(); it++) {
            if (*it != 9) {
                is_9 = false;
                break;
            }
        }

        if (is_9) {
            digits.insert(digits.begin(), 1);
            for (it = digits.begin() + 1; it != digits.end(); it++) {
                *it = 0;
            }
            return digits;
        }


//other conditions
        int length = (int) (digits.size() - 1);
        int curr_pos = length;
        if (digits[curr_pos] != 9) {
            digits[curr_pos] += 1;
            return digits;
        }
        else {
            while (curr_pos - 1 >= 0 && digits[curr_pos] == 9) {
                digits[curr_pos] = 0;
                digits[curr_pos - 1]++;
                curr_pos--;
            }
            return digits;
        }
    }
};

int main() {

    vector<int> input;
    input.push_back(8);
    input.push_back(9);
    input.push_back(9);

    Solution *s = new Solution();
    input = s->plusOne(input);

    vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); it++) {
        cout << *it;
    }

    return 0;
}
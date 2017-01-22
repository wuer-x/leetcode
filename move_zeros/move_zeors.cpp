//
// Created by 宋腾 on 16/1/26.
//
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int or_size = (int) nums.size();
        //如果写作        for(vector<int>::iterator iter = nums.begin();iter != nums.end() ;++iter){ ,报错
        for(vector<int>::iterator iter = nums.begin();iter != nums.end() ;){
            if(*iter == 0){
                nums.erase(iter);
            }
            else
                ++iter;
        }
        int curr_size = (int) nums.size();
        for(int i = curr_size ; i< or_size ;i++){
            nums.push_back(0);
        }
    }
};


int main(){

    vector<int> v ;
    v.push_back(0);
    v.push_back(2);
    for(vector<int>::iterator iter = v.begin();iter != v.end();++iter)
    {
        cout<<*iter<<endl;
        if(*iter == 2)
            v.erase(iter);
/*
        else
            iter++;
*/
    }
    Solution s;
    s.moveZeroes(v);

    return 0;
}
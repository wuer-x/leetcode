#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> rst = {0,0};



    return rst;
  }
};


void show_vector(vector<int>& nums){
  for(int elem : nums){
    cout<<elem<<endl;
  }
  cout<<"return"<<endl;
}



int main(){
  vector<int> nums = {2, 7, 11, 15};
  cout<<(find(nums.begin(), nums.end(), 2) != nums.end())<<endl;
  // show_vector(nums);
  return 0;
}

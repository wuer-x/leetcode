#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() <= 1) return (nums.empty()?0:nums[0]);
        
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0],nums[1]));

        for(int i = 2;i<nums.size();i++){
#cout<<"i is: "<<i<<endl;
#cout<<"push_back is: "<<max(nums[i]+dp[i-2], dp[i-1])<<endl<<endl;
            dp.push_back(max(nums[i]+dp[i-2],dp[i-1]));
        }

        return dp.back();

    }

};

int main(){
    int a[]  = {12,2345,12,343434,1,2,2,3,4,54};
    vector<int> nums ;
    for(int i = 0  ; i < 10 ;i++){
        nums.push_back(a[i]);
    }
    Solution * s = new Solution();
    
    cout<<s->rob(nums)<<endl;
}
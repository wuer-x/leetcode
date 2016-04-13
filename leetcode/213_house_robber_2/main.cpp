#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        int the_previous_sum = max(nums[1],nums[0]);
        int the_first_two_sum = nums[0];

        int first_value_robbed_previous = nums[0] > nums[1]?1:0 ;
        int first_value_robbed_first_two = 1;

        int length_nums = nums.size();
        int tmp_exchange_value = 0;

        if(length_nums > 3) {
        
        for(int i = 2; i < length_nums - 1 ;i++){
            printf("the previous sum is : %d, the first two sum is: %d\n",the_previous_sum, the_first_two_sum);
            printf("is the first house robbed: %d , %d \n", first_value_robbed_first_two, first_value_robbed_previous);
            if( the_previous_sum > the_first_two_sum + nums[i]){
                the_first_two_sum = the_previous_sum;
                first_value_robbed_first_two = first_value_robbed_previous;
            }
            else if(the_previous_sum < the_first_two_sum + nums[i]){
                //exchange value
                tmp_exchange_value = the_previous_sum;
                the_previous_sum = the_first_two_sum + nums[i];
                the_first_two_sum  = tmp_exchange_value;

                //update flag of the first house robbed
                tmp_exchange_value = first_value_robbed_previous;
                first_value_robbed_previous = first_value_robbed_first_two;
                first_value_robbed_first_two = tmp_exchange_value;
            }else{//equal
                first_value_robbed_previous = min(first_value_robbed_previous, first_value_robbed_first_two);
            }



        }
        }
        //do sth for the last value, check if first value is robbed.
        int rst = 0;
        if(nums[length_nums - 1] + the_first_two_sum > the_previous_sum){
            printf("first_value is robbed: %d, %d.\n", first_value_robbed_first_two, first_value_robbed_previous);
            if(first_value_robbed_first_two == 0){
                rst = nums[length_nums - 1] + the_first_two_sum;
            }
            else {
                rst = max(the_previous_sum,the_first_two_sum);
            }
            
        }else{rst = the_previous_sum;}

        return rst;
    }
};


int main(){
    //   int a[]  = {12,2345,12,343434,1,2,2,3,4,54};
    int a[]  = {4,3,2,10};
    
    
    vector<int> nums ;
    for(int i = 0  ; i < 4 ;i++){
        nums.push_back(a[i]);
    }
    Solution * s= new Solution();

    cout<<s->rob(nums)<<endl;

    return 0;
}
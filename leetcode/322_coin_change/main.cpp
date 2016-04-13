#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int coin_vector_size = coins.size();
        if(amount < coins[0] || amount > coins[coin_vector_size - 1]) return -1;

        
        
        

        
        
        cout<<coin_vector_size<<endl;
        return coin_vector_size;
            
    }
    
};

int main(){
    
    int a[]  = {2,3,4,10};


    vector<int> nums ;
    for(int i = 0  ; i < 4 ;i++){
        nums.push_back(a[i]);
            
    }
    Solution * s= new Solution();
    s->coinChange(nums,10);
    
    return 0;
}



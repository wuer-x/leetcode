#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
    void output_vector(vector<int> num){
        int size = num.size();
        for(int i = 0 ; i < size;i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
public:
    vector<int> countBits(int num) {

        vector<int> rst(num+1,0) ;
        
        rst[0]=0;
        if(num==0) return rst;
        rst[1] = 1;
        if(num==1) return rst;
        

        for(int i = 0 ; i<= num;i++){
            int update_index = pow(2,1)+i;
            for(int j = 1; update_index <= num;){

                if(rst[update_index] == 0){
                    printf("update_index is: %d and i is:%d and j is: %d\n",update_index,i,j);
                    rst[update_index] = rst[i] + 1;
                    output_vector(rst);
                }
                update_index = pow(2,++j)+i;
                    }
        }
        return rst;

    }
};

int main(){
    vector<int> nums ;

    Solution * s =  new Solution();
    nums = s->countBits(4);
    for(int i  = 0 ; i< nums.size() ;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
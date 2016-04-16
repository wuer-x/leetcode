#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int> > generate(int numRows){
        
        vector<int> curr_row;
        vector<vector<int> > rst;
        if(numRows == 0 ) return rst;
        curr_row.push_back(1);
        rst.push_back(curr_row);
        if(numRows == 1 ) return rst;
        for(int i = 1 ; i < numRows;i++){
            curr_row.clear();
            curr_row.push_back(1);
            for(int j = 1; j<i;j++){
                curr_row.push_back(rst[i-1][j-1] + rst[i-1][j]);
            }
            curr_row.push_back(1);

            rst.push_back(curr_row);
        }

        return rst;
    }

    void output(vector<vector<int> > nums){
        for(int i = 0 ;i < nums.size();i++){
            vector<int> curr_row = nums[i];
            for(int j =0 ; j < curr_row.size();j++){
                cout<<curr_row[j]<<" ";
            }

            cout<<endl;
        }
    }
};

int main(){
    vector<vector<int> > nums;
    Solution * s = new Solution();
    nums = s->generate(5);
    s->output(nums);
    

    return 0;
}
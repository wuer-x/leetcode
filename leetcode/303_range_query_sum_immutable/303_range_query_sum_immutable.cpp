# include <iostream>
# include <vector>

using namespace std;

class NumArray {

private:
    vector<int> sum_nums;
public:
    NumArray(vector<int> &nums) {
        if(nums.size()== 0) return;
        int index  = 0 ;
        sum_nums.push_back(nums[index++]);
        for(; index < nums.size();index++){
            sum_nums[index] = sum_nums[index-1] + nums[index];
        }
    }

    int sumRange(int i, int j) {
        if(i == 0){
            return sum_nums[j];
        }
        else {
            return sum_nums[j] - sum_nums[i-1];
        }
    }


};


int main(){

    int v1[13] = {-8261,2300,-1429,6274,9650,-3267,1414,-8102,6251,-5979,-5291,-4616,-4703};
    vector<int> nums ;
    for(int i = 0 ;  i< 13 ;i++){
        nums.push_back(v1[i]);
    }
    NumArray * na = new NumArray(nums);
cout<<na->sumRange(0,8)<<endl;
cout<<na->sumRange(4,5)<<endl;
cout<<na->sumRange(9,11)<<endl;
cout<<na->sumRange(2,11)<<endl;
cout<<na->sumRange(0,12)<<endl;
cout<<na->sumRange(9,12)<<endl;
cout<<na->sumRange(2,5)<<endl;
cout<<na->sumRange(0,9)<<endl;
cout<<na->sumRange(5,9)<<endl;
cout<<na->sumRange(0,1)<<endl;
cout<<na->sumRange(12,12)<<endl;
cout<<na->sumRange(6,7)<<endl;
cout<<na->sumRange(5,8)<<endl;
cout<<na->sumRange(1,1)<<endl;
cout<<na->sumRange(6,7)<<endl;
cout<<na->sumRange(10,11)<<endl;
cout<<na->sumRange(11,12)<<endl;
cout<<na->sumRange(7,8)<<endl;
cout<<na->sumRange(4,11)<<endl;
cout<<na->sumRange(8,9)<<endl;
cout<<na->sumRange(4,11)<<endl;
cout<<na->sumRange(2,9)<<endl;
cout<<na->sumRange(2,6)<<endl;
cout<<na->sumRange(11,12)<<endl;
cout<<na->sumRange(5,8)<<endl;
cout<<na->sumRange(11,11)<<endl;
cout<<na->sumRange(1,9)<<endl;
cout<<na->sumRange(12,12)<<endl;
cout<<na->sumRange(10,10)<<endl;
cout<<na->sumRange(4,7)<<endl;
cout<<na->sumRange(12,12)<<endl;
cout<<na->sumRange(8,10)<<endl;
cout<<na->sumRange(7,9)<<endl;
cout<<na->sumRange(4,7)<<endl;
cout<<na->sumRange(0,7)<<endl;
cout<<na->sumRange(8,9)<<endl;
cout<<na->sumRange(10,12)<<endl;
cout<<na->sumRange(0,9)<<endl;
cout<<na->sumRange(10,12)<<endl;
cout<<na->sumRange(7,12)<<endl;
cout<<na->sumRange(9,9)<<endl;
cout<<na->sumRange(0,12)<<endl;
cout<<na->sumRange(1,3)<<endl;
cout<<na->sumRange(8,8)<<endl;
cout<<na->sumRange(7,10)<<endl;
    return 0;
}

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
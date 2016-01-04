# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return 0;

    }

};

int main(){
    Solution s = new Solution();
    vector v = new vector();
    v.push_back(1);
    v.push_back(2);
    cout<<s.singleNumber(&v)<<endl;
    return 0;
}
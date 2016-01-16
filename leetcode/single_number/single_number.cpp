# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumberHashMap(vector<int> &nums) {
        unordered_map<int, int> int_hash;

        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
            int_hash[*iter] = (int_hash[*iter] == 1)?0:1;
        }
        for (unordered_map<int, int>::iterator iter = int_hash.begin(); iter != int_hash.end(); iter++) {
            if (iter->second == 1) {
                return iter->first;
            }
        }
        return 0;
    }

    int singleNumber(vector<int> &nums){
        int rst = 0;
        for(vector<int>::iterator iter = nums.begin();iter!=nums.end();++iter){
            rst ^= *iter;
        }

        return rst;
    }
};

int main() {
    Solution *s = new Solution();
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    //    vector<int>::iterator iter ;

/*
    for(iter=v.begin(); iter != v.end(); ++iter)
    {
        cout<<*iter<<endl;
    }
*/

    cout << s->singleNumber(v) << endl;
    return 0;
}
#include <iostream>

using namespace std;

class Solution{
public:
        bool canWinNim(int n){
                if(n%4==0)
                        return false;
                else
                        return true;
        }
};

int main(){
        Solution s;
        for(int i = 0 ;  i < 10 ;i++){
                cout<<s.canWinNim(i)<<endl;
        }
}

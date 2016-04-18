#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int max = 2;
        int min = 1;
        int tmp = max;
        if(n==0) return 0;
        if(n ==1) return min;
        if(n==2) return max;
        
        for(int i = 2;i<n;i++){
            tmp = max;
            max = min+tmp;
            min = tmp;
        }

        
        
        return max;
    }
    
};

int  main(){
    Solution * s  = new Solution();
    cout<<s->climbStairs(1);
    cout<<s->climbStairs(2);
    cout<<s->climbStairs(3);
    cout<<s->climbStairs(4);
    return 0;
}
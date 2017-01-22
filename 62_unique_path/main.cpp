#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int path_count[100][100] = {1};
        for(int i= 0 ;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j!=0){
                    path_count[i][j]=path_count[0][j-1];
                }
                else if(j==0 && i!=0){
                    path_count[i][j] = path_count[i-1][0];
                }
                else if(i !=0 && j != 0){
                    path_count[i][j] = path_count[i-1][j]+ path_count[i][j-1];
                }
            }
        }
        return path_count[m-1][n-1];
            
    }
    
};


int main(){
    Solution * s = new Solution();
    cout<<s->uniquePaths(99,99)<<endl;
    return 0;
}
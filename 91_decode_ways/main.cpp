#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int length_s = s.size();
        vector<int> rst(length_s,0);

        if(length_s ==0) return 0;
        else if(length_s ==1){
            if(!s.compare(0,1,"0"))
            {
                return 0;
            }

            else{
                return 1;
            }
        }

        else if(length_s == 2){
            if(s.substr(0,1)=="0") return 0;
            if(stoi(s) <= 26 && stoi(s) >=1){
                return 2;
            }
            else if(stoi(s)==0) return 0;
            else if(stoi(s)>26) return 1;
        }

        else{
            if(s.substr(0,1)=="0"){
                rst[0] = 0;
            }else{
                rst[0] = 1;
            }

            if(stoi(s.substr(0,2)) >= 1 && stoi(s.substr(0,2))<=26){
                rst[1] = 2;
            }
            else if(stoi(s.substr(0,2)) == 0){
                rst[1] = 0;
            }
            else if(stoi(s.substr(0,2)) > 26){
                rst[1] = 1;
            }

            for(int i =2;i<length_s;i++){
                if(s.substr(i-1,1)=="1" || (s.substr(i-1,1) == "2" && stoi(s.substr(i,1)) <= 6)){
                    rst[i] = rst[i-1] + 1;
                    
                }
                else rst[i] = rst[i-1];
            }
        }
        return rst[length_s - 1];
    }
};



int main(){

    Solution * s = new Solution();
    cout<<s->numDecodings("0");
    string st = "0";
    cout<<endl;
    cout<<st.substr(0,1)<<endl;
    cout<<st.compare(0,1,"0")<<endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    for(int i = 1 ; i <= n ; i++){
      cout<<to_string(i)<<endl;
    }
  vector<string> rst;
  rst.push_back("nimei");
  return rst;
  }
};

int main(){
  Solution * s  = new Solution;

  s->fizzBuzz(10);

  return 0;
}

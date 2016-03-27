//
// Created by 宋腾 on 16/3/25.
//

#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 1000000;
bool arr[MAXN+1] = {false};


class Solution {
public:



    vector<int> produce_prim_number()
    {
        vector<int> prim;
        prim.push_back(2);
        int i,j;
        for(i=3; i*i<=MAXN; i+=2)
        {
            if(!arr[i])
            {
                prim.push_back(i);
                for(j=i*i; j<=MAXN; j+=i)
                    arr[j] = true;
            }
        }
        while(i<=MAXN)
        {
            if(!arr[i])
                prim.push_back(i);
            i+=2;
        }
        return prim;
    }

//计算n!中素因子p的指数
    int Cal(int x, int p)
    {
        int ans = 0;
        long long rec = p;
        while(x>=rec)
        {
            ans += x/rec;
            rec *= p;
        }
        return ans;
    }

//计算n的k次方对M取模，二分法
    int Pow(long long n, int k, int M)
    {
        long long ans = 1;
        while(k)
        {
            if(k&1)
            {
                ans = (ans * n) % M;
            }
            n = (n * n) % M;
            k >>= 1;
        }
        return ans;
    }

//计算C(n,m)
    int uniquePaths(int n, int m)
    {
        const int M = 10007;
        vector<int> prim = produce_prim_number();
        long long ans = 1;
        int num;
        for(int i=0; i<prim.size() && prim[i]<=n; ++i)
        {
            num = Cal(n, prim[i]) - Cal(m, prim[i]) - Cal(n-m, prim[i]);
            ans = (ans * Pow(prim[i], num, M)) % M;
        }
        return ans;
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->uniquePaths(3,2);

    return 0;
}


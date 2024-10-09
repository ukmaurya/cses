#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
const int mod = 1e9+7;
ll binaryExponentiation(ll a, ll b, int mod ){   
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    ll ans = 1;
    while(b){
        if(b&1){
            ans =( ans*a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}
#define m 1000000007
vector<vector<int>> matMul(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> ans = {{0, 0}, {0, 0}};
    
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                ans[i][j] = (ans[i][j] + (1LL * a[i][k] * b[k][j]) % m) % m;
            }
        }
    }
    return ans;
}
vector<vector<int>> mul(int n)
{
    vector<vector<int>> x = {{1, 1}, {1, 0}};
    vector<vector<int>> ans={{1, 0}, {0, 1}};
    while(n)
    {
        if(n&1)
        {
            ans=matMul(ans, x);
        }
        x=matMul(x, x);
        n/=2;
    }
    return ans;
}
int32_t main() {
    int n; 
    cin>>n;
    vector<vector<int>> ans=mul(n);
   cout<< ans[1][0]%mod;
}
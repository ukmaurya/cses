#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
const int N= 1e7;
vector<ll> fact(N+1);
vector<ll> invFact(N+1);
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
ll ncr(ll n , ll r){
    if(r<0 || r>n)
     return 0;
    ll req=0;
    req = ((fact[n]*invFact[r])%mod*invFact[n-r])%mod;
    return req;
}
int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     // based on burnside lema 
     int n,m;
     cin>>n>>m;
     ll ans=0;
     for(int i =0;i<n;i++){
        ans=( ans+ binaryExponentiation(m,__gcd(i,n),mod))%mod;
     }
     ans =  (ans*binaryExponentiation(n,mod-2,mod))%mod;     //    ans/n;
     cout<<ans;
 return 0;
}
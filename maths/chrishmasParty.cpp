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
    ll req=0;
    req = ((fact[n]*invFact[r])%mod*invFact[n-r])%mod;
    return req;
}
int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
     // calcultaion of factorial 
      fact[0]=1;
      
      for(int i=1;i<N;i++){
        fact[i]=(1LL*fact[i-1]*i)%mod;
      }
      // calculation of inverse factorial  
     
      invFact[N-1] = binaryExponentiation(fact[N-1] , mod-2 , mod);
      for(int i=N-2 ;i>=0;i--){
        invFact[i] = (((i+1)*1LL)*(invFact[i+1]%mod))%mod;
      }
      int n ;
      cin>>n;
     
      ll sec=0;
      for(int i=1;i<=n;i++){
        ll temp = (ncr(n,i)*fact[n-i])%mod*pow(-1,i+1);
        sec = (sec + temp )%mod;
      }
      ll ans = (fact[n]-sec+mod)%mod;
      cout<<ans;
 return 0;
}
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
      if(n&1){
        cout<<0;
        return 0;
      }
      string s ;
      cin>>s;
    // extension of previous problem  
     // these problem are bijection of grid path problem with some condition that movement 
     // do not exceed y=x;
      //https://www.youtube.com/watch?v=rKRuMzcPZkk

      int x=0; // x cordinate
      int y=0;  // y cordinate
      int t=0; // to handle sone corner cases  
      for(int i=0;i<s.size();i++){
        if(s[i]=='(')
         { t++;
           x++;
          }
        else 
        {  y++;  
           t--;
           }
        if(t<0){ // no of ) or right moves are grater than ( or left move 
            cout<<0;
            return 0;
        }   
      }

      n=n/2;
      if(x>n || y>n )
       {
        cout<<0;
        return 0;
       }
      ll ans = (ncr(2*n-x-y , n-x)%mod - ncr(2*n-x-y , n-1-x)%mod +mod)%mod; // all path - wrong path
      cout<<ans;

     

 return 0;
}
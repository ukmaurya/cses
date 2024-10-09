#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll binaryExponentiation(ll a, ll b, int mod ){  // valid when a,b,m <=10^9 
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
    return ans;
}
int main(){  
    int t;
    cin>>t;
    int mod = 1e9+7;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        // since mod = prime number , using eulers theorem
        cout<<binaryExponentiation(a,binaryExponentiation(b,c,mod-1),mod)<<endl;;

    }
  

}
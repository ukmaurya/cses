#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
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
    return ans%mod;
}
ll mul(ll x,ll y,ll modulo)
{
	return ((x%mod)*(y%mod))%modulo;
}
ll dividing(ll x,ll y){
    return mul(x,binaryExponentiation(y,mod-2,mod),mod)%mod;
}


int main(){
    //https://www.youtube.com/watch?v=uy_C8BkuN9w&t=1012s
     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
     ll n;
     cin>>n;
     ll sum=1;
     ll product=1;
     ll numDiv = 1;
     ll num = 1;
    ll count2=1;
     while(n--){
        ll p,x;
        cin>>p>>x;
       
        numDiv=mul(numDiv,(x+1),mod);
        // gp 
        ll numi =(binaryExponentiation(p,x+1ll,mod)-1ll+mod)%mod;
        ll dino = (p-1+mod)%mod;
        ll gp = dividing(numi , dino);
       sum = mul(sum,gp,mod);
       num = mul(num,binaryExponentiation(p,x,mod),mod);
       product =mul(binaryExponentiation(product,x+1,mod),binaryExponentiation(binaryExponentiation(p,x*(x+1)/2,mod),count2,mod),mod);
       count2= mul(count2,x+1,mod-1);//mod-1 since fermet little theorem 
       // count2 is showing no of divisors ie no of choices*prevnumbem of divisors 
     }
   
     cout<<numDiv<<endl<<sum<<endl<<product<<endl;

}
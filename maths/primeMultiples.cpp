#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
     ll n;
     int k;
     cin>>n>>k;
     vector<ll> prime(k);
     for(int i=0;i<k;i++){
        cin>>prime[i];
     }
     // using inlusion exclusion principle (set theory)
     
     // number of num till n which is divisible by x is x/n;
     vector<ll> num_of_div(k+1,0); // 1 based indexing , 3rd index means all 3 bit is set ie n/(Pi*Pj*Pk)
     for(int mask=1;mask<(1<<k);mask++){  //mask =0 does not mean any sense ie taking no prime numbers 
         
           ll temp = n;
          for(int i=0;i<k;i++){
            if(mask&(1<<i)){ 
               
                temp= temp/prime[i];
            }
          }
          int totalDivisor = __builtin_popcount(mask);
          num_of_div[totalDivisor] += temp;
      }
      ll ans =0;
      for(int i=1;i<=k;i++){
        if(i&1){
            ans += num_of_div[i];
        }
        else{
            ans -= num_of_div[i];
        }
      }
      cout<<ans<<endl;
    

 return 0;
}
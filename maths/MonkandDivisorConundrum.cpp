#include<bits/stdc++.h>
using namespace std;
const int n = 2e5+1;
int main(){
     vector<int> divCount(n,0);
     vector<int> hash(n,0); // stores the frequency of each element in the array 
     // precomputation 
    int input;
    cin>>input;
    for(int i=0;i<input;i++){
        int a;
        cin>>a;
        hash[a]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j=j+i){
            if(hash[i]!=0){ // means present in the array 
               divCount[i]+=hash[j];
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
       int p,q;
       cin>>p>>q;
       long long lcm  = (p*1LL*q)/__gcd(p,q); // long long since max number is 10^5 and it lcm may go bayong int 
        int ans = divCount[p]+divCount[q];
       if(lcm<n){
        ans-=divCount[lcm]; // lcm divisors will be counted twice

       }
       cout<<ans<<endl;
    }
   
   return 0;
}
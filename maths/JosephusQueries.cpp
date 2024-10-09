/*We will solve the problem recursively, reducing the problem by at least half at each step. If 𝑘<𝑛2
, we can see that the answer would be 2𝑘
. Otherwise, we have removed all the even positions. The odd positions can be renamed from 1,2,…,𝑛2
 and we can recursively find the solution for it. And then we can re-map back to our original 𝑛
 by multiplying by 2
 and subtracting 1
.
Time complexity is 𝑂(𝑙𝑜𝑔𝑛)
.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll solve(ll n ,ll k){
    if(n==1){
        return 1; // base case
    }
    if(k<=(n+1)/2){  //(n+1)/2 to deal with odd numbers 
        if(2*k>n){
            return (2*k)%n;
        }
        return 2*k;  
    }
    ll temp = solve(n/2 , k-(n+1)/2); // solve recursively 
     
     if(n&1)  // mapping to original number 
      return 2*temp+1;
     else 
      return 2*temp-1;  

}
int main(){
    int q;
    cin>>q;
    while(q--){
        ll n , k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;;
        
    }
    return 0;
}
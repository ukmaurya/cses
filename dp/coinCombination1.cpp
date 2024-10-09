#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mod = 1e9+7;
    
    // using direct state dp concept, where dp[i] = number of ways to sum n 
    vector<int>dp(c+1,0); // n states
    dp[0]=1; // base case
    for(int i=1;i<=c;i++){
       for(int j=0;j<n;j++){
           if(arr[j]<= i){
              dp[i] =( dp[i]+dp[i-arr[j]]%mod)%mod;
           }
       }
    }
    cout<<dp[c]%mod<<endl;
}
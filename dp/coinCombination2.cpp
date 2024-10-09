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
    
   
  //   vector<int>dp(c+1,0); // n states
   /* 
       code where dublicate are allowed 
        // using direct state dp concept, where dp[i] = number of ways to sum n 
         dp[0]=1; // base case
           for(int i=0;i<=c;i++){
         for(int j=i;j<n;j++){
           if(arr[j]<= i){
              dp[i] = ( dp[i]+dp[i-arr[j]]%mod)%mod;
           }
       }
    }
   */
    // since only distinct required so one movement is required , similar to striver 
    vector<vector<int>> dp(n+2,vector<int>(c+1,0));
    for(int i=0;i<=n;i++){
       dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=c;j++){
            int take = 0;
            if(arr[i]<=j){
                take = dp[i][j-arr[i]]%mod;
            }
            int ntake = dp[i+1][j]%mod;
            dp[i][j] = (take+ntake)%mod;
        }
    }
  
    cout<<dp[0][c]%mod<<endl; 

    // 
}
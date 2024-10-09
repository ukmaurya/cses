#include<bits/stdc++.h>
using namespace std;
int solve(int a ,int b,vector<vector<int>> &dp){ // trying recursion 
   if(a==b){
    return 0;
   }
   if(dp[a][b]!=-1){
    return dp[a][b];
   }
   int ans = INT_MAX;
   // TRY VERTICAL CUT 
   for(int v = 1 ;v<a;v++){
    ans  = min(ans , 1+solve(v , b,dp )+solve(a-v , b,dp) );
   }
   // trying horizontal cut

   for(int h=1;h<b;h++){
    ans = min(ans,1+solve(a,h,dp)+solve(a,b-h,dp));
   }

   return dp[a][b]=ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
    cout<<solve(a,b,dp)<<endl;  // recursive solution 
   



    // vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    
    // // base case  when already a square then no cuts are required 
    // for(int i=0;i<min(a,b);i++){
    //     dp[i][i]=0;
    // }
    // for(int i=1;i<=a;i++){
    //     for(int j=1;j<=b;j++){
    //          if(i==j){
    //             dp[i][j]=0;
    //             continue;
    //          }
    //         //vertical cut 
    //         for(int k=1;k<j;k++){
    //            dp[i][j] = min (dp[i][j] , 1+dp[i][k] + dp[i][j-k] );
    //         }
    //         // horizontal cuts
    //         for(int h=1;h<i;h++){
    //            dp[i][j] = min(dp[i][j] , 1+dp[h][j]+dp[i-h][j]);
    //         }
           
            
    //     }
    // }
    // cout<<dp[a][b];
    return 0;
}
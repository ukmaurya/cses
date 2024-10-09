#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 ll solve(int i , int j , vector<int>&arr , bool turn,vector<vector<ll>>&dp){
     
       if(i>j)
        return 0;
        if(dp[i][j]!=-1)
         return dp[i][j];
    
      ll ans = 0;
    
       if(turn==true){
         ll first = solve(i+1 , j,arr , false,dp)+arr[i];
         ll sec = solve(i,j-1,arr,false,dp)+arr[j];
           ans = max(first , sec);
       }
       else{
         ll first = solve(i+1 , j,arr , true,dp);
         ll sec = solve(i,j-1,arr,true,dp );
          ans = min(first , sec);
       }
     return dp[i][j]=ans ;
     
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,-1));
    ll ans= solve(0, arr.size()-1,arr,true,dp);
    cout<<ans<<endl;
    }
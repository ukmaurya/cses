#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
void solve(int i ,vector<int>&arr, vector<char>&dp){
   
    if(i>=dp.size()){
        return;
    }
    bool win = false;
    for(int k=0;k<arr.size();k++){
        if(i-k >= 0 && dp[i-arr[k]] == 'L' ){
            win=true;
            break;
        }
    }
    if(win == true){
        dp[i] = 'W';
    }
    else{
        dp[i]='L';
    }
    cout<<dp[i];
    solve(i+1 , arr , dp);

}
int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // tle on top down approach on bigger test case
      //    may be due to recursion stack 
       /*
       int n, k ;
          cin>>n>>k;
          vector<int> arr(k);
         for(int i=0;i<k;i++){
            cin>>arr[i];
          }
          vector<char> dp(n+1,'a'); // wether winning state or loosing state
          dp[0]='L';
          solve(1,arr,dp);
         

       */

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll p[k];
    for(int i=0;i<k;i++)
    {
        cin>>p[i];
    }
    ll dp[n+1]={};
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(i-p[j]>=0 && dp[i-p[j]]==0)
            {
                dp[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==1) cout<<"W";
        else cout<<"L";
    }  

      
    

 return 0;
}
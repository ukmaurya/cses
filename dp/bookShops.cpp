#include<bits/stdc++.h>
using namespace std;
int main(){
    // 0/1 knapsack 
    // trying to apply state dp directly
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int maxPages =0;
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=x;j++){
            int take = 0;
            if(price[i]<=j){
                take=dp[i+1][j-price[i]]+pages[i];
            }
            int ntake = dp[i+1][j];
            dp[i][j] = max(take,ntake);
        }
    }
  cout<<dp[0][x];
  return 0;
  // think of binary search 
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    cin>>n;
    long long int mod = 1e9+7;
    char grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[n-1][n-1]=='*' ||grid[0][0]=='*' )
   {  cout<<0;
      return 0;
     }
    vector<vector<long long int>> dp(n+1,vector<long long int> (n+1,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int up = 0;
            if(i-1>=0 && grid[i-1][j]!= '*')
             up = dp[i-1][j]%mod;
            int right = 0;
            if(j-1>=0 && grid[i][j-1]!= '*')
              right = dp[i][j-1]%mod;
            dp[i][j] += (up+right)%mod;    

        }
    }
 cout<<dp[n-1][n-1]%mod<<endl;
    return 0;
}
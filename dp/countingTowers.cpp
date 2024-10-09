#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

vector<vector<int>> dp(1e6 + 1, vector<int>(2));
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // // dp[i][0] = number of ways to fill up the grid from 
        // // ith row to the top such that there is a 1*2 block
        // // on the i-1th row trying to extend forward
        
        
        // // dp[i][1] = number of ways to fill up the grid from 
        // // ith row to the top such that there is are 2 1*1 blocks
        // // on the i-1th row trying to extend forward
        
        // // base cases
        // dp[n][0] = 1;
        // dp[n][1] = 1;
        // for(int i = n - 1; i >= 0; i--){
        //     dp[i][0] = (2LL * dp[i+1][0] + dp[i+1][1]) % MOD;
        //     dp[i][1] = (4LL * dp[i+1][1] + dp[i+1][0]) % MOD;
        // }
        
        // // final subproblem
        // cout << (dp[1][0] + dp[1][1]) % MOD << endl;



 // second approach 
//        dp[i][p]=Number of ways to fill from 0th position till the ith position.

// here p denotes the tile at ith position as following:

// dp[i][0] => number of ways for the same such that ith position consist of 2 tiles of width 1 each.
// dp[i][1] => number of ways for the same such that ith position consist of 1 tile of width 2.
// So,recurrence would be:

// recurrence
// dp[i][1] = 2*dp[i-1][1] + dp[i-1][0]
// dp[i][0]=  dp[i-1][1] + 4*(dp[i-1][0])


// dp[i][1] = 2*dp[i-1][1] +dp[i-1][0]
// =>2*ways because we can either extend the current level to one level down or keep another new tile + 1*ways because we can only keep another new tile and cannot extend the current level downwards
// dp[i][0] = dp[i-1][1]+ 4*dp[i-1][0]
// =>1*ways because we can only keep another new set of tiles and cannot extend the current level + 4*ways because we can either keep a new tile, or extend both the sides together or extend a single side at one time(left or right side, so intotal 4 ways

       


      // base cases 
        dp[0][1] =1;
        dp[0][0] =1;
        for(int i=1 ;i<n;i++){
               dp[i][1] = (2*1LL*dp[i-1][1] + dp[i-1][0])%MOD;
               dp[i][0] = (4*1LL*dp[i-1][0] +dp[i-1][1])%MOD;
        }

     
      cout<<(dp[n-1][0]+dp[n-1][1])%MOD<<endl;



    }
    // time complexity: O(tn)
}
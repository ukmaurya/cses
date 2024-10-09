#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 ll solve(int i  , ll amount , vector<ll>&coins,vector<vector<ll>> &dp){
        int n = coins.size();
        if(i==n){
            if(amount==0)
             return 0;
            else return 1e18; 
        }
        if(amount==0)
         return 0;
        if(dp[i][amount]!=-1) return dp[i][amount]; 
        ll take = 1e18;
        if(coins[i]<=amount)
        {
            take = 1+solve(i,amount-coins[i], coins,dp);
        }
       ll ntake = solve(i+1 , amount , coins,dp);
        return dp[i][amount] = min(take , ntake);
   }
int main(){
   /* ll n,amount;
    cin>>n>>amount;
    vector<ll> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(amount+1,-1));
       ll ans =  solve(0,amount , coins,dp);
        if(ans==1e18)
        {
            cout<<-1;
        }
        else
         cout<<ans; */

   /* ll n , amount;
    cin>>n>>amount;
    vector<ll> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<ll>> dp(n+2,vector<ll>(amount+2,INT_MAX));

    for(int i=0;i<=n;i++){
        dp[i][0]= 0;

    }
   // dp[n][0]=0;
    for(int i=n-1;i>=0;i--){
        for(int sum=1; sum <=amount;sum++){
            ll take = INT_MAX;
            if(coins[i]<=sum){
                take = 1+dp[i][sum-coins[i]];
            }
            ll ntake = dp[i+1][sum];
            dp[i][sum] = min(take , ntake);

        }
    }
    if(dp[0][amount]>=INT_MAX)
      cout<<-1;
    else  
     cout<<dp[0][amount]; */
    // space optimisation
     int n , T;
    cin>>n>>T;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // Create two vectors to store the previous and current DP states
    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = prev[target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the current DP state
            cur[target] = min(notTake, take);
        }
        // Update the previous DP state with the current state for the next iteration
        prev = cur;
    }
    
    // The answer is in the last row of the DP table
    int ans = prev[T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        cout<<-1;
    else 
     cout<<ans; // Return the minimum number of elements needed
    return 0;


}
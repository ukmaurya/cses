/*#include<bits/stdc++.h>
using namespace std;
int ub;
int solve(int index , int prev , vector<int>&arr,vector<vector<int>>&dp){
    if(index==arr.size() ){
        return 1;
    }
    if(dp[index][prev+1]!=-1)
      return dp[index][prev+1];
    int ans =0;
    if(arr[index]==0){
    
        if(prev == -1){ // 0 at first position
           for(int i=1;i<=ub;i++){
             arr[index]=i;
             ans += solve(index+1 , index , arr,dp);
             arr[index]=0;
           }
        }
        else{
            for(int i=-1;i<=1;i++){
                
                int ele = arr[prev]+i;
                if(ele >= 1 && ele<=ub){
                  arr[index]=ele;
                  ans += solve(index+1, index , arr,dp);
                  arr[index]=0;
                }
            }
        }
         
    }
    else{
        if(prev!=-1 && abs(arr[prev]-arr[index])>1)
          return 0;
        ans = solve(index+1 , index , arr,dp);  
    }
    return dp[index][prev+1]= ans;

}
int main(){
     int n;
     cin>>n>>ub;
     vector<int>arr(n);
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     // in dp if array given , just think of that index 
     // or try to break big array to prefix array  , or suffix array 
     vector<vector<int>>dp(n,vector<int>(n+2,-1));
     cout<< solve(0,-1,arr,dp);

    return 0;
}
*/

// in above same logic using prev as index but giving wrong result on memoization but correct
// result in recursion
// same logic below code is using prev as prev element not index 
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int ub;

int solve(int index, int prev, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case: if we have processed all elements in the array
    if (index == arr.size()) {
        return 1;
    }

    // Memoization check: if already computed, return the stored result
    if (dp[index][prev + 1] != -1) {
        return dp[index][prev + 1];
    }

    int ans = 0;

    // If the current element is 0, we have multiple choices to consider
    if (arr[index] == 0) {
        // If this is the first element (index == 0), prev should be -1
        if (index == 0) {
            // Try all possible values from 1 to ub
            for (int i = 1; i <= ub; ++i) {
                arr[index] = i;
                ans = (ans + solve(index + 1, i, arr, dp)) % MOD;
                arr[index] = 0; // Reset for next iteration or recursion
            }
        } else {
            // Try values around the previous valid element
            for (int i = max(1, prev - 1); i <= min(ub, prev + 1); ++i) {
                arr[index] = i;
                ans = (ans + solve(index + 1, i, arr, dp)) % MOD;
                arr[index] = 0; // Reset for next iteration or recursion
            }
        }
    } else {
        // If the current element is already fixed
        // Check if it satisfies the absolute difference condition with the previous valid element
        if (index == 0 || abs(arr[index] - prev) <= 1) {
            ans = solve(index + 1, arr[index], arr, dp) % MOD;
        }
    }

    // Memoize the result for the current state
    return dp[index][prev + 1] = ans;
}

int main() {
    int n;
    cin >> n >> ub;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Initialize dp table with -1
    vector<vector<int>> dp(n, vector<int>(ub + 2, -1));

    // Start solving from index 0 with prev = -1 (no previous valid element)
    cout << solve(0, -1, arr, dp) << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    // using subset sum concept
    vector<vector<bool>>dp(n+1 , vector<bool>(sum+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    dp[n-1][sum]=true;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=sum;j++){
             bool take = false;
            if(arr[i]<=j){
                take = dp[i+1][j-arr[i]];
            }
            bool ntake = dp[i+1][j];
            dp[i][j] = take||ntake;
        }
    }
    vector<int>ans;
    for(int i=1;i<=sum;i++){
        if(dp[0][i]==true){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    
}
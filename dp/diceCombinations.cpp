#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n , vector<int>&dp){
    int mod = 1e9+7;
    if(n==0){
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n]%mod;
    }
    ll ans = 0;
    for(int i=1;i<=6;i++){
        ans = (ans+solve(n-i,dp))%mod;
    }
    return dp[n] = ans%mod;
}
int main(){
    ll n;
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<solve(n,dp);
    return 0; 

  
}




// following method will fail as follwing method is like implimentation of 
// number of subset with sum = k 
// but the problem is  is consider subset where order doesnot matter while in this question
// order matters ex : sum = 3   {1,2} {2,1} count as 2 ways but foll will count only one 
// also in foll method backword movement is not allowed 

/*int solve(int index , vector<int>&arr , int sum ){
    if(index == arr.size()){
        return 0;
    }
    if(sum==0){
        return 1;
    }
    int take =0;
    if(arr[index] <= sum){
        take += solve(index, arr, sum-arr[index]);
    }
    int ntake = solve(index+1 ,arr, sum);
    return take+ntake;

} 
int main(){
    int n ;
    cin>>n;
    vector<int> arr(6);
    for(int i=0;i<6;i++){
        arr[i]=i+1;
    }
    cout<<solve(0,arr,n);
    return 0;

} */

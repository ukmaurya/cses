// Online C++ compiler to run C++ program online
/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll index ,ll prev,  vector<pair<ll, pair<ll,ll >>>&temp, vector<vector<ll>>&dp ){
    ll n = temp.size();
    if(index==n){
        return 0;
    }
    if(dp[index][prev+1]!= -1){
        return dp[index][prev+1];
    }
    ll take = 0;
    if(prev==-1 || ( temp[index].first > temp[prev].second.first ))
      take =  solve(index+1 , index ,temp,dp)+temp[index].second.second;
    ll ntake = solve(index+1 ,prev , temp,dp);
    return dp[index][prev+1] = max(take, ntake);

}
int main(){
    ll n ;
    cin>>n;
    vector<pair<ll, pair<ll,ll >>> temp;
    for(ll i=0;i<n;i++){
        ll start, end , profit;
        cin>>start>>end>>profit;
        temp.push_back({start,{end, profit}});
    }
    sort(temp.begin()  , temp.end());
    vector<vector<ll>>dp(n+1,vector<ll>(n+2,0));
   
   ll ans = solve(0,-1,temp,dp); // run time error in top down may be due to stack overflow 
    cout<<ans<<endl; 
   
    
    for(ll i=n-1;i>=0;i--){
        for(ll prev = i-1;prev>=-1;prev--){
                  ll take = 0;
             if(prev==-1 || ( temp[i].first > temp[prev].second.first ))
               take = dp[i+1][i+1] +temp[i].second.second;
            ll ntake = dp[i+1][prev+1]; 
            dp[i][prev+1] = max(take, ntake);
        }
    }
    cout<<dp[0][0]<<endl;
    return 0;
  
}
*/

// we have solved using subset method by both top down but it run time error on larger test cases 
// constraint are telling nlogn will be good 
// we can use the method of lis but how to keep track of profit for this we will use dp 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = LLONG_MAX;
int solve(ll idx  , vector<pair<ll,pair<ll,ll>>>&temp, vector<ll> &dp){
    if(idx == temp.size()) 
       return 0;
    if(dp[idx]!=-1){
        return dp[idx];
    }
    ll ntake  = solve(idx+1 , temp,dp);
    ll take =0;
   ll nextStart = temp[idx].second.first;
    ll ub = upper_bound(temp.begin() , temp.end() , make_pair(nextStart , make_pair(INF ,INF)))-temp.begin();
    take = solve(ub , temp,dp)+temp[idx].second.second;
    return dp[idx]=max(take , ntake);   

}
int main(){
    ll n ;
    cin >> n;
    vector<pair<ll, pair<ll,ll>>> temp;
    for(ll i = 0; i < n; i++){
        ll start, end , profit;
        cin >> start >> end >> profit;
        temp.push_back({start, {end, profit}});
    }

    sort(temp.begin(), temp.end()); // Sort on basis of start time

    // // DP array to store maximum profit achievable starting from each interval
    // vector<ll> dp(n + 1, 0);

    // // Iterate from the last interval to the first
    // for(ll i = n - 1; i >= 0; i--){
    //     ll take = temp[i].second.second; // Profit of current interval
    //     ll nextIntervalStart = temp[i].second.first;

    //     // Find the next interval that starts after the current interval ends
    //     auto it = upper_bound(temp.begin(), temp.end(), make_pair(nextIntervalStart, make_pair(INF, INF))) - temp.begin();

    //     // Calculate maximum profit by either taking the current interval or skipping it
    //     dp[i] = max(dp[i + 1], take + dp[it]);
    // }

    // cout << dp[0] << endl; // Maximum profit achievable starting from the first interval
    // return 0;


    // using top down dp 
    vector<ll> dp(n + 1, -1);
    cout<<solve(0,temp,dp);
    return 0;

}

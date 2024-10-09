#include<bits/stdc++.h>
using namespace std;
int solve(string s, vector<int> &dp){
    int n = s.size();
   
    if(n==1){
        if( s[0]=='0')
          return 0;
        else 
         return 1;
    }
    if(dp[stoi(s)] != -1){
        return dp[stoi(s)];
    }
    int ans = INT_MAX;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') // else infinite time recursion call =>segmentation fault 
         continue;
        string temp = s;
        int num = stoi(temp);
        int digit = s[i]-'0';
        num = num-digit;
        ans = min(ans , 1+solve(to_string(num),dp));
    }
    return dp[stoi(s)]=ans;
}
int main(){
 /*string s;
   int num ;
   cin>>num;
   s = to_string(num);
   vector<int> dp(num+1,-1);
   int ans = solve(s,dp);
   cout<<ans;
 */  

  // using direct state dp method
  //dp[i] = min no of oeration required to make number i to 0
  // trasition dp[i] = 1 + summation dp[i-d] for all d in x 
  // base case dp[0]=0;
  int num;
  cin>>num;
  vector<int>dp(num+1,1e9);
  dp[0]=0;
  for(int i=1;i<=num;i++){
    for(char ch :to_string(i)){
          dp[i]=min(dp[i] , 1+dp[i-(ch-'0')]);
         
    }
  }
   cout<<dp[num]<<endl;
  return 0;
}
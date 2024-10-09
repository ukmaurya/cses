#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][10][2][2] ; 
// dp[num][prev][leading_zeros][istight] 
/* number of numbers of num digits between 0 to b ,which do not contain adjacent digit, 
   taking account leading zeroes , and tight
*/
/*  leading zeroes , 0001 allowwed but 1000 not allowed since 0 are repeating and are not leading zeroes 
    tight is requires so that grater numeber than required not counted 
*/
ll solve(ll index, string &s ,int prev,int leading_zero , int istight  ){
   if(index == s.size()){
    return 1;
   }
  if(prev!=-1 && dp[index][prev][leading_zero][istight] != -1)
    return dp[index][prev][leading_zero][istight];
  
  int limit = (istight==1)?s[index]-'0':9;
  ll ans =0;
  for(int dig = 0;dig<=limit;dig++){
    if( dig==prev && leading_zero != 1){
        continue;
    }
   //  int new_leadingzero = leading_zero&&(dig==0)?1:0;
    // int new_tight = (istight&&(dig==limit))?1:0;
    ans += solve(index+1,s,dig,leading_zero&&(dig==0),istight&&(dig==limit));
  } 
  return dp[index][prev][leading_zero][istight] = ans;

}
int main(){
    ll A,B;
    cin>>A>>B;
    string a = to_string(A-1);
    string b = to_string(B);
    memset(dp,-1,sizeof(dp));
    ll ans2 = solve(0,a,-1,1,1);
   
    memset(dp,-1,sizeof(dp));
    ll ans1 = solve(0,b,-1,1,1);
   
    ll ans = ans1-ans2;
    cout<<ans<<endl;
    return 0;

}
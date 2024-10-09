#include<bits/stdc++.h>
using namespace std;
int main(){
	int n ;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  /*vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=-1;prev--){
            int take = 0;
            if(prev==-1 || arr[i]>arr[prev]){
                 take = 1+dp[i+1][i+1];
            }
            int ntake = dp[i+1][prev+1];
             dp[i][prev+1] = max(take, ntake);
        } 
    }
	cout<<dp[0][-1+1];  */

// binary search method

    vector<int> temp;
    for(int i=0;i<n;i++){
      if(temp.empty() || temp.back()<arr[i]){
        temp.push_back(arr[i]);
      }
      else{
        int index = lower_bound(temp.begin() , temp.end() ,arr[i])-temp.begin();
        temp[index]=arr[i];
      }
    }
   cout<<temp.size();
}

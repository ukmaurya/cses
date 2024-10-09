#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
vector<vector<int>> matMul(vector<vector<int>>&ans , vector<vector<int>>&adj){
            int n = ans.size();
            vector<vector<int>> mulres(n,vector<int>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                       mulres[i][j] = ( mulres[i][j] + (ans[i][k]*1LL*adj[k][j])%mod)%mod;
                    }
                }
            }
            return mulres;

}
vector<vector<int>> matExponential(vector<vector<int>> &adj , int k){
    if(k==1){
        return adj;
    }
    vector<vector<int>>ans=adj;
    while(k){
        if(k&1)
          ans = matMul(ans , adj);
        adj = matMul(adj,adj);
        k=k>>1;
    }
    return ans;
}

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>adj(n,vector<int>(n,0));
    for(int i=0;i<m;i++){
      int a ,b;
      cin>>a>>b;
      adj[a-1][b-1]++;
   }
   vector<vector<int>> ans = matExponential(adj,k-1); // k-1 since zero based indesing 
   cout<<ans[0][n-1]%mod<<endl;


   
 return 0;
}
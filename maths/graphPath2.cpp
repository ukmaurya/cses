#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
ll INF = 4e18;
vector<vector<ll>> matMul(vector<vector<ll>>&ans , vector<vector<ll>>&adj){
            ll n = ans.size();
            vector<vector<ll>> mulres(n,vector<ll>(n,INF));
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    for(ll k=0;k<n;k++){
                       mulres[i][j] = min( mulres[i][j] , (ans[i][k]+adj[k][j]));
                    }
                }
            }
            return mulres;

}
vector<vector<ll>> matExponential(vector<vector<ll>> &adj , ll k){
    if(k==1){
        return adj;
    }
    vector<vector<ll>>ans=adj;
    while(k){
        if(k&1)
          ans = matMul(ans , adj);
        adj = matMul(adj,adj);
        k=k>>1;
    }
    return ans;
}

int32_t main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>adj(n,vector<ll>(n,INF));
    for(ll i=0;i<m;i++){
      ll a ,b,c;
      cin>>a>>b>>c;
      adj[a-1][b-1] = min(adj[a-1][b-1] , c);
   }
   vector<vector<ll>> ans = matExponential(adj,k-1); // k-1 since zero based indesing 
   if(ans[0][n-1]!= INF)
      cout<<ans[0][n-1]<<endl;
    else cout<<-1<<endl;  


   
 return 0;
}
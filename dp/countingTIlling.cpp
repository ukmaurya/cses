#include<bits/stdc++.h>
using namespace std;

int dp[1001][1<<11];
void callNextMasks(int curmask , int row , int nextMask ,int n, vector<int> &nxtMask){
     if(row==n+1){ // this mask prepared 
        nxtMask.push_back(nextMask);
        return;
     }
     // care bellow donot use if( (curmask&(1<<row)) == 1 )  since when row is not zero it will not give 1 workout will some example 
     if( (curmask&(1<<row)) != 0 ){ // that cell is already accupied u can not put tile 
        callNextMasks(curmask , row+1 , nextMask , n , nxtMask);
     }
     // vertical Filling in cur col
     if( row != n && (curmask&(1<<row))==0 && (curmask&(1<<(row+1)))==0 ){ 
          int newCurMask = (curmask|(1<<row))|1<<(row+1);
          callNextMasks(newCurMask, row+2 , nextMask , n , nxtMask);
     }
     // horizontal filling in cur col 
     if((curmask&(1<<row))==0){
        callNextMasks(curmask|(1<<row), row+1, nextMask|(1<<row) , n, nxtMask);
     }



}
int solve(int col , int mask , int m , int n){
    int mod = 1e9+7;
    if(col==m+1){ // all col fillled
       if(mask==0){ // proper filling ie no tile should cross grid 
        return 1; 
       }
       return 0;
    }

    if(dp[col][mask] != -1){
        return dp[col][mask]%mod;
    }
    vector<int> nxtMask ; // contains all mask generated during the filling of cur column
    callNextMasks( mask,1,0,n, nxtMask);
    int ans =0;
    for(auto it: nxtMask){  // for each arrangement check weather is correct way of filling 
        ans =(ans + solve(col+1 ,it, m,n )%mod)%mod;
    }
    return dp[col][mask] = ans%mod;
}
int main(){
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    int ans = solve(1,0,m,n);
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j , vector<vector<char>> &grid , vector<vector<int>>&vis ){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j]=1;
    int dx[]={0,1,0,-1};
    int dy[] = {1,0,-1,0};
    for(int k=0;k<4;k++){
        int r = i+dx[k];
        int c = j+dy[k];
        if(r>=0 && r<n && c>=0 &&c<m && !vis[r][c]&&grid[r][c]=='.'){
            dfs(r,c,grid,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
     vector<vector<int>>vis(n,vector<int>(m,0));
    int ans =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='.'){
                ans++;
                dfs(i,j,grid,vis);

            }
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
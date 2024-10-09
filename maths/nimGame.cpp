#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
          int n ;
          cin>>n;
          vector<int> arr(n);
          int xorr=0;
          for(int i=0;i<n;i++){
            cin>>arr[i];
            xorr = xorr^arr[i];
          }
        if(xorr==0){ // lossing state , since it will start with first player 
            cout<<"second"<<endl;
        }
        else{
            cout<<"first"<<endl;
        }

    }

 return 0;
}
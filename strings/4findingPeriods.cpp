#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gethash(int l , int r , vector<ll>&hash , vector<ll>&power , int &mod){
    ll ans = hash[r+1]-(hash[l]*power[r-l+1]%mod+mod)%mod; // due to shift of indexes by one place
    if(ans<0)        // take one example abcabca   and do py prefix hash =>very important concept
      return ans+mod;
    return ans;               // in gerneal hash[ l to r ] = hash[r]-hash[l-1]*power[len of window]
}
int main(){
    string s;
    cin>>s;
    int n = s.size();
    ll prime = 31;
    int mod = 1e9+7;
    vector<ll> power(n+5,0);
    power[0]=1;
    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*prime)%mod;
    }
    vector<ll> hash(n+5,0);
    hash[0] = 0; // origin shifting by one place
    for(int i=1;i<=n;i++){
        hash[i]=((hash[i-1]*prime)%mod+s[i-1])%mod;
    }
    // now check for each valid prefix length weather its repeatition can forms string or not 

    for(int i=1;i<=n;i++){ // for each prefix len 
          int index = 0;
          bool flag = true;
          while(index<n){
            int len = min(i,n-index);
            ll temp1 = gethash(0,len-1,hash,power,mod);
            ll temp2 = gethash(index,index+len-1,hash,power,mod);
            flag = flag && ( temp1==temp2 );
            index = index+len;
          }
          if(flag==true){
            cout<<i<<" ";
          }

    }
    return 0;
}
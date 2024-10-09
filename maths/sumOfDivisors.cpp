/* 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
const ll modInverse2 = 500000004;
ll sum(ll start , ll end){
   ll ans = (((end-start+1)%mod*(start+end)%mod)*modInverse2%mod)%mod; // AP sum n*(a+l)/2
   return ans;
}
int main(){
   ll n ;
   cin>>n;
   ll ans = 0;
   for(int i=1;i<=n;){ // we will be 
       ll q = n/i; // number of multiple of i
       ll start = i;
       ll end = n/q;  // end of cur group of same number of multiple 
       ans = (ans+(sum(start, end)*q)%mod)%mod; 
     
      i = end+1;


   }
   cout<<ans<<endl;
} */
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long TWO_MOD_INV = 500000004;

// Function to calculate the sum of the arithmetic series
long long sum(long long start, long long end) {
    return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    
    long long ans = 0;
    for (long long i = 1; i <= n;) {
        long long q = n / i;
        long long lastSame = n / q;
        ans = (ans + (sum(i, lastSame) * q) % MOD) % MOD;
        i = lastSame + 1;
    }

    cout << ans << endl;
    
    return 0;
}

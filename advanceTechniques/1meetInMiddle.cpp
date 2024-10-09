#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
ll binaryExponentiation(ll a, ll b, int mod ){   
    if(b==0){
        return 1;
    }
    else if(b==1){
        return a;
    }
    ll ans = 1;
    while(b){
        if(b&1){
            ans =( ans*a)%mod;
        }
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}
ll mul(ll x,ll y,ll modulo)
{
    return ((x%mod)*(y%mod))%modulo;
}
ll dividing(ll x,ll y){
    return mul(x,binaryExponentiation(y,mod-2,mod),mod)%mod;
}

void solve() {
    int n, x; cin >> n >> x;
    int m1 = n / 2, m2 = n - m1;
    int arr1[m1], arr2[m2];
    for (int i = 0; i < m1; i++) cin >> arr1[i];
    for (int i = 0; i < m2; i++) cin >> arr2[i];

    vector<ll> sum1, sum2;
    for (int i = 0; i < (1 << m1); i++) { 
        ll cur = 0;
        for (int j = 0; j < m1; j++)
            if (i & (1 << j))
                cur += arr1[j];
        sum1.push_back(cur);
    }
    for (int i = 0; i < (1 << m2); i++) { 
        ll cur = 0;
        for (int j = 0; j < m2; j++)
            if (i & (1 << j))
                cur += arr2[j];
        sum2.push_back(cur);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    for (ll s1 : sum1)
        ans += upper_bound(sum2.begin(), sum2.end(), x - s1) - lower_bound(sum2.begin(), sum2.end(), x - s1);
    cout << ans;
}

int main(){
  
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   // solve();
    // bellow is giving TLE in one test case
   int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Define left and right arrays for meet in the middle
    vector<ll> left; // Store subset sums of the first half
    unordered_map<ll, ll> mp; // Act as right vector with counts of sums

    // Generate subset sums for both halves
    int half = n / 2;

    // Generate all subset sums for the left half
    for (int mask = 0; mask < (1 << half); mask++) {
        ll lsum = 0;
        for (int i = 0; i < half; i++) {
            if (mask & (1 << i)) {
                lsum += arr[i];
            }
        }
        left.push_back(lsum);
    }

    // Generate all subset sums for the right half and store in the map with their counts
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        ll rsum = 0;
        for (int i = 0; i < (n - half); i++) {
            if (mask & (1 << i)) {
                rsum += arr[half + i];
            }
        }
        mp[rsum]++;
    }

    ll ans = 0;

    // Calculate the number of valid combinations
    for (ll sum : left) {
        ll req = x - sum;
        if (mp.find(req) != mp.end()) {
            ans += mp[req];
        }
    }

    cout << ans << endl;
    return 0; 
}
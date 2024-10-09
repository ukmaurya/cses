#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 const int MOD_INV_2 = 500000004; // Modular inverse of 2 under MOD
int main(){
    int n;
    cin>>n;
    int sum = n*(n+1)/2;
    if(sum%2!=0){
        cout<<0;
        return 0;
    }
    int target = sum/2;
    int mod = 1e9+7;
    vector<vector<int>>dp(n+2,vector<int>(target+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=target;j++){
            int take = 0;
            if(i<=j){
               take  =  dp[i-1][j-i]%mod;
            }
            int ntake =  dp[i-1][j]%mod;
            dp[i][j] = (take+ntake)%mod;
        }
    }
    
    cout<<((dp[n][target])*(ll)MOD_INV_2)%mod<<endl;

     // mod 2 inverse is used since dp[n][target] /2 required since each pairs counted twice 
     // so we divide by 2 , but it is modular division so mod inverse of 2 
    }

/* in above code when i was filling table n to 1 since making recursion form 1 to n 
   then it was giving wrong result due to base case.
try to fill table keeping in mind the which side is base case 
 below code is correct while filling form n but we also putted base case accordingly 
*/

    /*#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;

    // If the sum is odd, we cannot partition it into two equal subsets
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int target = sum / 2;
    vector<vector<int>> dp(n + 2, vector<int>(target + 1, 0));

    // Base case: There's one way to achieve the sum 0 (using no elements)
    dp[n + 1][0] = 1;

    // Fill the DP table from n to 1
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i + 1][j]; // Not including the i-th element
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - i]) % MOD; // Including the i-th element
            }
        }
    }

    // Answer is in dp[1][target], which represents the number of ways to achieve sum 'target' using elements 1 to n
    cout << dp[1][target]/2 << endl;

    return 0;
}
    */
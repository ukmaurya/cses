#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    // dp[mask][w] will store the minimum number of rides needed for subset represented by mask
    vector<vector<int>> dp(1 << n, vector<int>(x + 1, INT_MAX));

    // Base case: no people, no rides
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int w = 0; w <= x; w++) {
            if (dp[mask][w] == INT_MAX) continue;

            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) { // If the i-th person is not yet included in the current subset
                    int new_mask = mask | (1 << i);

                    if (w + weights[i] <= x) {
                        // If we can add the person to the current ride
                        dp[new_mask][w + weights[i]] = min(dp[new_mask][w + weights[i]], dp[mask][w]);
                    } else {
                        // Else, we need a new ride for the person
                        dp[new_mask][weights[i]] = min(dp[new_mask][weights[i]], dp[mask][w] + 1);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int w = 0; w <= x; w++) {
        ans = min(ans, dp[(1 << n) - 1][w]);
    }

    cout << ans << endl;

    return 0;
}

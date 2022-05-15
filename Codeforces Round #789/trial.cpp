#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

int solve(int A, int B) {
    vector<vector<int>> dp(A + 1, vector<int>(9*A + 1, 0));
    for(int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= A; i++) {
        for(int j = 0; j <= 9*i; j++) {
            for(int k = 0; k <= 9; k++) {
                if(k <= j) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }   
    }
    return dp[A][B] - dp[A - 1][B];
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << solve(2, 2) << endl;
    return 0;
}
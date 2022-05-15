#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

int dp[1000][1000];

int rec(int n, int taken) {
    if(n == taken) return 1;
    if(n < taken) return 0;

    if(dp[n][taken] != -1) return dp[n][taken];

    return dp[n][taken] = rec(n - taken, taken) + rec(n, taken + 1);
}

void solve() { 
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << rec(n, 1) << endl;    
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    cin >> t;
    for(i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
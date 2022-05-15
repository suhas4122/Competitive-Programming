#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

int dp[700005][2][4];
vector<int>arr;
int n;

int rec(int idx, int sell, int left) {
    cout << idx << " " << sell << " " << left << endl;
    if(idx == n || left == 0) {
        return 0;
    }
    if(dp[idx][sell][left] != -1) {
        return dp[idx][sell][left];
    }
    int ans;
    // if(sell == 1) {
    //     ans = max(rec(idx + 1, sell, left), rec(idx + 1, 1 - sell, left - 1) + arr[idx]);
    // } else {
        cout << "Here";
        ans = max(rec(idx + 1, sell, left), rec(idx + 1, 1 - sell, left) - arr[idx]);
    // }
    return dp[idx][sell][left] = ans; 
}

int maxProfit(const vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    n = A.size();
    return rec(0, 0, 2);
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int>A({2});
    cout << maxProfit(A) << endl;
    return 0;
}


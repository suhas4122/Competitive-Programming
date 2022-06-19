#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

int g[3][3];

ll rec(int x, int y, int rem) {
    if (rem == 0) {
        return 1;
    }
    ll ans = 0;
    g[x][y] = 1;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            int nx = x + i;
            int ny = y + j;
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            if (g[nx][ny]) continue;
            if ((i % 2) == 0 && (j % 2) == 0) {
                if (!g[x + i / 2][y + j / 2]) continue;
            }
            ans += rec(nx, ny, rem - 1);
        }
    }
    g[x][y] = 0;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans += rec(i, j, n - 1);
        }
    }
    cout << ans;
}

signed main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    for (i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
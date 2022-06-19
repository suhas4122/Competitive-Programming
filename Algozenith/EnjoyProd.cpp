#include <bits/stdc++.h>
using namespace std;

#define ll long long

string l, r;
ll k, n, dp[20][2][2][2][100][1024], par[20][2][2][2][100][1024];

ll rec(ll idx, ll nlo, ll nhi, ll start, ll num, ll mask) {
    if (idx == n) {
        return num == 0 && __builtin_popcountll(mask) == 1;
    }
    ll &ans = dp[idx][nlo][nhi][start][num][mask];
    if (ans != -1) return ans;
    ans = 0;
    ll lo = (nlo == 1 ? l[idx] - '0' : 0);
    ll hi = (nhi == 1 ? r[idx] - '0' : 9);
    for (ll i = lo; i <= hi; i++) {
        if (i) {
            ll nmask = mask;
            for (ll j = 1; j < 10; j++) {
                if (mask & (1 << j)) {
                    if (j % i == 0) nmask ^= (1 << j);
                }
            }
            ll temp = rec(idx + 1, nlo & (i == lo), nhi & (i == hi), 1, (10 * num + i) % k, nmask | (1 << i));
            if (temp * i > ans) {
                ans = temp * i;
                par[idx][nlo][nhi][start][num][mask] = i;
            }
        } else if (!start) {
            ll temp = rec(idx + 1, nlo & (i == lo), nhi & (i == hi), 0, 0, 0);
            if (temp > ans) {
                ans = temp;
                par[idx][nlo][nhi][start][num][mask] = i;
            }
        }
    }
    return dp[idx][nlo][nhi][start][num][mask] = ans;
}

ll myans = 0;

void getans(ll level, ll tlo, ll thi, ll started, ll num, ll mask) {
    if (level == n) return;
    ll curr = par[level][tlo][thi][started][num][mask];
    myans = myans * 10 + curr;
    ll lo = (tlo == 1 ? l[level] - '0' : 0);
    ll hi = (thi == 1 ? r[level] - '0' : 9);
    if (curr) {
        ll nmask = mask;
        for (ll j = 1; j < 10; j++) {
            if (mask & (1 << j)) {
                if (j % curr == 0) nmask ^= (1 << j);
            }
        }
        getans(level + 1, tlo & (curr == lo), thi & (curr == hi), 1, (10 * num + curr) % k, nmask | (1 << curr));
    } else if (!started) {
        getans(level + 1, tlo & (curr == lo), thi & (curr == hi), 0, 0, 0);
    }
}

void solve() {
    cin >> l >> r >> k;
    l = string(r.length() - l.length(), '0') + l;
    n = r.length();
    memset(dp, -1, sizeof(dp));
    myans = 0;
    ll ans = rec(0, 1, 1, 0, 0, 0);
    if (ans == 0)
        cout << -1 << '\n';
    else {
        getans(0, 1, 1, 0, 0, 0);
        cout << ans << " " << myans << '\n';
    }
}

signed main() {
    int tc;
    cin >> tc;
    while (tc--) solve();
}
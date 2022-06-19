#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

string board[8];
bool col[8], dia1[16], dia2[16];

ll rec(ll x) {
    if(x == 8) {
        return 1;
    }
    ll ans = 0;
    for(int i = 0; i < 8; i++) {
        if(board[x][i] == '.') {
            if(col[i] == 0 && dia1[x + i] == 0 && dia2[7 + i - x] == 0) {
                col[i] = dia1[i + x] = dia2[7 + i - x] = 1;
                ans += rec(x + 1);
                col[i] = dia1[i + x] = dia2[7 + i - x] = 0;
            }
        }
    }
    return ans;
}

void solve() {
    for(int i = 0; i < 8; i++) cin >> board[i];
    ll ans = rec(0);
    cout << ans;
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    // cin >> t;
    for(i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
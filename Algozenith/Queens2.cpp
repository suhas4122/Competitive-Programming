#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

ll n;
int pos[15];
bool col[15], dia1[30], dia2[30];

ll rec(ll x) {
    if(x == n) {
        return 1;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if((x < 2 || (pos[x - 2] != i + 1 && pos[x - 2] != i - 1)) && (x < 1 || (pos[x - 1] != i + 2 && pos[x - 1] !=  i - 2))) {
            if(col[i] == 0 && dia1[x + i] == 0 && dia2[n - 1 + i - x] == 0) {
                col[i] = dia1[i + x] = dia2[n - 1 + i - x] = 1;
                pos[x] = i;
                ans += rec(x + 1);
                pos[x] = -100;
                col[i] = dia1[i + x] = dia2[n - 1 + i - x] = 0;
            }
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < 15; i++) pos[i] = -100;
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
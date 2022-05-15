#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;
    int rem = (x - a > 0) ? x - a : 0;
    int rem2 = (y - b > 0) ? y - b : 0;
    if(rem + rem2 > c) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;
vector<string> ans;
string curr;

void rec(int x, int y) {
    if(x == 0 && y == 0) {
        ans.push_back(curr);
    }
    if(x > 0) {
        curr += '(';
        rec(x - 1, y);
        curr.pop_back();
    }
    if(y > x) {
        curr += ')';
        rec(x, y - 1);
        curr.pop_back();
    }
}

void solve() {
    ll n;
    cin >> n;
    curr = "";
    rec(n / 2, n / 2);
    for(auto &x: ans) {
        cout << x << endl;
    }
}

signed main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    // cin >> t;
    for (i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
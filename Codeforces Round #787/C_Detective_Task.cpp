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
    string s;
    cin >> s;
    int n = s.size();
    int lastOne = 0, firstZero = n - 1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') lastOne = i;
        if(firstZero == n - 1 && s[i] == '0') firstZero = i;
    }
    int ans = firstZero - lastOne + 1;
    cout << ans << endl;
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
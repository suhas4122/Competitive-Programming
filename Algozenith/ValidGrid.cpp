#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
    bool f = 1;
    string r = "{";
    for (const auto& x : v) {
        if (!f) r += ", ";
        f = 0;
        r += to_string(x);
    }
    return r + "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#define debarr(a, n)                                 \
    cerr << #a << " : ";                             \
    for (int i = 0; i < n; i++) cerr << a[i] << " "; \
    cerr << endl;
#define debmat(mat, row, col)                                   \
    cerr << #mat << " :\n";                                     \
    for (int i = 0; i < row; i++) {                             \
        for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; \
        cerr << endl;                                           \
    }

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

bool vis[7][7];
string s;
map<char, pair<int, int>> mp;

ll rec(ll idx, ll x, ll y) {
    if (x == 6 && y == 0) {
        if (idx == 48) {
            return 1;
        }
        return 0;
    }
    vis[x][y] = 1;
    ll ans = 0;
    if (s[idx] != '?') {
        int nx = x + mp[s[idx]].first;
        int ny = y + mp[s[idx]].second;
        if (nx <= 6 || nx >= 0 || ny <= 6 || ny >= 0 || !vis[nx][ny])
            ans += rec(idx + 1, nx, ny);
    } else {
        for (auto& c : {'U', 'D', 'L', 'R'}) {
            int nx = x + mp[c].first;
            int ny = y + mp[c].second;
            if (nx <= 6 || nx >= 0 || ny <= 6 || ny >= 0 || !vis[nx][ny])
                ans += rec(idx + 1, nx, ny);
        }
    }
    vis[x][y] = 0;
    return ans;
}

void solve() {
    cin >> s;
    mp['D'] = {1, 0};
    mp['U'] = {-1, 0};
    mp['R'] = {0, 1};
    mp['L'] = {0, -1};
    cout << rec(0, 0, 0);
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
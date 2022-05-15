#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
    bool f = 1;
    string r = "{";
    for (const auto &x : v) {
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

vector<vector<int>> g;

int dfs1(int v) {
    if (g[v].size() == 0) {
        return 1;
    } else {
        int res = 0;
        int len = g[v].size();
        for (int i = 0; i < len; i++) {
            res += dfs1(g[v][i]);
        }
        return res;
    }
}

void dfs2(int v, vector<int> &path) {
    path.push_back(v + 1);
    if (g[v].size() == 0) {
        cout << path.size() << endl;
        for (auto &x : path) cout << x << " ";
        cout << endl;
        path.clear();
    } else {
        dfs2(g[v][0], path);
        int len = g[v].size();
        for (int i = 1; i < len; i++) {
            vector<int> temp;
            dfs2(g[v][i], temp);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    vector<int> p(n);
    int root;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if (i == p[i]) {
            root = i;
        } else {
            g[p[i]].push_back(i);
        }
    }
    vector<int> path;
    cout << dfs1(root) << endl;
    dfs2(root, path);
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    cin >> t;
    for (i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
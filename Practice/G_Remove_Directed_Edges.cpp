#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
#define debarr(a, n) cerr << #a << " : "; for(int i = 0; i < n; i++) cerr << a[i] << " "; cerr << endl;
#define debmat(mat, row, col) cerr << #mat << " :\n"; for(int i = 0; i < row; i++){for(int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

vector <int> in, out;
vector<vector<int>>graph;
vector<int>dp;

int rec(int x) {
    if(dp[x] != -1) return dp[x];
    if(out[x] >= 2 && in[x] >= 2) {
        dp[x] = 1;
        for(auto v: graph[x]) {
            dp[x] = max(dp[x], rec(v) + 1);
        }
        return dp[x];
    } else if(in[x] >= 2) {
        return dp[x] = 1;
    } else {
        return dp[x] = -1e8;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    dp.assign(n, -1);
    in.resize(n);
    out.resize(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        in[v]++;
        out[u]++;
    }
    int ans = 1;
    for(int i = 0; i < n; i++) {
        if(out[i] >= 2) {
            for(auto v: graph[i]) {
                ans = max(ans, rec(v) + 1);
            }
        }
    }
    // pr(dp);
    cout << ans << endl;
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    for(i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}

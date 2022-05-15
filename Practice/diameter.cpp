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

vector<vector<int>> g, ginv;
vector<int>good, vis;

void dfs_good(int u) {
    good[u] = 1;
    for(auto &x: ginv[u]) {
        if(!good[x]) {
            dfs_good(x);
        }
    }
}

void dfs(int u) {
    vis[u] = 1;
    for(auto &x: g[u]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}

int solve(vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return 0;
    }
    g.assign(n + 1, {});
    ginv.assign(n + 1, {});
    good.assign(n + 1, 0);
    vis.assign(n + 1, 0);

    for(int i = 0; i < n; i++) {
        g[i + 1].push_back(A[i]);
        ginv[A[i]].push_back(i + 1);
    }
    pr(g);
    pr(ginv);

    dfs_good(1);
    pr(good);

    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(!vis[i] && !good[i]) {
            pr(i);
            dfs(i);
            ans++;
        }
    }

    return ans;
}


signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int>A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << solve(A) << endl;

    return 0;
}
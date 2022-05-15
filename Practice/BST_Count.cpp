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

#define int long long 
vector<vector<int>> dp;
int mod = 1000000007;
int fact[110];

int inv(int a) {
    a %= mod;
    if (a < 0) a += mod;
    int b = mod, u = 0, v = 1;
    while (a) {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += mod;
    return u;
}

int ncr(int n, int r) {
    return (((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod;
}

int rec(int n, int m) {
    if((1 << (m + 1)) - 1 < n) return 0;
    if(n <= 1) {
        if(m == 0)
            return 1;
        return 0;
    }
    if(dp[n][m] != -1) 
        return dp[n][m];
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = i;
        int y = n - i - 1;
        int tot = 0;
        for(int j = 0; j < m - 1; j++) {
            tot = (tot + (rec(x, j) * rec(y, m - 1)) % mod) % mod;
        }
        for(int j = 0; j < m - 1; j++) {
            tot = (tot + (rec(x, m - 1) * rec(y, j)) % mod) % mod;
        }
        tot = (tot + (rec(x, m - 1) * rec(y, m - 1)) % mod) % mod;

        ans = (ans + (tot * ncr(x + y, x)) % mod) % mod;
    }
    return dp[n][m] = ans % mod;
} 

int cntPermBST(int A, int B) {
    dp.clear();
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < 110; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    dp.assign(A + 1, vector <int> (B + 1, -1));
    return rec(A, B);
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << cntPermBST(n, m) << endl;    
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

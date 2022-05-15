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

string a, b, c;
int x, y, n;
int dp[151][151][151];

int rec(int i, int j, int k) {
    pr(i, j, k);
    if(i == x && j == y && k == n) {
        return 1;
    }
    if((i < x && a[i] != c[k]) && (j < y && b[j] != c[k])) {
        return 0;
    }
    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    if(i == x) {
        return dp[i][j][k] = (b.substr(j) == c.substr(k));
    }
    if(j == y) {
        return dp[i][j][k] = (a.substr(i) == c.substr(k));
    }
    int ans = 0;
    if(a[i] == c[k]) {
        ans |= rec(i + 1, j, k + 1);
    }
    if(b[j] == c[k]) {
        ans |= rec(i, j + 1, k + 1);
    }
    return dp[i][j][k] = ans;
}

int isInterleave(string A, string B, string C) {
    x = A.size();
    y = B.size();
    n = C.size();
    a = A;
    b = B;
    c = C;
    if(x + y != n) return 0;
    memset(dp, -1, sizeof(dp));
    return rec(0, 0, 0);
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << isInterleave("B", "e", "Be") << endl;
    return 0;
}
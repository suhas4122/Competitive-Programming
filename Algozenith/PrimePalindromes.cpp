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

vector<bool> isPrime;

bool prime(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false; 
    }
    return true;
}

ll rec(ll curr, ll maxlen, ll currlen, ll a, ll b) {
    ll ans = 0;
    if(currlen <= (maxlen + 1) / 2) {
        string st = to_string(curr);
        string st2 = st;
        reverse(all(st2));
        st.pop_back();
        st = st + st2;
        ll pal = stoll(st);
        if(pal >= a && pal <= b && prime(pal)) ans++;
    }
    if(currlen <= maxlen / 2) {
        string st = to_string(curr);
        string st2 = st;
        reverse(all(st2));
        st = st + st2;
        ll pal = stoll(st);
        if(pal >= a && pal <= b && prime(pal)) ans++;
    } 
    if(currlen > (maxlen + 1) / 2) return 0;

    for(int i = 0; i < 10; i++) {
        curr *= 10;
        curr += i;
        ans += rec(curr, maxlen, currlen + 1, a, b);
        curr /= 10;
    }

    return ans;
}

void solve() {
    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    ll len = to_string(b).size();
    for(int i = 1; i < 10; i++) {
        ans += rec(i, len, 1, a, b);
    }

    cout << ans;
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
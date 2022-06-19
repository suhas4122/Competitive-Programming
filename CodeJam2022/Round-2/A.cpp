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

#define for0(n) for (long long i = 0; i < (long long)(n); ++i)             // 0 based indexing
#define for0j(n) for (long long j = 0; j < (long long)(n); ++j)            // 0 based indexing
#define for1(n) for (long long i = 1; i <= (long long)(n); ++i)            // 1 based indexing
#define for1j(n) for (long long j = 1; j <= (long long)(n); ++j)           // 1 based indexing
#define forc(l, r) for (long long i = (long long)(l); i <= (int)(r); ++i)  // closed interver from l to r r inclusive
#define forr0(n) for (long long i = (long long)(n)-1; i >= 0; --i)         // reverse 0 based.
#define forr1(n) for (long long i = (long long)(n); i >= 1; --i)           // reverse 1 based

#define ini(x) \
    ll x;      \
    cin >> x;
#define ini2(x, y) \
    ll x, y;       \
    cin >> x >> y;
#define inia(arr, n) \
    ll arr[n];       \
    for0(n) cin >> arr[i];

#define pb push_back
#define fi first
#define se second
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end()   // Forward traversal
#define rall(x) (x).rbegin, (x).rend()  // reverse traversal
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c, i) for (__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c, x) ((c).find(x) != (c).end())
// find version works for all containers. This is present in std namespace.
#define cpresent(c, x) (find(all(c), x) != (c).end())
// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

ll mod(ll n);
ll gcd(ll a, ll b);
ll modM(ll n, ll m);
ll modA(ll n, ll m);
ll modS(ll n, ll m);
ll power(ll a, ll b);
ll inv(ll a, ll mod);

const long long int N = 1e9 + 7;
vector<vector<int>> a;
vector<int> path;
vector<pair<int, int>> ans;

ll n, k;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(ll x, ll y, ll i, ll j, ll l, vector<vector<int>> &a, vector<vector<vector<int>>> &dp) {
    if (x >= 0 && x < n && y >= 0 && y < n && dp[x][y][l - 1] && a[x][y] < a[i][j])
        return true;
    return false;
}

void solve() {
    n, k;
    cin >> n >> k;
    ll moves = n / 2 + n / 2;
    if (moves > k) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int t = 0, l = 0, r = n - 1, b = n - 1;
    int d = 0, count = 1;
    a.assign(n, vector<int>(n));
    while (t <= b && l <= r) {
        if (d == 0) {
            for (int i = l; i <= r; i++) {
                a[t][i] = count;
                count++;
            }
            d = 1;
            t++;
        } else if (d == 1) {
            for (int i = t; i <= b; i++) {
                a[i][r] = count;
                count++;
            }
            d = 2;
            r--;
        } else if (d == 2) {
            for (int i = r; i >= l; i--) {
                a[b][i] = count;
                count++;
            }
            d = 3;
            b--;
        } else if (d == 3) {
            for (int i = b; i >= t; i--) {
                a[i][l] = count;
                count++;
            }
            d = 0;
            l++;
        }
    }

    vector<vector<vector<int>>> dp;
    vector<vector<vector<pair<int, int>>>> par(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(k + 1, {-1, -1})));
    dp.assign(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));
    for (int l = 0; l <= k; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][l] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int l = 1; l <= k; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 || j != 0) {
                    for (int dir = 0; dir < 4; dir++) {
                        int x = i + dx[dir], y = j + dy[dir];
                        if (check(x, y, i, j, l, a, dp)) {
                            dp[i][j][l] = 1;
                            par[i][j][l] = {x, y};
                        }
                    }
                }
            }
        }
    }
    if (dp[n / 2][n / 2][k] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    pair<int, int> p;
    p = make_pair(n / 2, n / 2);
    vector<int> path;
    l = k;
    while (p.fi != -1 && p.se != -1) {
        path.push_back(a[p.fi][p.se]);
        p = par[p.fi][p.se][l--];
    }
    ans.clear();
    reverse(all(path));
    for (int i = 0; i < path.size() - 1; i++) {
        if (path[i] != path[i + 1] - 1) {
            ans.push_back({path[i], path[i + 1]});
        }
    }
    int m = ans.size();
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ans[i].fi << " " << ans[i].se << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;

    ll t;
    cin >> t;
    int i = 1;

    while (t--) {
        cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll mod(ll n) { return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = modM(res, a);
        }
        a = modM(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    ll b = mod, u = 0, v = 1;
    while (a) {
        ll t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += mod;
    return u;
}
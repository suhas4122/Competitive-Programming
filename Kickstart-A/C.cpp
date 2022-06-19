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

void solve1() {
    ll n;
    cin >> n;
    vvll gr(n);
    vpll edges;
    for0(n - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        edges.pb({a, b});
        gr[a].pb(b);
        gr[b].pb(a);
    }
    ll straight = 1;
    ll head = 0;
    for0(n) {
        if (gr[i].size() != 1 && gr[i].size() != 2) {
            straight = 0;
            ;
        }
        if (gr[i].size() == 1) head = i;
    }
    if (!straight) {
        cout << "-1\n";
        return;
    }
    map<pll, ll> m;
    vll visited(n, 0);
    visited[head] = 1;
    ll flag = 0;
    for0(n) {
        for (auto x : gr[head]) {
            if (visited[x] == 0) {
                m[{head, x}] = 2 + flag;
                visited[x] = 1;
                head = x;
                flag = 1 - flag;
            }
        }
    }
    // pr(m);
    for (auto x : edges) {
        if (m[x] != 0) {
            cout << m[x] << " ";
        } else {
            cout << m[{x.se, x.fi}] << " ";
        }
    }
    cout << "\n";
}

void solve3() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    for1(n) {
        for1j(m) {
            ll x, y;
            if (n % 2 == 1) {
                x = abs(i - (n + 1) / 2);
            } else {
                x = min(abs(i - (n / 2)), abs(i - (n / 2 + 1)));
            }
            if (m % 2 == 1) {
                y = abs(j - (m + 1) / 2);
            } else {
                y = min(abs(j - (m / 2)), abs(j - (m / 2 + 1)));
            }
            mp[x + y]++;
        }
    }
    ll ans = n / 2 + m / 2;
    for (auto &x : mp) {
        for0(x.se) {
            cout << ans << " ";
        }
        ans++;
    }
    cout << "\n";
}

bool ispali(string s) {
    assert(sz(s) == 5 || sz(s) == 6);
    for (int i = 0, j = sz(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

bool rec(string s, int i, int n) {
    if (i != n) {
        if (s[i] != '?') return rec(s, i + 1, n);
        string s0 = s;
        s0[i] = '0';
        string s1 = s;
        s1[i] = '1';
        return rec(s1, i + 1, n) || rec(s0, i + 1, n);
    }
    for (int i = 0; i + 4 < n; i++) {
        if (ispali(s.substr(i, 5))) {
            return 0;
        }
    }
    for (int i = 0; i + 5 < n; i++) {
        if (ispali(s.substr(i, 6))) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    string s;
    int n;
    cin >> n >> s;
    if (rec(s, 0, n))
        cout << "POSSIBLE\n";
    else
        cout << "IMPOSSIBLE\n";
}

void solve2() {
    ll N;
    cin >> N;
    vll nums(N);
    for0(N) cin >> nums[i];
    int mx = *max_element(nums.begin(), nums.end());

    // boolean vector to check existence
    vector<bool> exists(mx + 1, false);
    for (int x : nums)
        exists[x] = true;

    int res = 0;
    for (int i = 1; i <= mx; i++) {
        int gcd = 0;
        // find the GCD of multiples of i that exist in nums
        for (int j = i; j <= mx; j += i)
            if (exists[j])
                gcd = __gcd(gcd, j);
        if (gcd == i)  // increment result if i is the GCD
            res++;
    }
    cout << res - N << "\n";
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
        cout << "Case #" << i << ": ";
        i++;
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
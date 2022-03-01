#include <bits/stdc++.h>  // This will work only for g++ compiler. 
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

#define for0(n) for (long long i = 0; i < (long long)(n); ++i) // 0 based indexing
#define for0j(n) for (long long j = 0; j < (long long)(n); ++j) // 0 based indexing
#define for1(n) for (long long i = 1; i <= (long long)(n); ++i) // 1 based indexing
#define for1j(n) for (long long j = 1; j <= (long long)(n); ++j) // 1 based indexing
#define forc(l, r) for (long long i = (long long)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(n) for (long long i = (long long)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(n) for (long long i = (long long)(n); i >= 1; --i) // reverse 1 based

#define ini(x) ll x; cin >> x;
#define ini2(x, y) ll x, y; cin >> x >> y;
#define inia(arr, n) ll arr[n]; for0(n) cin >> arr[i];

#define pb push_back
#define ff first
#define ss second
// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())
//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())
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
int query(int x) {
    cout << x << endl;
    int v;
    cin >> v;
    return v;
}

int n;
using pii = pair<int, int>;
vector<vector<pii>> g;
vector<int> col;
ll prv = -1;

struct barrett_reduction {
    unsigned mod;
    uint64_t div;
 
    barrett_reduction(unsigned m) : mod(m), div(-1LLU / m) {}
 
    unsigned operator()(uint64_t a) const {
#ifdef __SIZEOF_INT128__
        uint64_t q = uint64_t(__uint128_t(div) * a >> 64);
        uint64_t r = a - q * mod;
        return unsigned(r < mod ? r : r - mod);
#endif
        return unsigned(a % mod);
    }
};

template<const int &MOD, const barrett_reduction &barrett>
struct _b_int {
    int val;
 
    _b_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _b_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _b_int(int v) : _b_int(int64_t(v)) {}
    _b_int(unsigned v) : _b_int(uint64_t(v)) {}
 
    static int inv_mod(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _b_int& operator+=(const _b_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _b_int& operator-=(const _b_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x) {
#if !defined(_WIN32) || defined(_WIN64)
        return barrett(x);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * MOD for this to work, so that x / MOD fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (MOD));
        return rem;
    }
 
    _b_int& operator*=(const _b_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _b_int& operator/=(const _b_int &other) {
        return *this *= other.inv();
    }
 
    friend _b_int operator+(const _b_int &a, const _b_int &b) { return _b_int(a) += b; }
    friend _b_int operator-(const _b_int &a, const _b_int &b) { return _b_int(a) -= b; }
    friend _b_int operator*(const _b_int &a, const _b_int &b) { return _b_int(a) *= b; }
    friend _b_int operator/(const _b_int &a, const _b_int &b) { return _b_int(a) /= b; }
 
    _b_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _b_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _b_int operator++(int) { _b_int before = *this; ++*this; return before; }
    _b_int operator--(int) { _b_int before = *this; --*this; return before; }
 
    _b_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _b_int &a, const _b_int &b) { return a.val == b.val; }
    friend bool operator!=(const _b_int &a, const _b_int &b) { return a.val != b.val; }
    friend bool operator<(const _b_int &a, const _b_int &b) { return a.val < b.val; }
    friend bool operator>(const _b_int &a, const _b_int &b) { return a.val > b.val; }
    friend bool operator<=(const _b_int &a, const _b_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _b_int &a, const _b_int &b) { return a.val >= b.val; }
 
    _b_int inv() const {
        return inv_mod(val);
    }
 
    _b_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _b_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _b_int &m) {
        return os << m.val;
    }
 
    friend istream& operator>>(istream &is, _b_int &m) {
        int64_t x;
        is >> x;
        m = x;
        return is;
    }
};

void solve11() {
    ll n;
    cin >> n;
    ll arr[n];
    for0(n) cin >> arr[i];
    vll maxi(n);
    maxi[0] = arr[0];
    for(int i = 1; i < n; i++){
        maxi[i] = max(maxi[i-1], arr[i]);
    }
    ll mini = 1e18;
    vll ind;
    for(int i = n-1; i>=1; i--){
        mini = min(mini, arr[i]);
        if(maxi[i-1] <= mini) ind.pb(i);
    }
    ind.pb(0);
    reverse(all(ind));
    ind.pb(n);
    // pr(ind);
    sort(arr, arr+n);
    ll ans = 0;
    ll m = ind.size();
    for0(m-1){
        ans += arr[ind[i+1]-1] - arr[ind[i]];
    }
    cout << ans << endl;
}
int dfs(int nn, int pp) {
    bool lf = 1;
    int cnt1 = 0, cnt2 = 0;
    for (auto& v : g[nn]) {
        if (v.ff == pp)
            continue;
        lf = 0;
        v.ss = dfs(v.ff, nn);
        if (v.ss)
            cnt1++;
        else
            cnt2++;
    }
    if (pp == -1)  // root
        return 0;
    int q = query(nn);
    if (prv == -1) {
        prv = q;
        q = query(nn);
    }
    int change = q - prv;
    prv = q;
    int exp_ch = cnt2 - cnt1;
    if (change - exp_ch == -1) {
        return 0;
    } else if (change - exp_ch == 1)
        return 1;
    else {
        cout << "error\n" << endl;
    }
}

void dfs2(int nn, int pp) {
    for (auto v : g[nn]) {
        if (v.ff == pp)
            continue;
        if (pp != -1)
            v.ss = !v.ss;
        col[v.ff] = v.ss ^ col[nn];
        dfs2(v.ff, nn);
    }
}

void solve() {
    int q;
    cin >> n >> q;
    g = vector<vector<pii>>(n + 1);
    col = vector<int>(n + 1);
    prv = -1;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, -1});
        g[y].push_back({x, -1});
    }
    col[1] = 1;
    dfs(1, -1);
    dfs2(1, -1);
    int w = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i])
            b++;
        else
            w++;
    }
    if (w < b) {
        for (int i = 1; i <= n; i++) {
            if (!col[i])
                query(i);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (col[i])
                query(i);
        }
    }
    cout << 0 << endl;
    int v;
    cin >> v;
}

int main() {
  	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;

    ll t;
    cin >> t;
    
    while(t--){
    	solve();
    }
    return 0;
}


ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll mod(ll n) {return (n % N + N) % N; }
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
        b -= t * a; swap(a, b);
        u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += mod;
    return u; 
}

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

#define MAX_N 26

struct Matrix {  // Fibonacci (and related) Matrix

    int a[MAX_N][MAX_N];

    Matrix() {
        memset(a, 0, sizeof a);
    }

    void reset() {
        memset(a, 0, sizeof a);
    }

    void Identity() {
        reset();
        for (int i = 0; i < MAX_N; i++) {
            a[i][i] = 1;
        }
    }

    Matrix operator+(const Matrix &o) const {
        Matrix res;
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                res.a[i][j] = modA(a[i][j], o.a[i][j]);
            }
        }
        return res;
    };

    Matrix operator*(const Matrix &o) const {
        Matrix res;
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                res.a[i][j] = 0;
                for (int k = 0; k < MAX_N; k++) {
                    res.a[i][j] = modA(res.a[i][j], modM(a[i][k], o.a[k][j]));
                }
            }
        }
        return res;
    };

    void print(Matrix a) {
        for (int i = 0; i < MAX_N; i++) {
            for (int j = 0; j < MAX_N; j++) {
                cout << a.a[i][j] << " \n"[j == MAX_N - 1];
            }
        }
    }

    Matrix power(Matrix a, int n) {
        Matrix res;
        res.Identity();
        while (n) {
            if (n & 1)
                res = res * a;
            a = a * a;
            n /= 2;
        }
        return res;
    }
};

struct Matrix {
    vector<vector<ll>> a;
    int n;

    Matrix(int sza, vector<vector<ll>> vec) {
        n = sza;
        a = vec;
    }

    Matrix operator+(const Matrix &o) const {
        vector<vector<ll>> res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = modA(a[i][j], o.a[i][j]);
            }
        }
        return Matrix(n, res);
    };

    Matrix operator*(const Matrix &o) const {
        vector<vector<ll>> res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    res[i][j] = modA(res[i][j], modM(a[i][k], o.a[k][j]));
                }
            }
        }
        return Matrix(n, res);
    };

    Matrix exp(ll m) {
        vector<vector<ll>> res(n, vll(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        Matrix out(n, res);
        Matrix temp = (*this);
        while (m) {
            if (m & 1) {
                out = out * temp;
            }
            temp = temp * temp;
            m /= 2;
        }
        return out;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mat(26, vector<ll>(26, 0));
    for (int i = 0; i < m; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        mat[c1 - 'a'][c2 - 'a'] = 1;
        mat[c2 - 'a'][c1 - 'a'] = 1;
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                mat[i][j] |= (mat[i][k] & mat[k][j]);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            mat[i][j] = 1 - mat[i][j];
        }
    }

    for (int i = 0; i < 26; i++) {
        mat[i][i] = 1;
    }

    Matrix ma(26, mat);
    Matrix out = ma.exp(n - 1);

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ans = modA(ans, out.a[i][j]);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;

    ll t = 1;
    // cin >> t;

    while (t--) {
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
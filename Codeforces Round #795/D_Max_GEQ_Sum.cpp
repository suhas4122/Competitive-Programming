#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(char s) { return string(1, s); }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
    bool f = 1;
    string r = "{";
    for (const auto& x : v) {
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

struct SegmentTree {
    vll tree;
    vll arr;
    ll n;
    SegmentTree(ll size) {
        n = size;
        tree.assign(4 * (n + 1), {});
        arr.assign(n + 1, {});
    }
    void merge(ll& ni, ll& nj, ll& nk) {
        ni = max(nj, nk);
    }
    void build_tree(ll i, ll l, ll r) {
        if (l == r) {
            tree[i] = arr[l];
        } else {
            ll mid = (l + r) / 2;
            build_tree(2 * i, l, mid);
            build_tree(2 * i + 1, mid + 1, r);
            merge(tree[i], tree[2 * i], tree[2 * i + 1]);
        }
    }
    void update_tree(ll i, ll l, ll r, ll x, ll v) {
        if (x < l || x > r)
            return;
        if (l == r) {
            tree[i] = v;
            arr[l] = v;
            return;
        }
        ll mid = (l + r) / 2;
        update_tree(2 * i, l, mid, x, v);
        update_tree(2 * i + 1, mid + 1, r, x, v);
        merge(tree[i], tree[2 * i], tree[2 * i + 1]);
    }
    ll query_tree(ll i, ll l, ll r, ll lq, ll rq) {
        if (l > rq || r < lq)
            return -1e18;  // ref notes
        if (l >= lq && rq >= r) {
            return tree[i];
        } else {
            ll mid = (l + r) / 2;
            return max(query_tree(2 * i, l, mid, lq, rq), query_tree(2 * i + 1, mid + 1, r, lq, rq));
        }
    }
    // make changes accordingly here (can be 1,0,n-1) also
    void build() { build_tree(1, 0, n - 1); }
    void update(ll x, ll v) { update_tree(1, 0, n - 1, x, v); }
    ll query(ll lq, ll rq) { return query_tree(1, 0, n - 1, lq, rq); }
    // Note: always remember that while querying the part that is out of range but still being queried should be handled by care and not simply 0 value (eg. bitwise and of some range [l,r])
};

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for0(n) {
        cin >> a[i];
    }
    vll rmax(n, n);
    stack<ll> st2;
    for (int i = n - 1; i >= 0; i--) {
        while (true) {
            if (!st2.empty() && a[i] >= a[st2.top()])
                st2.pop();
            else
                break;
        }
        if (!st2.empty()) {
            rmax[i] = st2.top();
        }
        st2.push(i);
    }
    vll lmax(n, -1);
    stack<ll> st1;
    for0(n) {
        while (true) {
            if (!st1.empty() && a[i] >= a[st1.top()])
                st1.pop();
            else 
                break;
        }
        if (!st1.empty()) {
            lmax[i] = st1.top();
        }
        st1.push(i);
    }
    vll pref(n, 0);
    for0(n) {
        if (i == 0) {
            pref[i] = a[i];
        } else if (i > 0) {
            pref[i] = a[i] + pref[i - 1];
        }
    }
    vll suff(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suff[i] = a[i];
        } else if (i < n - 1) {
            suff[i] = a[i] + suff[i + 1];
        }
    }

    SegmentTree prefix_max(n);
    prefix_max.arr = pref;
    prefix_max.build();

    SegmentTree suffix_max(n);
    suffix_max.arr = suff;
    suffix_max.build();

    for0(n) {
        if (a[i] > 0) {
            ll l = lmax[i];
            ll r = rmax[i];
            ll qr = prefix_max.query(i, r - 1);
            qr -= pref[i];
            ll ql = suffix_max.query(l + 1, i);
            ql -= suff[i];
            if (qr + ql > 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;

    ll t;
    cin >> t;

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
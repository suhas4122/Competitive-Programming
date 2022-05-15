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
#define int long long

const int mxn = 420;
ll dp[mxn][mxn][2];  // 0 - left, 1 - right
vector<ll> a;
ll d;

vector<ll> factors(ll x) {
    vector<ll> result;
    ll i = 1;

    while (i * i <= x) {
        if (x % i == 0) {
            result.push_back(i);
            if (x / i != i) {
                result.push_back(x / i);
            }
        }
        i++;
    }

    return result;
}

bool check_palindrome(ll n) {
    ll rev = 0;
    ll temp = n;
    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev == n;
}

void trial() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == 'D')
        for (char& c : s)
            c = (c == 'D') ? 'R' : 'D';

    ll a = 0, b = 0, k = 0;
    for (char c : s) a += c == 'R';
    for (char c : s) b += c == 'D';
    while (k < s.size() && s[k] == 'R') k++;

    ll ans = n * n;
    if (b == 0) {
        ans = n;
    } else {
        ans -= k * (n - 1 - b) + a * b;
    }
    cout << ans << '\n';
}

ll rec(int l, int r, int dim) {
    if (l != r) {
        if (dp[l][r][dim] < LLONG_MAX) {
            return dp[l][r][dim];
        } else {
            ll val;
            if (dim == 0) {
                ll temp = LLONG_MAX;

                ll mx = max(a[l], a[l + 1]), mn = min(a[l], a[l + 1]);
                temp = abs(mx - mn);
                temp = min(temp, abs(d - mx + mn));
                ll vl = rec(l + 1, r, 0) + temp;

                mx = max(a[l], a[r]), mn = min(a[l], a[r]);
                temp = abs(mx - mn);
                temp = min(temp, abs(d - mx + mn));
                ll vr = rec(l + 1, r, 1) + temp;

                dp[l][r][dim] = min(vl, vr);
                return dp[l][r][dim];

            } else {
                ll temp = LLONG_MAX;

                ll mx = max(a[r], a[l]);
                ll mn = min(a[r], a[l]);
                temp = abs(mx - mn);
                temp = min(temp, abs(d - mx + mn));
                ll vl = rec(l, r - 1, 0) + temp;

                mx = max(a[r], a[r - 1]);
                mn = min(a[r], a[r - 1]);
                temp = abs(mx - mn);
                temp = min(temp, abs(d - mx + mn));
                ll vr = rec(l, r - 1, 1) + temp;

                dp[l][r][dim] = min(vl, vr);
                return dp[l][r][dim];
            }
        }
    }
    return 0;
}

void HFHF() {
    ll n;
    cin >> n >> d;
    for (int i = 0; i <= n + 5; i++) {
        for (int j = 0; j <= n + 5; j++) {
            dp[i][j][0] = dp[i][j][1] = LLONG_MAX;
        }
    }
    a.resize(n + 2);
    a[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 0;
    a.erase(unique(all(a)), a.end());
    n = a.size();

    ll ans = rec(0, n - 1, 0);
    ans = min(ans, rec(0, n - 1, 1));
    cout << ans << endl;
}

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> b(r);
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }
    if (c == 1) {
        string ans = "E" + string(2 * r - 1, 'S') + "W" + string(2 * r - 1, 'N');
        cout << ans << '\n';
        return;
    }

    string ans = "E";
    for (int i = 0; i < (r >> 1); i++) {
        ans += string(2 * c - 2, 'E');
        ans += "S";

        for (int j = 0; j < (c + 1) / 2 - 1; j++) {
            if (c % 2 == 0 || j > 0) {
                ans += "WWSSWNNW";
            } else
                ans += "SSWNNW";
        }
        ans += "WWSS";
        if (i != (r >> 1) - 1 || (r % 2 == 1)) ans += 'S';
    }
    if (r % 2 == 0) {
        ans += "W" + string(2 * r - 1, 'N');
    } else {
        ans += string(2 * c - 2, 'E') + "S" + string(2 * c - 1, 'W');
        ans += string(2 * r - 1, 'N');
    }
    cout << ans << '\n';
}

signed main() {
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
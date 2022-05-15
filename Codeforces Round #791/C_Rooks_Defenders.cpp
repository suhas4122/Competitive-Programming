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
#define fi first
#define se second
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
const int MAXN = 1e5 + 5;

ll nx, tx[4*MAXN];

void buildx(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        tx[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        buildx(a, v*2, tl, tm);
        buildx(a, v*2+1, tm+1, tr);
        tx[v] = tx[v*2] + tx[v*2+1];
    }
}

ll sumx(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return tx[v];
    }
    ll tm = (tl + tr) / 2;
    return sumx(v*2, tl, tm, l, min(r, tm))
           + sumx(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void updatex(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        tx[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            updatex(v*2, tl, tm, pos, new_val);
        else
            updatex(v*2+1, tm+1, tr, pos, new_val);
        tx[v] = tx[v*2] + tx[v*2+1];
    }
}

ll ny, ty[4*MAXN];

void buildy(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        ty[v] = a[tl];
    } else {
        ll tm = (tl + tr) / 2;
        buildy(a, v*2, tl, tm);
        buildy(a, v*2+1, tm+1, tr);
        ty[v] = ty[v*2] + ty[v*2+1];
    }
}

ll sumy(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return ty[v];
    }
    ll tm = (tl + tr) / 2;
    return sumy(v*2, tl, tm, l, min(r, tm))
           + sumy(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void updatey(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr) {
        ty[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            updatey(v*2, tl, tm, pos, new_val);
        else
            updatey(v*2+1, tm+1, tr, pos, new_val);
        ty[v] = ty[v*2] + ty[v*2+1];
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    ll ax[n+1];
    ll ay[n+1];
    for0(n + 1) {
        ax[i] = ay[i] = 0;
    }
    buildx(ax, 1, 1, n);
    buildy(ay, 1, 1, n);
    for0(q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll x, y;
            cin >> x >> y;
            ax[x] += 1;
            ay[y] += 1;
            if(ax[x] == 1) {
                updatex(1, 1, n, x, 1);
            } 
            if(ay[y] == 1) {
                updatey(1, 1, n, y, 1);
            }
        } else if(t == 2) {
            ll x, y;
            cin >> x >> y;
            ax[x] -= 1;
            ay[y] -= 1;
            if(ax[x] == 0) {
                updatex(1, 1, n, x, 0);
            } 
            if(ay[y] == 0) {
                updatey(1, 1, n, y, 0);
            }
        } else {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll row = sumx(1, 1, n, x1, x2);
            ll col = sumy(1, 1, n, y1, y2);
            if(row >= x2 - x1 + 1 || col >= y2 - y1 + 1) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;

    ll t = 1;
    // cin >> t;
    
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
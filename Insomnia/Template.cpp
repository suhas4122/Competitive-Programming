#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

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



int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> dp(n+1), a(n+1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }

    function<void(int,int)> dfs = [&](int s,int p) {
        dp[s] = 0;
        for(auto &j:g[s]) {
            if(j != p) {
                dfs(j, s);
                if(a[j] < a[s]) {
                    dp[s] += dp[j] + 1;
                }
            }
        }
    };  
    dfs(1, 0);
    ll ans = 0;
    // debug(dp);
    function<void(int,int,int)> dfs2 = [&](int s,int p, int sed) {
        pr(ans, s, p, sed);
        vector<ll> dps;
        if(p > 0 && a[p] < a[s]) {
            dps.push_back(dp[p] + 1);
            dp[s] += dp[p] + 1;
        }
        for(auto &j:g[s]) {
            if(j != p) {
                if(a[j] < a[s]) {
                    dps.push_back(dp[j] + 1);
                }
                dfs2(j, s, sed);
            }
        }
        // debug(s,dps);
        ll sum = 0;
        for(auto &j:dps) {
            ans += sum * j;
            sum += j;
        }
        ans += dp[s] * sed;
         pr(ans, s, p, sed);
    };
    dfs2(1, 0, 1);
    // debug(dp);
    // for(int i=1;i<=n;++i) {
    //     a[i] = -a[i];
    // }
    // dfs(1, 0);
    // // debug(dp);
    // dfs2(1, 0, 0);
    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}
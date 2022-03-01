#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define cerr cout
#define endl '\n'

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

typedef long long ll;
const ll MOD = 1000000007;
const int INF = (int)1e9 + 5;

ll binpow(ll b, ll p){ ll ans = 1; while(p > 0){if(p & 1) ans = (ans * b) % MOD; b = (b * b) % MOD; p >>= 1;}return ans;}
ll modinv(ll x){return binpow(x % MOD, MOD - 2);}

int np(int n) {
    int count = 0; 
    if (n && !(n & (n - 1))) 
        return n; 
    
    while(n != 0) 
    { 
        n >>= 1; 
        count += 1; 
    } 
    
    return (1 << count); 
}

void solve()
{
    int nn;
    cin >> nn;
    int tot = nn;
    map<int, int> cnt;
    vector<int> a(nn);
    for(auto &x : a) {
        cin >> x;
        cnt[x]++;
    }
    sort(all(a));

    auto it = unique(all(a));
    a.resize(distance(a.begin(), it));
    int n = sz(a);
    vector<int> pref(n+1);
    pref.push_back(0);
    for(int i = 0; i < n; i++) {
        if(i) {
            pref[i+1] = pref[i] + cnt[a[i]];
        }
        else {
            pref[i+1] = cnt[a[i]];
        }
    }

    int x = 1;
    vector<int> pows;
    pows.push_back(0);
    while(x <= 2 * n) {
        pows.push_back(x);
        x *= 2; 
    }

    // pr(pows);
    // pr(pref);

    int ans = INT_MAX;
    for(int i = 0; i < sz(pows); i++) {
        for(int j = 0; j < sz(pows); j++) {
            int temp = 0;
            auto it = upper_bound(all(pref), pows[i]);
            // pr(*it);
            int v = 0, ind1 = -1, ind2 = -1, v2 = 0;
            if(it != pref.begin()) {
                it--;
                ind1 = it - pref.begin();
                // pr(ind1);
                v = pref[ind1];
            }
            temp += pows[i] - v;

            it = upper_bound(all(pref), v + pows[j]);
            if(it != pref.begin()) {
                it--;
                ind2 = it - pref.begin();
                v2 = pref[ind2] - v;
            }
            temp += pows[j] - v2;
            // if(j == 0) temp++

            int left = tot - v - v2;
            int xx = np(left) - left;
            temp += xx;
            
            ans = min(ans, temp);
        }
    }
    
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    cin >> t;
    for(i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
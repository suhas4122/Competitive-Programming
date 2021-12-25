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
#define pr(...) cerr << "[" << # __VA_ARGS__ << "] :", debug_out(_VA_ARGS_)

#define debarr(a, n) cerr << #a << " : "; for(int i = 0; i < n; i++) cerr << a[i] << " "; cerr << endl;
#define debmat(mat, row, col) cerr << #mat << " :\n"; for(int i = 0; i < row; i++){for(int j = 0; j < col; j++) cerr << mat[i][j] << " "; cerr << endl;}

typedef long long ll;
const ll N = 1000000007;
const int INF = (int)1e9 + 5;

ll binpow(ll b, ll p){ ll ans = 1; while(p > 0){if(p & 1) ans = (ans * b) % N; b = (b * b) % N; p >>= 1;}return ans;}


ll mod(ll n) {return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }


void solve(){

    ll k, i;
    string u;
    cin >> k;
    cin >> u;
    ll ans = 0, len = 0, sumab = 0, suma = 0, pairs = 0, lastind = -1, firstind = -1;
    ll c = 0;
    char lastchar = 'A', first = 'A';
    for(i = 0; i < k; i++) {
        if(u[i] == 'X' || u[i] == 'O') {
            first = u[i];
            break;
        }
    }
    vector<ll> nextdot(k, 0);
    ll last = k;
    for(i = k - 1; i >= 0; i--) {
        if(u[i] == '.') {
            last = i;
        }
        nextdot[i] = last - i;
    }
    bool dotok = 0;
    for(i = 0; i < k; i++) {
        if(u[i] == '.') {
            dotok = 1;
            ans = modM(ans, 2);
            ll temp = modM(sumab, len);
            ans = modA(ans, temp);
            sumab = modM(sumab, 2);
            sumab = modA(sumab, 2 * len%N * pairs%N);
            suma = modM(suma, 2);
            temp = modM(pairs, len);
            suma = modA(suma, temp);
            pairs = modM(pairs, 2);
            
            if((lastchar == 'X' && first == 'O') || (lastchar == 'O' && first == 'X')) {
                ll a = lastind + 1;
                ll b = modS(len, firstind);
                sumab = modA(sumab, a + b);
                suma = modA(suma, a);
                temp = modM(a, b);
                ans = modA(ans, temp);
                pairs = modA(pairs, 1);
            }

            lastind += len;

            if(i + 1 < k) {
                int temp = modM(pairs, nextdot[i + 1]);
                sumab = modA(sumab, temp);
                temp = modM(suma, nextdot[i+1]);
                ans = modA(ans, temp);
            }

            len = modM(len, 2);
        }
        else if(u[i] == 'F') {
            len++;
        }
        else if(u[i] == 'O') {
            if(firstind == -1) {
                firstind = len;
            }
            if(lastchar == 'X') {
                pairs++;
                ll a = lastind + 1;
                ll b = nextdot[i];
                int temp = modM(a, b);
                ans = modA(ans, temp);
                sumab = modA(sumab, a + b);
                suma = modA(suma, a);
            }
            lastchar = 'O';
            lastind = len;
            len++;
            c++;
        }
        else if(u[i] == 'X') {
            if(firstind == -1) {
                firstind = len;
            }
            if(lastchar == 'O') {
                pairs++;
                ll a = lastind + 1;
                ll b = nextdot[i];
                int temp = modM(a, b);
                ans = modA(ans, temp);
                sumab = modA(sumab, a + b);
                suma = modA(suma, a);
            }
            lastchar = 'X';
            lastind = len;
            len++;
        }
        sumab = mod(sumab);
        suma = mod(suma);
        len = mod(len);
        pairs = mod(pairs);
        lastind = mod(lastind);
        ans = mod(ans);
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
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
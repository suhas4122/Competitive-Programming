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

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> arr(n), prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i)
            prefix[i] = prefix[i - 1] + arr[i];
        else
            prefix[i] = arr[i];
    }

    ll head = -1, tail = 0;
    multiset<ll> mst;
    ll odd = 0, best = -1e18;

    while (tail < n) {
        while (head < n - 1 &&
               ((odd < k && arr[head + 1] % 2) ||
                (odd <= k && arr[head + 1] % 2 == 0))) {
            head++;
            if (arr[head] % 2) odd++;
            mst.insert(prefix[head]);
        }

        ll temp = d + (tail > 0 ? prefix[tail - 1] : 0);
        auto it = mst.upper_bound(temp);
        if(it != mst.begin()) {
            it--;
            best = max(best, *it - (tail > 0 ? prefix[tail - 1] : 0));
        }
        if(head < tail) {
            tail++;
            head = tail - 1;
        } else {
            if(arr[tail] % 2) {
                odd--;
            }
            mst.erase(mst.find(prefix[tail]));
            tail++;
        }
    }

    if(best != -1e18) {
        cout << best << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

signed main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    cin >> t;
    for (i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
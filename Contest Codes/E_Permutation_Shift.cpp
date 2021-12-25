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
ll modinv(ll x){return binpow(x, MOD - 2);}
int minSwaps(int arr[], int n)
{
    // Create an array of
    // pairs where first
    // element is array element
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
    // Sort the array by array
    // element values to
    // get right position of
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);
 
    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);
 
    // Initialize result
    int ans = 0;
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle.
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

void solve()
{
    int n, m, i, k;
    set<int> ans, ans1;
    cin >> n >> m;
    deque<int> a;
    int arr[n];
    for(i = 0; i < n; i++) {
        cin >> arr[i];
        a.push_back(arr[i]);
    }
    map<int, int> mp;
    for(int i = 0; i<n; i++){
        int c = (n + i + 1 - a[i])%n;
        mp[c]++;
    }
    for(auto x: mp){
        if(x.ss >= n-2*m)
            ans.insert(x.ff);
    }
    for(auto x: ans){
        int array[n];
        for(int i = 0; i<n; i++){
            array[i] = arr[(i+x)%n];
        }
        // debarr(array, n);
        if(minSwaps(array, n) <= m)
            ans1.insert(x);
    }
    cout << sz(ans1);
    for(auto x : ans1) {
        cout << " " << x;
    }
    cout << endl;
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
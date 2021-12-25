#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
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

typedef pair<ll, ll> Point;
Point p;
ll n;
long double ans = 1e18;
vector<Point> arr;

long double area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

ll cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
}

long double dist(Point a, Point b)
{
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double perimeter(vector<Point> ans)
{
    long double perimeter = 0.0;
  
    // Find the distance between adjacent Points
    for (ll i = 0; i < ans.size() - 1; i++) {
        perimeter += dist(ans[i], ans[i + 1]);
    }
  
    // Add the distance between first and last Point
    perimeter += dist(ans[0], ans[ans.size() - 1]);
  
    return perimeter;
}


void isInside(vector<Point> data, Point p)
{  
    ll x1 = data[0].x, y1 = data[0].y, x2 = data[1].x, y2 = data[1].y, x3 = data[2].x, y3 = data[2].y;
    ll x = p.x, y = p.y; 
    long double A = area (x1, y1, x2, y2, x3, y3);
    if(A == 0)
            return;
    long double A1 = area (x, y, x2, y2, x3, y3);
    long double A2 = area (x1, y1, x, y, x3, y3);
    long double A3 = area (x1, y1, x2, y2, x, y);
    // pr(A1, A2, A3);
    if(A1 + A2 + A3 != A)
        return;
    if(A1==0 && A2==0 || A2==0 && A3==0 || A3==0 && A1==0)
        return;
    if(A1 == 0) {
        for(int i = 0; i < n; i++) {
            ll v = cross_product(arr[i], data[1], data[2]);
            ll w = cross_product(data[0], data[1], data[2]);
            // pr(v, w);
            if(v * w < 0) {
                vector<Point> temp = {data[0], data[1], arr[i], data[2]};
                long double pt = perimeter(temp);
                ans = min(ans, pt);
            }
        }
    }
    else if(A2 == 0) {
        for(int i = 0; i < n; i++) {
            ll v = cross_product(arr[i], data[0], data[2]);
            ll w = cross_product(data[1], data[0], data[2]);
            if(v * w < 0) {
                vector<Point> temp = {data[1], data[0], arr[i], data[2]};
                long double pt = perimeter(temp);
                ans = min(ans, pt);
            }
        }
    }
    else if(A3 == 0) {
        for(int i = 0; i < n; i++) {
            ll v = cross_product(arr[i], data[0], data[1]);
            ll w = cross_product(data[2], data[0], data[1]);
            if(v * w < 0) {
                vector<Point> temp = {data[2], data[0], arr[i], data[1]};
                long double pt = perimeter(temp);
                ans = min(ans, pt);
            }
        }
    }
    else{
        ans = min(ans, perimeter(data));
    }
}

void combinationUtil(ll r, ll index, vector<Point> data, ll i){
    if (index == r) {
        pr(data);
        isInside(data, p);
    }
    if (i >= n)
        return;
    data[index] = arr[i];
    combinationUtil(r, index + 1, data, i + 1);
    combinationUtil(r, index, data, i + 1);
}

void solve(){
    cout << fixed << setprecision(10);
    ll i;
    
    cin >> n;
    arr.resize(n);
    for(i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    cin >> p.x >> p.y;
    vector<Point> data(3);

    for(int i = 0; i< n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                vector<Point> data = {arr[i], arr[j], arr[k]};
                isInside(data, p);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1, i;
    cin >> t;
    for(i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        if(ans == 1e18){
            cout << "IMPOSSIBLE\n";
        }
        else{
            cout << ans << "\n";
        }
        ans = 1e18;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// string to_string(string s) { return '"' + s + '"'; }
// string to_string(char s) { return string(1, s); }
// string to_string(const char* s) { return to_string((string)s); }
// string to_string(bool b) { return (b ? "true" : "false"); }
// template <typename A>
// string to_string(A);
// template <typename A, typename B>
// string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
// template <typename A>
// string to_string(A v) {
//     bool f = 1;
//     string r = "{";
//     for (const auto& x : v) {
//         if (!f) r += ", ";
//         f = 0;
//         r += to_string(x);
//     }
//     return r + "}";
// }
// void debug_out() { cerr << endl; }
// template <typename Head, typename... Tail>
// void debug_out(Head H, Tail... T) {
//     cerr << " " << to_string(H);
//     debug_out(T...);
// }
// #define pr(...) cerr << "[" << #__VA_ARGS__ << "] :", debug_out(__VA_ARGS__)
// #define debarr(a, n)                                 \
//     cerr << #a << " : ";                             \
//     for (int i = 0; i < n; i++) cerr << a[i] << " "; \
//     cerr << endl;
// #define debmat(mat, row, col)                                   \
//     cerr << #mat << " :\n";                                     \
//     for (int i = 0; i < row; i++) {                             \
//         for (int j = 0; j < col; j++) cerr << mat[i][j] << " "; \
//         cerr << endl;                                           \
//     }

// #define for0(n) for (long long i = 0; i < (long long)(n); ++i)             // 0 based indexing
// #define for0j(n) for (long long j = 0; j < (long long)(n); ++j)            // 0 based indexing
// #define for1(n) for (long long i = 1; i <= (long long)(n); ++i)            // 1 based indexing
// #define for1j(n) for (long long j = 1; j <= (long long)(n); ++j)           // 1 based indexing
// #define forc(l, r) for (long long i = (long long)(l); i <= (int)(r); ++i)  // closed interver from l to r r inclusive
// #define forr0(n) for (long long i = (long long)(n)-1; i >= 0; --i)         // reverse 0 based.
// #define forr1(n) for (long long i = (long long)(n); i >= 1; --i)           // reverse 1 based

// #define ini(x) \
//     ll x;      \
//     cin >> x;
// #define ini2(x, y) \
//     ll x, y;       \
//     cin >> x >> y;
// #define inia(arr, n) \
//     ll arr[n];       \
//     for0(n) cin >> arr[i];

// #define pb push_back
// #define fi first
// #define se second
// // to be used with algorithms that processes a container Eg: find(all(c),42)
// #define all(x) (x).begin(), (x).end()   // Forward traversal
// #define rall(x) (x).rbegin, (x).rend()  // reverse traversal
// // traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
// #define tr(c, i) for (__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
// // find if a given value is present in a container. Container version. Runs in log(n) for set and map
// #define present(c, x) ((c).find(x) != (c).end())
// // find version works for all containers. This is present in std namespace.
// #define cpresent(c, x) (find(all(c), x) != (c).end())
// // Avoiding wrap around of size()-1 where size is a unsigned int.
// #define sz(a) int((a).size())

// // Shorthand for commonly used types
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef long long ll;
// typedef pair<ll, ll> pll;
// typedef vector<pll> vpll;
// typedef vector<ll> vll;
// typedef vector<vll> vvll;
// typedef double ld;

// ll mod(ll n);
// ll gcd(ll a, ll b);
// ll modM(ll n, ll m);
// ll modA(ll n, ll m);
// ll modS(ll n, ll m);
// ll power(ll a, ll b);
// ll inv(ll a, ll mod);

// const long long int N = 1e9 + 7;

// struct DSU {
//     ll n, size;
//     vll arr, rank;

//     DSU(ll _) {
//         n = _;
//         size = _;
//         arr.assign(n, -1);
//         rank.assign(n, 1);
//     }

//     ll find(ll x) {
//         if (arr[x] == -1) {
//             return x;
//         }
//         return arr[x] = find(arr[x]);
//     }

//     void unite(ll x, ll y) {
//         ll x1 = find(x);
//         ll y1 = find(y);
//         if (x1 == y1) return;
//         if (rank[x1] > rank[y1]) swap(x1, y1);
//         arr[x1] = y1;
//         rank[y1] += rank[x1];
//         size--;
//     }
// };

// ll n, m;

// ll num(ll x, ll y) {
//     return x * m + y;
// }

// void solve() {
//     cin >> n >> m;
//     vvll grid(n, vll(m));

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     DSU dsu(n * m);
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (i < n - 1 && grid[i][j] == grid[i + 1][j]) {
//                 dsu.unite(num(i, j), num(i + 1, j));
//             }
//             if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
//                 dsu.unite(num(i, j), num(i, j + 1));
//             }
//         }
//     }

//     map<ll, ll>mp;
//     vll nodes;

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(dsu.find(num(i, j)) == num(i, j)) {
//                 nodes.pb(num(i, j));
//                 mp[num(i, j)] = nodes.size() - 1;
//             }   
//         }
//     }

//     pr(nodes);
//     vector<set<ll>> graph(nodes.size());

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (i < n - 1 && grid[i][j] != grid[i + 1][j]) {
//                 ll x = dsu.find(num(i, j));
//                 ll y = dsu.find(num(i + 1, j));
//                 graph[mp[x]].insert(mp[y]);
//                 graph[mp[y]].insert(mp[x]);
//             }
//             if (j < m - 1 && grid[i][j] != grid[i][j + 1]) {
//                 ll x = dsu.find(num(i, j));
//                 ll y = dsu.find(num(i, j + 1));
//                 graph[mp[x]].insert(mp[y]);
//                 graph[mp[y]].insert(mp[x]);
//             }
//         }
//     }

//     vll colors;

//     for(auto &x: nodes) {
//         colors.pb(grid[x / m][x % m]);
//         x = dsu.rank[x];
//     }
    
//     pr(nodes);
//     pr(colors);
//     pr(graph);

//     ll ans = *max_element(all(nodes));
//     ll comps = nodes.size();

//     queue<array<ll, 3>> q;

//     q.push({0, colors[]})
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.precision(6);
//     cout << fixed;

//     ll t = 1;
//     // cin >> t;

//     while (t--) {
//         solve();
//     }
//     return 0;
// }

// ll gcd(ll a, ll b) {
//     if (b > a) return gcd(b, a);
//     if (b == 0) return a;
//     return gcd(b, a % b);
// }

// ll mod(ll n) { return (n % N + N) % N; }
// ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
// ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
// ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }

// ll power(ll a, ll b) {
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1) {
//             res = modM(res, a);
//         }
//         a = modM(a, a);
//         b >>= 1;
//     }
//     return res;
// }

// ll inv(ll a, ll mod) {
//     a %= mod;
//     if (a < 0) a += mod;
//     ll b = mod, u = 0, v = 1;
//     while (a) {
//         ll t = b / a;
//         b -= t * a;
//         swap(a, b);
//         u -= t * v;
//         swap(u, v);
//     }
//     assert(b == 1);
//     if (u < 0) u += mod;
//     return u;
// }

#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
using namespace std;
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
#define all(o) (o).begin(), (o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);++i)
#define rep(i,a,b) for(lli i=a;i<=b;++i)
#define per(i,a,b) for(lli i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b))) 
#define sz(x) (lli)(x).size()
#define endl '\n'
typedef long long lli;        typedef long double ld;
typedef pair<lli,lli> ii;     typedef vector<lli> vi;
typedef vector<ii> vii;       typedef vector<vi> graph;
long long MOD=1000000007;     long double EPS=1e-9;
#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
lli binpow(lli b,lli p,lli mod){lli ans=1;b%=mod;for(;p;p>>=1){if(p&1)ans=ans*b%mod;b=b*b%mod;}return ans;}

void pre(){

}

int uf[1000100];
int rankk[1000100];
multiset<int> compSize;
void init(){
    compSize.clear();
    fr(i,1000001){uf[i]=i;rankk[i]=1;compSize.insert(1);}
}
int get(int x){
    while(x!=uf[x])x=uf[x];return x;
}
vector<pair<int,int>> st;
void merge(int x,int y){
    x=get(x);y=get(y);
    if(x==y)return;
    if(rankk[x] < rankk[y])swap(x,y);
    compSize.erase(compSize.find(rankk[x]));
    compSize.erase(compSize.find(rankk[y]));
    rankk[x]+=rankk[y];
    uf[y]=x;
    st.EB(y,x);
    compSize.insert(rankk[x]);   
}
void revert(){
    while(!st.empty()){
        int y = st.back().F;
        int x = st.back().S;
        st.pop_back();
        compSize.erase(compSize.find(rankk[x]));
        uf[y]=y;
        rankk[x]-=rankk[y];
        compSize.insert(rankk[x]);
        compSize.insert(rankk[y]);
    }
}
int getMax(){
    auto it=compSize.end();it--;
    return *it;
}


int n,m;
bool check(int i,int j){
    if(i<n&&i>=0&&j<m&&j>=0)return 1;
    return 0;
}
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int arr[1001][1001];
int node[1001][1001];

vector<pair<ii,ii>> edges;

void solve(){
    cin>>n>>m;
    init();
    int cnt=1;
    fr(i,n)fr(j,m){cin>>arr[i][j];node[i][j]=cnt++;}
    fr(i,n)fr(j,m){
        fr(k,2){
            int xx = i+dx[k];
            int yy = j+dy[k];
            if(check(xx,yy)){
                int cc1 = arr[i][j];
                int cc2 = arr[xx][yy];
                if(cc1>cc2)swap(cc1,cc2);
                if(cc1!=cc2){
                    edges.EB(MP(MP(cc1,cc2),MP(node[i][j],node[xx][yy])));
                }else{
                    merge(node[i][j],node[xx][yy]);
                } 
            }
        }
    }
    st.clear();
    sort(all(edges));
    int ans=getMax();
    for(int i=0;i<edges.size();i++){
        int j=i;
        while(j<edges.size() && edges[i].F==edges[j].F){
            merge(edges[j].S.F,edges[j].S.S);
            j++;
        }
        remax(ans,getMax());
        revert();
        i=j-1;
    }
    cout << ans << endl; 
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //cout<<fixed<<setprecision(15);
    //clock_t begin = clock();
    pre();lli _t=1;//cin>>_t;
    for(lli i=1;i<=_t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    // clock_t end = clock();double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;cerr << elapsed_secs;
}
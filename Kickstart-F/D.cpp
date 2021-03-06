//#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
//using namespace __gnu_pbds;
//template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
const ll mod =1e9+7;
const int maxn = 15;
#define endl '\n'
#define int ll
#define ld long double
#define all(x) (x).begin(),(x).end()
vector<int> g[maxn];
int visited[maxn], a[maxn], l[maxn], r[maxn];
int n, m, k;
int dp[1<<maxn];
int poss(int mask, int s, int t){
  if(s == t) return 1;
  visited[s] = 1;
  for(auto v : g[s]){
    if(visited[v]) continue;
    if(((mask>>v)&1) || v == t){
      if(poss(mask, v, t)) return 1;
    }
  }

  return 0;
}
int solve(int mask, int last, int sum){
  if(sum == k){
    return 1;
  }
  if(sum > k) return 0;
  if(mask + 1 == (1<<n)) return 0;

  int &res = dp[mask];
  if(res != -1){
    return res;
  }
  res = 0;
  
  for(int i = 0; i < n;i++){
    if((((mask>>i)&1) == 0) and sum >= l[i] and sum <= r[i]){
      memset(visited, 0, sizeof(visited));
      if(poss(mask, last, i)) res += solve((mask|(1<<i)), i, sum + a[i]);
    }
  }

  return res;
}
int32_t main()
{ 
  IOS


  int testcases = 1;
  cin>>testcases;
  for(int test = 1;test<=testcases;test++)
  {
    cout<<"Case #"<<test<<": ";
    
    cin >> n >> m >>k;
    // trace(n, m, k);
    for(int i = 0; i < n;i++){
      g[i].clear();
      cin >> l[i] >> r[i] >> a[i];
    }

    for(int i = 0;i<m;i++){
      int x, y;
      cin >> x >> y;
      
     
      g[x].push_back(y);
      g[y].push_back(x);
      
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i = 0; i < n;i++){
      ans += solve((1<<i), i, a[i]);
    }

    cout << ans << endl;



  }

 


  

  

	

  
  
  


  
  

}
 
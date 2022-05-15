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
vector<vector<bool>> vis;

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, m;

int dfs(int x, int y, vector<vector<int>> &A) {
    int count = 1;
    vis[x][y] = 1;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        pr(x, y, nx, ny);
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 1 && !vis[nx][ny]) {
            count += dfs(nx, ny, A);
        }
    }
    return count;
}

int solve(vector<vector<int> > &A) {  
    n = A.size();
    if(n == 0) {
        return 0;
    }
    m = A[0].size();
    if(m == 0) {
        return 0;
    }
    vis.assign(n, vector<bool>(m, false));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == 1 && !vis[i][j]) {
                pr(i, j);
                int sz = dfs(i, j, A);
                if(sz > ans) {
                    ans = sz;
                }
            }
        }        
    }
    return ans;
}


signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> A = {
                                {0, 0, 1, 0, 0, 0, 0, 0}, 
                                {1, 1, 1, 1, 1, 1, 1, 0}
                            };
    cout << solve(A) << endl;
    return 0;
}
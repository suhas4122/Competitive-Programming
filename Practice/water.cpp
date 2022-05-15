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

vector<vector<int>>blue, red;
queue<pair<int, int>>q;
int n, m;

bool check(int x, int y, int nx, int ny, vector<vector<char>> A) {
    if(nx < n && nx >= 0 && ny < m && ny >=0 && A[nx][ny] == 'O') {
        return true;
    }
    return false;
}
  
void solve(vector<vector<char> > &A) {
    n = A.size();
    if(n == 0) {
        return;
    }
    m = A[0].size();
    if(m == 0) {
        return;
    }
    queue<pair<int, int>> q;
    vector<vector<char>> ans(n, vector<char>(m, 'X'));
    for(int i = 0; i < n; i++) {
        if(A[i][0] == 'O') {
            q.push({i, 0});
            // pr(i, 0);
        }
        if(m > 1 && A[i][m - 1] == 'O') {
            q.push({i, m - 1});
            // pr(i, m - 1);
        }
    }
    for(int i = 1; i < m - 1; i++) {
        if(A[0][i] == 'O') {
            q.push({0, i});
            // pr(0, i);
        }
        if(n > 1 && A[n - 1][i] == 'O') {
            q.push({n - 1, i});
            // pr(n - 1, i);
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        pr(x, y);
        ans[x][y] = 'O';
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            pr(nx, ny);
            if(check(x, y, nx, ny, A) && ans[nx][ny] == 'O') {
                ans[nx][ny] = 'O';
                // q.push({nx, ny});
            }
        }
    }
    A = ans;
}


signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> A = {{'O'}};
    solve(A);
    pr(A);
    return 0;
}
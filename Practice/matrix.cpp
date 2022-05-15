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

int solve(string A, string B, vector<string> &C) {
    set<string> dict;
    for(auto &x: C) dict.insert(x);
    dict.insert(A);

    queue<pair<string, int>> q;
    q.push({A, 1});

    while(!q.empty()) {
        string str = q.front().first;
        int dist = q.front().second;
        q.pop();
        pr(str, dist);
        if(str == B) {
            return dist;
        }
        dict.erase(str);
        for(int i = 0; i < str.size(); i++) {
            for(int j = 0; j < 26; j++) {
                char c = 'a' + j;
                if(c == str[i]) {
                    continue;
                }
                string next = str;
                next[i] = c;
                if(dict.find(next) != dict.end()) {
                    q.push({next, dist + 1});
                }
            }
        }
    }

    return 0;
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string A = "ymain", B = "oecij";
    vector<string> C = {"ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij", "yecij", "ymanj", "yzcnj", "ymain"};
    cout << solve(A, B, C) << endl;
    return 0;
}
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

vector<string> wordBreak(string s, vector<string> &B) {
    set <string> words(B.begin(), B.end());
    int n = s.length();
    vector <bool> dp(n + 1);
    map<int, vector<vector<string>>> mp;
    dp[0] = true;
    mp[0] = {{}};
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && words.find(s.substr(j, i - j)) != words.end()) {
                dp[i] = true;
                for(auto x: mp[j]) {
                    x.push_back(s.substr(j, i - j));
                    mp[i].push_back(x);
                }
            }
        }
        pr(i, mp[i]);
    }

    vector<string> ans;
    if(!dp[n]) {
        return ans;
    }
    for(auto &x: mp[n]) {
        string s;
        for(auto y: x) {
            s += y;
            s += ' ';
        }
        s.pop_back();
        ans.push_back(s);
    }

    return ans;
}

void solve() {
    string s = "aabbbabaaabbbabaabaab";
    vector <string> v {"bababbbb", "bbbabaa", "abbb", "a", "aabbaab", "b", "babaabbbb", "aa", "bb"};
    vector <string> ans = wordBreak(s, v);
    pr(ans);
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    // cin >> t;
    for(i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
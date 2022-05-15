#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

void rec(const string& s, int ind, int extral, int extrar, string curr, int l, int r, unordered_set<string>& ans) {
    if (ind == s.size()) {
        if (l == r && extral == 0 && extrar == 0) 
            ans.insert(curr);
        return;
    }
    if (s[ind] != '(' && s[ind] != ')') {
        curr += s[ind];
        rec(s, ind + 1, extral, extrar, curr, l, r, ans);
        return;
    }
    if (s[ind] == '(') {
        if (extral > 0) {
            rec(s, ind + 1, extral - 1, extrar, curr, l, r, ans);
        }
        rec(s, ind + 1, extral, extrar, curr + s[ind], l + 1, r, ans);
    } else {
        if (extrar > 0) {
            rec(s, ind + 1, extral, extrar - 1, curr, l, r, ans);
        }
        if (l > r) {
            rec(s, ind + 1, extral, extrar, curr + s[ind], l, r + 1, ans);
        }
    }
}

void solve(const string& s, unordered_set<string>& ans) {
    int l = 0, r = 0;
    for (auto &c : s) {
        if (c == '(') {
            ++l;
        }
        if (c == ')') {
            if (l != 0) {
                --l;
            } else {
                ++r;
            }
        }
    }
    rec(s, 0, l, r, "", 0, 0, ans);
}

vector<string> removeInvalidParentheses(string str) {
    string s;
    s = str;
    unordered_set <string> ans;
    solve(s, ans);
    vector<string> ret_val(ans.begin(), ans.end());
    if (ret_val.empty()) ret_val.push_back("");
    return ret_val;
}

int main() {
    string str;
    cin >> str;
    vector<string> ans = removeInvalidParentheses(str);
    for (auto x : ans) {
        cout << x << " ";
    }
}
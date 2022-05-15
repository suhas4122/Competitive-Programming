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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &A) {
    int i, j, k;
    vector<Interval> B;
    int count = 0;
    sort(A.begin(), A.end(), comp);

    for (Interval interval : A) {
        k = B.size();
        count = 0;
        if (k == 0) {
            B.push_back(interval);
            k = B.size();
            count = 1;
        }

        else if (interval.start > B[k - 1].end && count == 0) {
            B.push_back(interval);
            k = B.size();
        }

        else if (B[k - 1].end < interval.end && count == 0) {
            B[k - 1].end = interval.end;
        }
    }
    return B;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<Interval> A = {{1,3},{2,6},{8,10},{15,18}};
    vector<Interval> B = merge(A);
    cout << B.size() << endl;
    for (Interval interval : B) {
        cout << interval.start << " " << interval.end << endl;
    }
    return 0;
}
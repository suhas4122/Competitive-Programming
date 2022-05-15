#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

void solve() {
    int n;
    cin >> n;   
    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int lo = 0, hi = n-1, ans = 0;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if((mid > lo && arr[mid] >= arr[mid - 1]) || (mid == lo && arr[mid] >= arr [mid + 1])) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << arr[ans] << endl;
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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
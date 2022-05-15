#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

int n, k; 
int arr[100010], brr[100010];

int check(int x) {
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += upper_bound(brr, brr + n, x - arr[i]) - brr; 
    }
    return ans < k;
}

void solve() {  
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> brr[i];
    }
    sort(arr, arr + n);
    sort(brr, brr + n);

    int lo = arr[0] + brr[0];
    int hi = arr[n-1] + brr[n-1];
    int ans = -1;

    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans + 1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i;
    cin >> t;
    for(i = 1; i <= t; i++) { 
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin >> n;
    ll curr = 0;
    ll mini = 0, maxi = 0;
    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        curr += x;
        mini = min(mini, curr);
        maxi = max(maxi, curr);
    }
    ll lb, ub;
    cin >> lb >> ub;
    ll ans = (ub-lb) - (maxi-mini) + 1;
    cout << ans << "\n";
}
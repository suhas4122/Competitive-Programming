#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    multiset<ll>s;
    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        s.insert(x);
    }
    ll maxi = INT_MIN;
    ll count = 0;
    ll prev = INT_MIN;
    for(auto x: s){
        if(prev == x || prev + 1 == x){
            count ++;
            prev = x;
        }else{
            maxi = max(count, maxi);
            count = 1;
            prev = x;
        }
    }
    cout << maxi << "\n";
}
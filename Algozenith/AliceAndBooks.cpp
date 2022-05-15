#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> s;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] > curr){
            s.insert(a[i]);
            if(*s.begin() == curr)
                s.erase(s.begin());
            else 
                curr++;
        }
        cout << curr << " ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
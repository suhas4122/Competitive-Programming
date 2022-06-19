#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> d(n + 1, 1);
    for (int i = 2; i * i <= n; i++) {
        for(int j = 1; j * i * i <= n; j++) {
            d[j * i * i] = i * i;
        }
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[i / d[i]]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += cnt[i] * cnt[i];
    cout << ans << endl;
}
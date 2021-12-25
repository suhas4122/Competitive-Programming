#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[51][101][51];

void pre(){
    for(int i = 1; i<=100; i++){
        dp[1][i][0] = 1;
    }
    for(int i = 2; i<=50; i++){
        for(int j = 1; j<=100; j++){
            for(int k = 0; k<=50; k++){
                if(k >= i || k >= j){
                    dp[i][j][k] = 0;
                    continue;
                }
                ll sum = 0;
                for(int l = 1; l<j; l++){
                    if(k>0) sum += dp[i-1][l][k-1];
                }
                sum += (j)*dp[i-1][j][k];
                dp[i][j][k] = sum;
            }
        }
    }
}

ll solve(ll n, ll m, ll c){
    ll sum = 0;
    for(int i = c+1; i<=m; i++) sum += dp[n][i][c];
    return sum;
}

int main(){
    pre();
    ll n, m, c;
    cin >> n >> m >> c;
    cout << solve(n, m, c) << "\n";
}
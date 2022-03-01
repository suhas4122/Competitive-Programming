#include <bits/stdc++.h> 
using namespace std;
#define for0(n) for(int i=0;i<n;++i) 

int main(){
    int t, n; cin >> t;
    while(t--){
    	cin >> n;
        int arr[n], maxi[n];
        for0(n) cin >> arr[i];
        maxi[0] = arr[0];
        for(int i = 1; i < n; i++){
            maxi[i] = max(maxi[i-1], arr[i]);
        }
        int mini = INT_MAX;
        vector<int> ind;
        for(int i = n-1; i>=1; i--){
            mini = min(mini, arr[i]);
            if(maxi[i-1] <= mini) ind.push_back(i);
        }
        cout << ind.size() + 1<< "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    vector<pair<char, int>>v;
    int count = 1;
    char pre = s[0];
    for(int i = 1; i<s.length(); i++){
        if(s[i] == pre){
            count++;
        }else{
            v.push_back({pre, count});
            count = 0;
        }
        pre = s[i];
    }
    v.push_back({pre, count});
    int w;
    cin >> w;
    int counter = 0;
    while(w--){
        vector<pair<char, int>> temp;
        int count = 1;
        char pre = s[0];
        int i1 = 0;
        for(int i = 1; i<s.length(); i++){
            if(s[i] == pre){
                count++;
            }else{
                v.push_back({pre, count});
                if(v[i1].first != pre || v[i1].second > count){
                    cout << "NO\n";
                    break;
                }
                i1++;
                count = 0;
            }
            pre = s[i];
        }   
        if(v[i1].first != pre || v[i1].second > count || i1 != v.size()-1){
            cout << "NO\n";
            break;
        }else{
            cout << "YES\n";
            counter++;
        }
    }
}
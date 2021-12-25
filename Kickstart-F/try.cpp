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


void re_sort(int arr[], int left, int right){
    pr(left, right);
    int l = left, r = right, p = left;
    while (l<r){
        while(arr[l] <= arr[p] && l < right)
            l++;
        while (arr[r] >= arr[p] && r > left)
            r--;
        if(l >= r){
            swap(arr[p], arr[r]);
            re_sort(arr, left, r-1);
            re_sort(arr, r+1, right);
            return;
        }
        swap(arr[l], arr[r]);
        // debarr(arr, 7);        
    }    
}

int main(){
    int arr[] = {4, 5, 6, 2, 3, 1, 9};
    re_sort(arr, 0, 6);
    for(int i = 0; i<7; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
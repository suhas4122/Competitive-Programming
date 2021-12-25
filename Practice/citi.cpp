#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct ele {
    int count, index, val;
};

bool comp(struct ele a, struct ele b){
    return (a.val < b.val);
}

bool comp2(struct ele a, struct ele b){
    if (a.count != b.count)
        return (a.count < b.count);
    else
        return a.index > b.index;
}
 
vector<int> sortByFrequency(vector<int> arr, int n) {
    struct ele element[n];
    for (int i = 0; i < n; i++) {
        element[i].index = i;
        element[i].count = 0;
        element[i].val = arr[i];
    }
    stable_sort(element, element + n, comp);
    element[0].count = 1;
    for (int i = 1; i < n; i++) {
        if (element[i].val == element[i - 1].val) {
            element[i].count += element[i - 1].count + 1;
            element[i - 1].count = -1;
            element[i].index = element[i - 1].index;
        }
        else
            element[i].count = 1;
    }
    stable_sort(element, element + n, comp2);
    for (int i = n - 1, index = 0; i >= 0; i--)
        if (element[i].count != -1)
            for (int j = 0; j < element[i].count; j++)
                arr[index++] = element[i].val;
    return arr;
}


int main(){
    vector<int> a {1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 5, 6, 6, 6, 7, 8, 9, 10};
    vector<int>res;
    res = sortByFrequency(a, a.size());
    for(int i = 0;i < res.size(); i++)
            cout<<res[i]<<" ";
    cout << "\n";
    return 0;
}

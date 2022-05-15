#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

template <typename t>
class Vector {
    int size, capacity;
    t* arr;

   public:
    Vector(int n = 1) {
        arr = new t[n];
        size = 0;
        capacity = n;
    }

    void push(int x) {
        if (size == capacity) {
            t* temp = new t[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            capacity *= 2;
        }

        arr[size++] = x;
    }

    void set(int x, int ind) {
        if (ind >= 0 && ind < size) {
            arr[ind] = x;
        }
    }                   

    t get(int ind) {
        if (ind >= 0 && ind < size) {
            return arr[ind];
        }
    }

    void print() {
        for(int i = 0; i < size; i++) 
            cout << arr[i] << " ";
        cout << endl;
    }
};

signed main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Vector <int> v(2);
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(3);
    v.push(3);
    v.set(10, 2);
    v.print();

    return 0;
}
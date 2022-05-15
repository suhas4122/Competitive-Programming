#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
const ll MOD = 1000000007;

class Queue {
   public:

    int rear, front, size;
    int* queue;

    Queue(int sz) {
        size = sz;
        queue = new int[sz];
        front = -1;
        rear = -1;
    }

    void enQueue(int x) {
        if (rear == (front + size - 1) % size) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
            queue[rear] = x;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = x;
        }
    }

    int deQueue() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return -1;
        }
        int return_val = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1 + size) % size;
        }
        return return_val;
    }

    void printQueue() {
        int i = front;
        if (front == -1) {
            cout << "Queue is empty\n";
        }
        while(i != rear) {
            cout << queue[i]  << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] << endl;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Queue q(5);
    q.enQueue(2);
    q.enQueue(4);
    q.enQueue(6);
    q.enQueue(8);
    q.enQueue(4);
    q.enQueue(6);
    int x = q.deQueue();
    cout << x << endl;
    cout << q.front << " " << q.rear << endl;
    q.printQueue();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

template <class T>
class queuee {
    T *arr;
    int size;
    int front;
    int rear;

public:
    queuee(int n): size(n), front(0), rear(-1) {
        arr = new T[n];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty!!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void enqueue(T x) {
        if (isFull()) {
            cout << "Queue Full!!" << endl;
            return;
        }

        rear++;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty!!" << endl;
            return;
        }
        front++;
    }

    void Front() {
        if (isEmpty()) {
            cout << "Queue Empty!!" << endl;
            return;
        }

        cout << arr[front] << endl;
    }

    bool isEmpty() {
        return (rear == -1 || front > rear) ? 1 : 0;
    }

    bool isFull() {
        return (rear == size - 1) ? 1 : 0;
    }

    ~queuee() {
        delete[] arr;
    }
};

int main()
{
    int n;
    cin >> n;

    queuee<int> q1(n);
    if(q1.isEmpty()){ cout << "QUEUE EMPTY!!" << endl; }

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    q1.display();

    q1.dequeue();
    q1.display();

    q1.Front();

    q1.dequeue();
    q1.display();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

template <class T>
class dequee {
    T *arr;
    int size;
    int front;
    int rear;
    int count;

public:
    dequee(int n): size(n), front(0), rear(-1), count(0) {
        arr = new T[n];
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == size);
    }

    void insertRear(T x) {
        if (isFull()) {
            cout << "Deque Full!!" << endl;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = x;
        count++;
    }

    void insertFront(T x) {
        if (isFull()) {
            cout << "Deque Full!!" << endl;
            return;
        }

        front = (front - 1 + size) % size;
        arr[front] = x;
        count++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Empty!!" << endl;
            return;
        }

        front = (front + 1) % size;
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Empty!!" << endl;
            return;
        }

        rear = (rear - 1 + size) % size;
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque Empty!!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % size] << " ";
        }
        cout << endl;
    }

    void Front() {
        if (isEmpty()) {
            cout << "Deque Empty!!" << endl;
            return;
        }

        cout << arr[front] << endl;
    }

    void Rear() {
        if (isEmpty()) {
            cout << "Deque Empty!!" << endl;
            return;
        }

        cout << arr[rear] << endl;
    }

    ~dequee() {
        delete[] arr;
    }
};


int main()
{
    int n;
    cin >> n;

    dequee<int> d1(n);

    if(d1.isEmpty()){ cout << "DEQUE EMPTY!!" << endl; }

    d1.insertRear(10);
    d1.insertRear(20);
    d1.insertFront(5);
    d1.insertFront(2);

    d1.display();

    d1.deleteRear();
    d1.display();

    d1.deleteFront();
    d1.display();

    d1.Front();
    d1.Rear();

    return 0;
}

#include <iostream>
using namespace std;

void heapify(int heap[], int n, int root, bool isMax) {
    int target = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (isMax) {
        if (left < n && heap[left] > heap[target])   target = left;
        if (right < n && heap[right] > heap[target]) target = right;
    } else {
        if (left < n && heap[left] < heap[target])   target = left;
        if (right < n && heap[right] < heap[target]) target = right;
    }

    if (target != root) {
        swap(heap[root], heap[target]);
        heapify(heap, n, target, isMax);
    }
}

void heapsort(int heap[], int n, bool isMax) {
    for (int j = n - 1; j >= 0; j--) {
        swap(heap[0], heap[j]);
        heapify(heap, j, 0, isMax);
    }
    cout << "\nThe sorted array is : ";
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void build_maxheap(int heap[], int n) {
    cout << "\nBuilding Max_Heap_Array ::\n" << endl;

    for (int i = 1; i < n; i++) {
        int child = i;
        do {
            int root = (child - 1) / 2;
            cout << "root :" << root << " -> " << "child :" << child << endl;
            if (heap[root] < heap[child])
                swap(heap[root], heap[child]);
            child = root;
        } while (child != 0);
    }

    cout << "\nHeap array: ";
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;

    heapsort(heap, n, true);   // sorts ascending
}

void build_minheap(int heap[], int n) {
    cout << "\nBuilding Min_Heap_Array ::\n" << endl;

    for (int i = 1; i < n; i++) {
        int child = i;
        do {
            int root = (child - 1) / 2;
            cout << "root :" << root << " -> " << "child :" << child << endl;
            if (heap[root] > heap[child])
                swap(heap[root], heap[child]);
            child = root;
        } while (child != 0);
    }

    cout << "\nHeap array: ";
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;

    heapsort(heap, n, false);  // sorts descending
}

int main() {
    int n = 5;
    int heapMx[10] = {2, 3, 1, 0, 4};
    int heapMn[10] = {2, 3, 1, 0, 4};

    cout << "Given Array : ";
    for (int i = 0; i < n; i++)
        cout << heapMx[i] << " ";
    cout << endl;

    build_maxheap(heapMx, n);
    build_minheap(heapMn, n);
    return 0;
}
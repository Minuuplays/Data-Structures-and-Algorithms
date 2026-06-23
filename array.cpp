#include <iostream>

using namespace std;

// commented parts are used when not using a class ..just basic array in main and some functions to use
// #define N 100

class arrayy{
    int *arr;
    int n;
public:
    arrayy(int n=100):n(n){
        arr = new int [n];
    }

    void input(){
        for (int i=0;i<n;i++){
            cin >> arr[i];
        }
    }

    void display(){
        for (int i=0;i<n;i++){
            cout << arr [i] << " ";
        }
        cout << endl;
    }

    void displaywithIndex(){
        for (int i=0;i<n;i++){
            cout << "At index " << i << " : " << arr [i] << endl ;
        }
    }

    void traverse(){   // traverse(int arr[N],int n)
        for (int i=0;i<n;i++){
            cout << "Traversing array at index: " << i << endl;
        }
    }

    void search(int key){  // search(int arr[N],int &n,int key)
        for (int i=0;i<n;i++){
            if (arr[i] == key){
                cout << "Found at index : " << i <<endl;
            }
            else {
                cout << "Not Found !!" << endl;
            }
        }
    }

    void update(int pos,int x){ // update(arr[N],int &n, int pos, int x)
        arr[pos] = x;
    }

    void insert(int pos,int x){ // insert(arr[N],int &n, int pos, int x)
        int temp = n;
        n++;
        for(int i=temp;i>pos;i--){
            arr[i]=arr[i-1];
        } 
        arr[pos] = x;
    }

    void delet(int pos){
        for (int i=pos;i<n-1;i++){
            arr[i]=arr[i+1];
        }
        n--;
    }

    ~arrayy(){
        delete[] arr;
    }
};

int main()
{
    int m;
    cin >> m;
    arrayy a1(m);

    a1.input();
    a1.display();
    a1.displaywithIndex();
    a1.traverse();
    a1.search(2);
    a1.update(3,10);
    a1.display();
    a1.insert(1,20);
    a1.display();
    a1.delet(1);
    a1.display();
    
    return 0;
}

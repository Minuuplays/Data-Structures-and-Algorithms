#include <bits/stdc++.h>

using namespace std;

template <class T>
class stackk{
    T *arr;
    int size;
    int top;
public:
    stackk(int n):size(n),top(-1){
        arr= new T[n];
    }

    void display(){
        for (int i=0;i<=top;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void push(T x){
        top++;
        arr[top]=x;
    }

    void pop(){
        if (isEmpty()) {
            cout << "Stack Empty!!" << endl;
           return ;
        }  
        top--;
    }

    void Top(){
        if (isEmpty()) {
            cout << "Stack Empty!!" << endl;
           return ;
        }  
        cout << arr[top] << endl;
    }

    bool isEmpty(){
        return (top == -1 )? 1:0;
    }

    ~stackk(){
        delete[] arr;
    }
};


int main()
{
    int n;
    cin >> n;

    stackk<int> s1(n);
    if(s1.isEmpty()){ cout << "STACK EMPTY!!" << endl; };

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.display();
    s1.pop();
    s1.display();
    s1.Top();

    return 0;

}
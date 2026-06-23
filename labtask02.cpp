#include <bits/stdc++.h>

using namespace std;
template <class T>

class MovingAverage{
    T *arr;
    int size;
    int front;
public:
    MovingAverage(int n):size(n),front(-1){  
        arr = new int[n]; 
    }

    void next(T x)
    {
        front++;
        if (front < size){
            arr[front] = x;
        }
        if (front == size){
            for (int i=0;i<size;i++) {
                arr[i]=arr[i+1];
            } 
            front--; 
            arr[front]=x;
        }
    }

    void display(){
       for(int i=0;i<=front;i++) {
           cout << arr[i] << " ";
       } cout << endl;
    }

    float average()
    {
        float sum=0;
        for(int i=0;i<= front;i++){
             sum+=arr[i];
        }
        return sum/(front+1);
    }
};

int main()
{
    int n;
    cin >> n;
    MovingAverage <int> m(n);

    int a;
    int i=1;

    while(i!=0){
        cin >> a;
        m.next(a);
        cout << "Average : " << m.average() << endl;
        i++;
    }
    return 0;
}
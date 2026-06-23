#include <bits/stdc++.h>
using namespace std;

class deq{
   int *arr;
   int size;
   int front;
   int rear;

   public:
       deq(int n):size(n),front(0),rear(-1)
       {
           arr= new int [n];
       }

       void inrear(int x)
       {
           rear = (rear+1)%size;
           arr[rear] = x;
       }

      /* void infront(int x)
       {
           front = (front -1+size)%size;
           arr[front] = x;

       }*/

       void pro()
       {
           if (rear == -1 )
           {
               cout << "Holding area is Empty!!" <<endl;
           }

           int temp = arr[front];
           front++;
           rear++;
           arr[rear]=temp;if (rear == -1 )
           {
               cout << "Holding area is Empty!!" <<endl;
           }

       }

       void delet(int x)
       {
           if (rear == -1 )
           {
               cout << "EMPTY !!" <<endl;
           }

           for (int i=front;i<=rear;i++)
           {
               if (arr[i]==x)
               {
                   arr[i]=0;
                   return;
               }
           }

           cout << "Error !! Not Found !!" << endl;

       }

       void display()
       {
           if (rear == -1 )
           {
               cout << "Holding area is Empty!!" <<endl;
           }
           for (int i=front;i<=rear;i++)
           {
               cout << "Task " << arr[i] << "  " ;
           }
           cout << endl;
       }

       ~deq ()
       {
           delete[] arr;
       }

};


int main()
{
    deq d1(10);

    here:
    cout << "Choose option :\n   1.ARRIVE\n   2.URGENT\n   3.PROCESS\n   4.CANCEL\n   5.VIEW_FORWARD\n";


    int n;
    cin >> n;

    switch(n)
    {
    case 1:
        int m;
        cin >> m;
        d1.inrear(m);
        goto here;
        break;
    case 2:
        int o;
        cin >> o;
       // d1.infront(o);
        goto here;
        break;
    case 3:
        d1.pro();
        goto here;
        break;
    case 4:
        int a;
        cin >> a;
        d1.delet(a);
        goto here;
        break;
    case 5:
        d1.display();
        goto here;
        break;
    default:
        cout << "Error !! " << endl;
        goto here;
    }

    return 0;
}
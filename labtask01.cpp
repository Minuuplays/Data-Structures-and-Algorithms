#include <bits/stdc++.h>
using namespace std;

void delet(int arr[20],int &n,int i){
    for (int j=i;j<n;j++){
        arr[j]=arr[j+1];
    }
    n=n-1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    for (int i=n;i>0;i--){
        int count = 0;
        for (int j=0;j<n;j++){
            if (arr[i]==arr[j]){
                count ++;
            }
            if (count > 1){
                arr[i] = 0;
            }
        }
    }

    for (int i=0;i<n;i++){
        if (arr[i]==0){
            delet(arr,n,i);
            i=i-1;
        }
    }

    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}                                                                   
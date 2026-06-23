#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for (int i=0;i<n;i++) {
        cout << arr[i] << "  " ;
    }
    cout << endl;
}

void selectSort(int arr[], int n);
void insertSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int n);
void mergeSort(int arr[], int n);

int main()
{
    int arr1[7]={2,7,4,1,8,0,6};
    int arr2[7]={2,7,4,1,8,0,6};
    int arr3[7]={2,7,4,1,8,0,6};
    int arr4[7]={2,7,4,1,8,0,6};
    int arr5[7]={2,7,4,1,8,0,6};

    selectSort(arr1, 7);
    insertSort(arr2, 7);
    bubbleSort(arr3, 7);
    quickSort(arr4, 7);
    mergeSort(arr5,7);

    return 0;
}

void selectSort(int arr[], int n){
    int min;
    for (int i=0; i<n-1; i++){
        int min_index = i;
        for (int j=i+1;j<n;j++) {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
    cout << "Selection Sort :  " ;
    display(arr,n);
    cout << endl ;
    return ;
}

void insertSort(int arr[], int n){
    for (int i=0; i<n; i++) {
        int k = arr[i];
        int j = i-1;

        while (j>=0 && arr[j]>k) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
    cout << "Insertion Sort :  " ;
    display(arr,n);
    cout << endl ;
    return ;
}

void bubbleSort(int arr[], int n){
   // bool swapped;
    for (int i=0; i<(n/2); i++)
    {
       // swapped =false;
        for (int j=0; j <n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                //swapped=true;
            }
        }
      //  if (swapped)
         display(arr,n);
          // break;
    }

    cout << "Bubble Sort    :  " ;
    display(arr,n);
    cout << endl ;
    return ;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];   // last element  pivot
    int i = low - 1;         // index of smaller element

    for (int j=low;j<high;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);  
    return i+1;
}

void quickSortHelper(int arr[],int low,int high){
    if (low < high) {
        int pi = partition(arr,low,high);   // pivot index

        quickSortHelper(arr,low,pi-1);    // sort left 
        quickSortHelper(arr,pi+1,high);   // sort right 
    }
}

void quickSort(int arr[], int n){
    quickSortHelper(arr,0,n-1);

    cout << "Quick Sort     :  ";
    display(arr,n);
    cout << endl;
}

void merge(int arr[],int left,int mid,int right)
{
    int n1 = mid-left+1;  //left subarray
    int n2 = right-mid;   //right 

    int L[n1], R[n2];
    for (int i=0;i<n1;i++) L[i] = arr[left+i];
    for (int j=0;j<n2;j++) R[j] = arr[mid+1+j];

    int i=0, j=0, k=left;
    while ( i<n1 && j<n2 ) {
        if (L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i<n1) arr[k++] = L[i++];
    while (j<n2) arr[k++] = R[j++];
}

void mergeSortHelper(int arr[],int left,int right){
    if (left < right){
        int mid = left+ (right-left) /2;  

        mergeSortHelper(arr,left,mid);        // sort left half
        mergeSortHelper(arr,mid+1,right);   // sort right half
        merge(arr,left,mid,right);           // merge sorted halves
    }
}

void mergeSort(int arr[], int n){
    mergeSortHelper(arr,0,n - 1);

    cout << "Merge Sort     :  ";
    display(arr,n);
    cout << endl;
}
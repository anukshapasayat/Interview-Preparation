#include<stdio.h>
void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l]>arr[largest])
    largest = l;
    if(r<n && arr[r]>arr[largest])
    largest = r;
    if(largest != i){
        int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n){
    for(int i = n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
    for(int i = n-1;i>0;i--){
        int swap = arr[i];
            arr[i] = arr[0];
            arr[0] = swap;
        heapify(arr,n,0);
    }
}
void printheap(int arr[], int n){
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = 6;
    heapsort(arr, n);
    printf("Sorted array is \n");
    printheap(arr, n);
}
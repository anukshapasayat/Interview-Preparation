#include<stdio.h>
int peak(int arr[], int l, int h, int n){
    int mid = l + (h-l)/2;
    if((mid == 0 || arr[mid-1]<=arr[mid])&&(mid == n-1 || arr[mid]>= arr[mid+1]))
    return mid;
    else if (mid>0 && arr[mid - 1]>arr[mid])
    return peak(arr, l, mid-1, n);
    else
    return peak(arr, mid+1, h, n);
}
int peak_f(int arr[], int n){
    peak(arr, 0, n-1, n);
}
int main(){
    int arr[] = {1,2,3,4,7,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = arr[peak_f(arr, n)];
    printf("%d",x);
    return 0;
}
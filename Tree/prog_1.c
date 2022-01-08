#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Convert to min heap
void heapify(int arr[], int n, int i)
{
    int smallest = i;                    // smallest is the root
    int l = 2 * i + 1;                  //left child
    int r = 2 * i + 2;                  //right child
    if (l < n && arr[l] < arr[smallest]) //if left child smaller than root
        smallest = l;                    //make left child as root
    if (r < n && arr[r] < arr[smallest]) //if right child samller than root
        smallest = r;                    //make right child as root
    if (smallest != i)
    { //if any of the child found to be greater, swap it with root
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, smallest); //do it recursively till it is heapified till the bottom
    }
}

void Make_min_heap(int arr[], int n)
{
    int start = (n / 2) - 1; //index of last non-leaf elements
    for (int i = start; i >= 0; i--)
    { //start heapifying in reverse
        heapify(arr, n, i);
    }
}
//Convert to max heap
void heapify2(int arr[], int n, int i)
{
    int largest = i;                    // largest is the root
    int l = 2 * i + 1;                  //left child
    int r = 2 * i + 2;                  //right child
    if (l < n && arr[l] > arr[largest]) //if left child greater than root
        largest = l;                    //make left child as root
    if (r < n && arr[r] > arr[largest]) //if right child greater than root
        largest = r;                    //make right child as root
    if (largest != i)
    { //if any of the child found to be greater, swap it with root
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify2(arr, n, largest); //do it recursively till it is heapified till the bottom
    }
}

void Make_max_heap(int arr[], int n)
{
    int start = (n / 2) - 1; //index of last non-leaf elements
    for (int i = start; i >= 0; i--)
    { //start heapifying in reverse
        heapify2(arr, n, i);
    }
}
void MinMax(int arr[], int n)
{
    Make_max_heap(arr, n);
    printf("\nArray form of max heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void MaxMin(int arr[], int n){
    Make_min_heap(arr, n);
    printf("\nArray form of min heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

bool isMAXHeap(int arr[], int i, int n)
{
    // If a leaf node
    if (i >= (n - 2) / 2)
        return true;

    // If an internal node and is
    // greater than its children,
    // and same is recursively
    // true for the children
    if (arr[i] >= arr[2 * i + 1] && arr[i] >= arr[2 * i + 2] && isMAXHeap(arr, 2 * i + 1, n) && isMAXHeap(arr, 2 * i + 2, n))
        return true;

    return false;
}

bool isMINHeap(int arr[],int i, int n)
{
    // If a leaf node
    if (i >= (n - 2) / 2)
        return true;

    // If an internal node and is
    // smaller than its children,
    // and same is recursively
    // true for the children
    if (arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2] && isMINHeap(arr, 2 * i + 1, n) && isMINHeap(arr, 2 * i + 2, n))
        return true;

    return false;
}
int main()
{
    int n = 11;
    int arr[11];
    int i;
    printf("Enter heap : \n");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(isMAXHeap(arr,i,n) == true){
        printf("MAX");
        MaxMin(arr, n);
    }
    else{
        printf("MIN");
        MinMax(arr, n);
    }
    return 0;
}
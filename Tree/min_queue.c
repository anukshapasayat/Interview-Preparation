#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void printheap(int arr[], int n)
{
    printf("\nArray form of min-queue:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n = 11;
    int arr[11];
    int i;
    printf("Enter the elements of the min-queue (smaller number greater priority) : \n");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &arr[i]);
    }
    Make_min_heap(arr, n);
    printheap(arr, n);
    return 0;
}
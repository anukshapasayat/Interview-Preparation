#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void heapify(int arr[], int n, int i)
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
        heapify(arr, n, largest); //do it recursively till it is heapified till the bottom
    }
}

void Make_max_heap(int arr[], int n)
{
    int start = (n / 2) - 1; //index of last non-leaf elements
    for (int i = start; i >= 0; i--)
    { //start heapifying in reverse
        heapify(arr, n, i);
    }
}

void printheap(int arr[], int n)
{
    printf("\nArray form of max heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n = 11;
    int arr[11];
    int i;
    printf("Enter the elements of the max-queue (greater number greater priority) : \n");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &arr[i]);
    }
    Make_max_heap(arr, n);
    printheap(arr, n);
    return 0;
}
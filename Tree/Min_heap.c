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

bool isHeap(int arr[], int i, int n)
{
    // If a leaf node
    if (i >= (n - 2) / 2)
        return true;

    // If an internal node and is
    // smaller than its children,
    // and same is recursively
    // true for the children
    if (arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2] && isHeap(arr, 2 * i + 1, n) && isHeap(arr, 2 * i + 2, n))
        return true;

    return false;
}

void insertNode(int arr[], int n, int Key)
{
    n = n + 1;
    arr[n - 1] = Key;
    printf("Checking if after adding the element is it heap or not: \n");
    if(isHeap != 0)
    printf("Heap !");
    else{
    printf("NOT Heap !");
    Make_min_heap(arr, n);}
}

void deleteRoot(int arr[], int n)
{
    // Get the last element
    int lastElement = arr[n - 1];
    // Replace root with last element
    arr[0] = lastElement;
    // Decrease size of heap by 1
    n = n - 1;
    printf("Checking if after deleting the element is it heap or not: \n");
    if(isHeap == true)
    printf("Heap !");
    else
    printf("NOT Heap !");
    Make_min_heap(arr, n);
}

void printheap(int arr[], int n)
{
    printf("\nArray form of min heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int n = 11;
    int arr[11];
    int i;
    printf("Enter the elements of the heap : \n");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &arr[i]);
    }
    Make_min_heap(arr, n);
    printheap(arr, n);
    int k;
    printf("What do you want to insert into the heap ?\n");
    scanf("%d",&k);
    insertNode(arr, n , k);
    printf("\nAfter inserting an element: \n");
    printheap(arr, n);
    printf("Deleting the root element:\n");
    deleteRoot(arr, n);
    printheap(arr, n);
    return 0;
}
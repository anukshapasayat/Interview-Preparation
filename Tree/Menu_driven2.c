#include<stdio.h>
#include<stdlib.h>
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
void replace(int arr[], int n, int pos, int val){
    arr[pos] = val;
}
void insertNode(int arr[], int n, int Key)
{
    n = n + 1;
    arr[n - 1] = Key;
    Make_min_heap(arr, n);
}

void deleteRoot(int arr[], int n)
{
    // Get the last element
    int lastElement = arr[n - 1];
    // Replace root with last element
    arr[0] = lastElement;
    // Decrease size of heap by 1
    n = n - 1;
    Make_min_heap(arr, n);
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
    }
}
int main(){
    int c, n, a =0, key, max = 0, pos, val;
    do{
    printf("\n0. Quit");
    printf("\n1. n Random numbers=>Array");
    printf("\n2. Display the Array");
    printf("\n3. Sort the Array in Descending Order by using Min-Heap Sort technique");
    printf("\n4. Sort the Array in Ascending Order by using any algorithm");
    printf("\n5. Extract largest element");
    printf("\n6. Replace value at a node with new value");
    printf("\n7. Insert a new element");
    printf("\n8. Delete an element");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    switch(c){
        case 0:
        exit(0);
        case 1: 
        printf("Enter size of array:");
        scanf("%d",&n);
        int arr[10];
        printf("Enter array elements: ");
        for(int i = 0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        break;
        case 2:
        for(int i = 0;i<n;i++){
            printf("%d ",arr[i]);
        }
        break;
        case 3:
        heapSort(arr, n);
        break;
        case 4:
        for (int i = 0; i < n; ++i) 
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (arr[i] > arr[j]) 
                {
                    a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
        }
        break;
        case 5:
         max = arr[0];
        for(int i = 1;i<n;i++){
            if(arr[i]>max)
            max = arr[i];
        }
        printf("%d",max);
        break;
        case 6:
        printf("\nEnter the position at which you want to enter the value :");
        scanf("%d",&pos);
        printf("\nEnter the value you want to change it with: ");
        scanf("%d",&val);
        replace(arr, n, pos, val);
        break;
        case 7:
        printf("\nEnter the value you want to insert: ");
        scanf("%d",&key);
        insertNode(arr, n, key);
        break;
        case 8:
        deleteRoot(arr, n);
        break;
        default:
        printf("Wrong Input!");
        break;
    }
    }while(c != 0);

}
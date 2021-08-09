#include<stdio.h>
#include<stdlib.h>

//A node structure
struct Node{
    int data;
    struct Node *next;
};

//PUSH Function : Adds an element in the beginning of the linked list
//Given a pointer to pointer head reference, and an int data to add.
void push(struct Node **headref, int data){
    //1. Allocate Node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    //2. Put Data.
    new_node->data = data;
    //3. Make the new node the head.
    new_node->next = (*headref);
    //4. Move the head to point to the new node.
    (*headref) = new_node;
}

//SwapNodes: Swap two nodes without swapping data
//1. x and y may or may not be adjacent.
//2. Either x or y may be a head node.
//3. Either x or y may be the last node.
//4. x and/or y may not be present in the linked list.
void swapNodes(struct Node **head_ref, int x, int y){
    //Check if x and y are same
    if(x == y)
    return;

    //Search of x while keeping track of prevX and currX
    struct Node *prevX = NULL, *currX = *head_ref;
    while(currX != NULL && currX->data != x){
        prevX = currX;
        currX = currX->next;
    }

    //Search of y while keeping track of prevY and currY
    struct Node *prevY = NULL, *currY = *head_ref;
    while(currY != NULL && currY->data != y){
        prevY = currY;
        currY = currY->next;
    }

    //Check if either x or y is absent
    if(currX == NULL || currY == NULL)
    return;

    //Check if x is head of list
    if(prevX != NULL)
    prevX->next = currY;
    else
    *head_ref = currY;

    //Check if y is head of list
    if(prevY != NULL)
    prevY->next = currX;
    else
    *head_ref = currX;

    //Swap next pointers
    struct Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp; 
}
//Print function : to print the list
void printlist(struct Node *head_ref){
    while(head_ref != NULL){
        printf("%d ", head_ref->data);
        head_ref = head_ref->next;
    }
    printf("\n");
}

//Main function
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 10);
    push(&head, 22);
    printlist(head);
    swapNodes(&head, 2, 10);
    printlist(head);
    return 0;
}
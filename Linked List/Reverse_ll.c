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

//Reverse a linked list
void reverse(struct Node **headref){
    struct Node *prev = NULL;
    struct Node *curr = *headref;
    struct Node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *headref = prev;
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
    reverse(&head);
    printlist(head);
    return 0;
}
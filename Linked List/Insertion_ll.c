#include<stdio.h>
#include<stdlib.h>

// A singly linked list node.
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

//INSERT_AFTER : Insert after a given node.
void insertAfter(struct Node *prev_node, int data){
    // Check if prev_node is null
    if(prev_node == NULL){
        printf("The previous node is null.");
        return;
    }
    //1. Allocate Node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    //2. Put Data.
    new_node->data = data;
    //3. Make next of new_node as next of prev_node.
    new_node->next = prev_node->next;
    //4. Make the new_node as next of prev_node.
    prev_node->next = new_node;
}

//APPEND Function : Adds an element in the beginning of the linked list
//Given a pointer to pointer head reference, and an int data to add.
void append(struct Node **headref, int data){
    //1. Allocate node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    // Used later
    struct Node *last = *headref;
    //2. Put data
    new_node->data = data;
    //3. Make the next of new_node null.
    new_node->next = NULL;
    //4. Check if the list is null
    if(*headref == NULL){
        *headref = new_node;
        return;
    }
    //5. Traverse through list to add at the end.
    while(last->next != NULL)
    last = last->next;
    //6. On reaching the last node add the new_node;
    last->next = new_node;
    return;
}

//Print function : to print the list
void printlist(struct Node *head_ref){
    while(head_ref != NULL){
        printf(" %d ", head_ref->data);
        head_ref = head_ref->next;
    }

}

//Main function
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    append(&head, 6);
    push(&head, 4);
    push(&head, 2);
    insertAfter(head->next, 7);
    append(&head, 24);
    printlist(head);
    return 0;
}

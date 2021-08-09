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

//GetCount1 : Count the number of nodes in the linked list using Iterative method
int getcount1 (struct Node *head){
    //1. Intialize count
    int count = 0;
    //2. Intialize a temp as head
    struct Node *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

//GetCount2 : COunt the number of nodes in the linked list using recursion
int getcount2 (struct Node *head){
    if(head == NULL)
    return 0;
    else
    return 1 + getcount2(head->next);
}

//Print function : to print the list
void printlist(struct Node *head_ref){
    while(head_ref != NULL){
        printf("%d ", head_ref->data);
        head_ref = head_ref->next;
    }

}

//Main function
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    push(&head, 4);
    push(&head, 2);
    push(&head, 6);
    printlist(head);
    printf("\n%d\n",getcount1(head));
    push(&head, 8);
    push(&head, 10);
    push(&head, 22);
    printlist(head);
    printf("\n%d\n",getcount2(head));
    return 0;
}
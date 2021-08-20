#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node; 
}
//Iteratively
bool search1(struct Node **head_ref, int key){
    struct Node *curr = *head_ref;
    while(curr != NULL){
        if(curr->data == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}
//Recursively
bool search2(struct Node *head_ref, int key){
    if(head_ref == NULL)
    return false;
    if((head_ref)->data == key ){
        return true;
    }
    else{
        return search2(head_ref->next, key);
    }
}

int main(){
    struct Node *head = NULL;
    push(&head, 5);
    push(&head, 25);
    push(&head, 53);
    push(&head, 55);
    push(&head, 35);
    push(&head, 45);
    push(&head, 65);
    if(search1(&head, 55) != 0){
        printf("Element 55 found !\n");
    }
    else{
        printf("Element 55 not found !\n");
    }
    if(search2(head, 55) != 0){
        printf("Element 55 found !\n");
    }
    else{
        printf("Element 55 not found !\n");
    }
}

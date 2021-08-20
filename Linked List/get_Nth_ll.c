#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
// From the beginning
int get_Nth(struct Node **headref, int n){
    int i = 1;
    struct Node *curr = *headref;
    while(curr != NULL && i<n){
        curr = curr->next;
        i++;
    }
    return (curr->data);
}
//From the end
int get_Nth_last(struct Node **head_ref, int n){
    int c = 0;
    struct Node *curr = *head_ref;
    while(curr != NULL){
        curr = curr->next;
        c++;
    }
    if(n>c)
    return -1;
    int i;
    curr = *head_ref;
    for(i = 0;i<c-n;i++){
        curr = curr->next;
    }
    return (curr->data);
}

int main(){
    struct Node *head = NULL;
    push(&head, 6);
    push(&head, 63);
    push(&head, 61);
    push(&head, 60);
    push(&head, 86);
    push(&head, 76);
    push(&head, 56);
    printf("%d\n", get_Nth(&head, 3));
    printf("%d", get_Nth_last(&head, 3));

}

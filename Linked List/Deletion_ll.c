#include<stdio.h>
#include<stdlib.h>

//A node structure
struct Node{
    int data;
    struct Node *next;
};

//Push Function to add elements in front of the list.
void push(struct Node **head_ref, int data){
    //1. Allocate memory.
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    //2. Add data.
    new_node->data = data;
    //3. Make the next of new_node as the head_ref.
    new_node->next = (*head_ref);
    //4. Make the new node as head.
    *head_ref = new_node;
}

//DeleteNode1 function : Delete the node when the key is given.
void deleteNode1(struct Node **headref, int key){
    //Store Head Node.
    struct Node *temp = *headref, *prev;
    //Check if the head is the key
    if(temp != NULL && temp->data == key){
        *headref = temp->next;
        free(temp);
        return;
    }
    //Search for the key and keep track of the previous node
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    //If the key not found
    if(temp == NULL)
    return;
    //Delink the node to be deleted
    prev->next = temp->next;
    //Free Memory
    free(temp);
}

//DeleteNode2 Function : To delete the node if position is given.
void deleteNode2(struct Node **head_ref, int position){
    //Check if list is empty
    if(*head_ref == NULL){
        return;
    }
    //Store the head node.
    struct Node *temp = *head_ref;
    //Check if the position is head
    if(position == 0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    //Find previous position to the node to be deleted.
    for(int i = 0; temp != NULL && i<position-1; i++ ){
        temp = temp->next;
    }
    //if position is more than the number of nodes
    if(temp == NULL || temp->next == NULL)
    return;
    //temp->next has to be deleted
    //Store temp->next->next in a new_node
    struct Node *next_node = temp->next->next;
    //Free temp->next
    free(temp->next);
    //Make next_node as next node of temp
    temp->next = next_node;
}

//Print function : to print the list
void printlist(struct Node *head_ref){
    while(head_ref != NULL){
        printf(" %d ", head_ref->data);
        head_ref = head_ref->next;
    }
    printf("\n");

}

//Main Function
int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 10);
    push(&head, 16);
    push(&head, 26);
    printlist(head);
    deleteNode1(&head, 4);
    printlist(head);
    deleteNode2(&head, 3);
    printlist(head);
    return 0;
}

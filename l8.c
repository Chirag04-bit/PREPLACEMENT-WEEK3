#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* reverse(struct Node* head) {
    struct Node* prev=NULL,*curr=head,*next=NULL;
    while(curr) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void push(struct Node** head,int data) {
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data; newNode->next=*head; *head=newNode;
}

void printList(struct Node* head) {
    while(head) { printf("%d -> ",head->data); head=head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    push(&head,1); push(&head,2); push(&head,3);
    printf("Before reverse: "); printList(head);
    head=reverse(head);
    printf("After reverse: "); printList(head);
    return 0;
}
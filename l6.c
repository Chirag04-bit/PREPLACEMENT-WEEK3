#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int detectLoop(struct Node* head) {
    struct Node *slow=head,*fast=head;
    while(slow && fast && fast->next) {
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}

void push(struct Node** head,int data) {
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data; newNode->next=*head; *head=newNode;
}

int main() {
    struct Node* head=NULL;
    push(&head,10); push(&head,20); push(&head,30);
    head->next->next->next=head; // create loop
    if(detectLoop(head)) printf("Loop detected\n");
    else printf("No loop\n");
    return 0;
}
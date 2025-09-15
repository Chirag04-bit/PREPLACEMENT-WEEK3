#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

void removeLoop(struct Node* loopNode, struct Node* head) {
    struct Node* ptr1=head;
    while(1) {
        struct Node* ptr2=loopNode;
        while(ptr2->next!=loopNode && ptr2->next!=ptr1)
            ptr2=ptr2->next;
        if(ptr2->next==ptr1) break;
        ptr1=ptr1->next;
    }
    struct Node* ptr2=loopNode;
    while(ptr2->next!=ptr1) ptr2=ptr2->next;
    ptr2->next=NULL;
}

int detectAndRemove(struct Node* head) {
    struct Node *slow=head,*fast=head;
    while(slow && fast && fast->next) {
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) {
            removeLoop(slow,head);
            return 1;
        }
    }
    return 0;
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
    push(&head,10); push(&head,20); push(&head,30);
    head->next->next->next=head; // loop
    detectAndRemove(head);
    printf("List after removing loop: "); printList(head);
    return 0;
}
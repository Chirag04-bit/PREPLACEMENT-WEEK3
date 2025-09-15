#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int search(struct Node* head, int key) {
    int pos=0;
    while(head) {
        if(head->data==key) return pos;
        head=head->next; pos++;
    }
    return -1;
}

void push(struct Node** head, int data) {
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data; newNode->next=*head; *head=newNode;
}

int main() {
    struct Node* head=NULL;
    push(&head,5); push(&head,15); push(&head,25);
    int key=15;
    int pos=search(head,key);
    if(pos!=-1) printf("Found %d at position %d\n",key,pos);
    else printf("Not found\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev=NULL;
    if(temp != NULL && temp->data==key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp && temp->data!=key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL) return;
    prev->next = temp->next;
    free(temp);
}

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* head) {
    while(head) { printf("%d -> ", head->data); head=head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* head=NULL;
    push(&head,10); push(&head,20); push(&head,30);
    printf("Before deletion: "); printList(head);
    deleteNode(&head,20);
    printf("After deletion: "); printList(head);
    return 0;
}
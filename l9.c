#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* newNode(int data) {
    struct Node* node=malloc(sizeof(struct Node));
    node->data=data; node->next=NULL;
    return node;
}

struct Node* addTwoLists(struct Node* l1, struct Node* l2) {
    struct Node *res=NULL, **node=&res;
    int carry=0;
    while(l1 || l2 || carry) {
        int sum=carry;
        if(l1) { sum+=l1->data; l1=l1->next; }
        if(l2) { sum+=l2->data; l2=l2->next; }
        carry=sum/10;
        *node=newNode(sum%10);
        node=&((*node)->next);
    }
    return res;
}

void printList(struct Node* head) {
    while(head) { printf("%d -> ",head->data); head=head->next; }
    printf("NULL\n");
}

int main() {
    struct Node* l1=newNode(2); l1->next=newNode(4); l1->next->next=newNode(3);
    struct Node* l2=newNode(5); l2->next=newNode(6); l2->next->next=newNode(4);
    struct Node* sum=addTwoLists(l1,l2);
    printf("Sum: "); printList(sum);
    return 0;
}
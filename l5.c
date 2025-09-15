#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

int nthFromEnd(struct Node* head, int n) {
    struct Node *main=head,*ref=head;
    int count=0;
    while(count<n) {
        if(ref==NULL) return -1;
        ref=ref->next; count++;
    }
    while(ref) { main=main->next; ref=ref->next; }
    return main->data;
}

void push(struct Node** head,int data) {
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data; newNode->next=*head; *head=newNode;
}

int main() {
    struct Node* head=NULL;
    for(int i=1;i<=5;i++) push(&head,i*10);
    int n=2;
    int ans=nthFromEnd(head,n);
    if(ans!=-1) printf("%dth node from end: %d\n",n,ans);
    else printf("Not enough nodes\n");
    return 0;
}
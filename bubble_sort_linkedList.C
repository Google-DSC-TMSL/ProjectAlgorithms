#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr){
    while (ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    
}

void bubble(struct node *p){
    struct node*q = (struct node*)malloc(sizeof(struct node));
    for(int i = 0;i < 5;i++){
        q = p->next;
        for(int j = 0;4 - i;j++){
            if(p->data > q->data){
                p->next = q->next;
                q->next = p;
            }
            p = p->next;
        }
    }
}


int main(){

    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth = (struct node*)malloc(sizeof(struct node));
    struct node *fifth = (struct node*)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 8;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = NULL;

    bubble(head);
    display(head);

    return 0;
}

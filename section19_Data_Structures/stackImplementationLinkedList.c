#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* link;
};

struct node* top = NULL;

void push(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = data;
        temp->link = top;
        top = temp;
    }
}

int isEmpty()
{
    return top == NULL;
}

void pop()
{
    struct node* temp;
    if(top != NULL){
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display()
{
    struct node* temp;
    if(top != NULL)
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d: \n", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();
    pop();
    pop();

    display();

    return 0;
}
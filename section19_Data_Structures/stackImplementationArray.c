#include <stdio.h>
#define MAXSIZE     5

struct stack{
    int stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;
STACK s;

void push(void);
int pop(void);
void display(void);

void main(void){
    int choice;
    int option = 1;
    s.top = -1;
    while(option)
    {
        printf("---------------------------------------\n");
        printf("1->push\n");
        printf("2->pop\n");
        printf("3->display\n");
        printf("4->exit\n");
        printf("---------------------------------------\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
        }
        fflush(stdin);
        printf("Do you want to continue(0 or 1)?\n");
        scanf("%d", &option);
    }
}

void push(void)
{
    int num = 0;;
    if(s.top == MAXSIZE - 1){
        printf("Stack is full\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed\n");
        scanf("%d", &num);
        s.top += 1;
        s.stk[s.top] = num;
    }
    return;
}

int pop(void)
{
    int num = 0;
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return s.top;
    }
    else
    {
        num = s.stk[s.top];
        printf("poped element is: %d\n", s.stk[s.top]);
        s.top -= 1;
    }
    return num;
}

void display(void)
{
    int i = 0;
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("\nThe status of the stack is: \n");
        for(i = s.top; i >= 0; i--){
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}
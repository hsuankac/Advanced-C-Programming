#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node* next;
};

struct node* createNode(int val);
void insertNodeAtTheBeginning();
void insertNodeAtTheEnd();
void insertNodeAtPosition();
void deletePosition();
void search();
void updateValue();
void display();

struct node *newNode, *ptr, *prev, *temp;
struct node *head = NULL, *tail = NULL;

int main(void)
{
    int ch = '\0';

    while(true)
    {
        printf("\n---------------------------\n");
        printf("\nOperations on a linked list\n");
        printf("\n---------------------------\n");
        printf("\n1.Insert node at beginning");
        printf("\n2.Insert node at end");
        printf("\n3.Insert node at a specific position");
        printf("\n4.Delete node from any position");
        printf("\n5.Update node value");
        printf("\n6.Search element in the linked list");
        printf("\n7.Display list");
        printf("\n8.Exit");
        printf("\n---------------------------\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insertNodeAtTheBeginning();
                break;
            case 2:
                insertNodeAtTheEnd();
                break;
            case 3:
                insertNodeAtPosition();
                break;
            case 4:
                deletePosition();
                break;
            case 5:
                updateValue();
                break;
            case 6:
                search();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\n...Exiting....\n");
                return 0;
                break;
            default:
                printf("\n....Invalid Choise...\n");
                break;
        }
    }
    return 0;
}

struct node* createNode(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("\nMemory was not allocated");
        return 0;
    }else{
        newNode->value = val;
        newNode->next = NULL;
        return newNode;
    }
}

void insertNodeAtTheBeginning()
{
    int val = 0;
    printf("\nEnter the value for the node: ");
    scanf("%d", &val);
    newNode = createNode(val);
    if(head == tail && head == NULL){
        head = tail = newNode;
        head->next = NULL;
        tail->next = NULL;
    }else{
        temp = head;
        head = newNode;
        head->next = temp;
    }
}

void insertNodeAtTheEnd()
{
    int val = 0;
    printf("\nEnter the value for the node: ");
    scanf("%d", &val);
    newNode = createNode(val);
    if(head == tail && head == NULL){
        head = tail = newNode;
        head->next = NULL;
        tail->next = NULL;
    }else{
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void insertNodeAtPosition()
{
    int pos, val, cnt = 0, i;
    printf("\nEnter the value for the node: ");
    scanf("%d", &val);
    newNode = createNode(val);
    printf("\nEnter the position");
    scanf("%d", &pos);
    ptr = head;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if(pos == 1)
    {
        if(head == tail && head == NULL)
        {
            head = tail = newNode;
            head->next = NULL;
            tail->next = NULL;
        }
        else
        {
            temp = head;
            head = newNode;
            head->next = temp;
        }
        printf("\n----Inserted----");
    }
    else if(pos > 1 && pos <= cnt)
    {
        ptr = head;
        for(i = 1; i < pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newNode;
        newNode->next = ptr;
        printf("\n----Inserted----");
    }
    else
    {
        printf("Position is out of range");
    }

}

void deletePosition()
{
    int pos, cnt = 0, i;
    if(head == NULL)
    {
        printf("List is empty\n");
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted: ");
        scanf("%d", &pos);
        ptr = head;
        if(pos == 1)
        {
            head = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while(ptr != NULL)
            {
                ptr = ptr->next;
                cnt += 1;
            }
            if(pos > 0 && pos <= cnt)
            {
                ptr = head;
                for(i = 1; i < pos; i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range ");
            }
            free(ptr);
            printf("\nElement deleted");
        }
    }
}

void updateValue()
{
    int oldval, newval, flag = 0;
    if(head == NULL)
    {
        printf("List is empty\n");
        printf("No nodes in the list to updatd\n");
    }
    else
    {
        printf("\nEnter the value to be updated: ");
        scanf("%d", &oldval);
        printf("\nEnter the new value: ");
        scanf("%d", &newval);
        for(ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->value == oldval)
            {
                ptr->value = newval;
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("\nUpdated successfully");
        }
        else
        {
            printf("\nValue not found in list");
        }
    }
}

void search()
{
    int flag = 0, key, pos = 0;
    if(head == NULL)
    {
        printf("List is empty\n");
        printf("No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search");
        scanf("%d",&key);
        for(ptr = head; ptr != NULL; ptr = ptr->next)
        {
            pos = pos + 1;
            if(ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("\nElement %d found at %d position", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}

void display()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        printf("No nodes in the list to display");
    }
    else
    {
        for(ptr = head; ptr != NULL; ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}
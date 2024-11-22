#include <stdio.h>
#include <stdlib.h>

/* self-referential structure*/
typedef struct node{
    char data;
    struct node* nextPtr;
} node_t;

typedef node_t* ListNodePtr;

/* prototypes*/
void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void)
{
    ListNodePtr head = NULL; /*initial there are no nodes*/
    int choice; /*user's choice*/
    char item = '\0';   /*char entered by user*/

    /* loop while usre does not enter choice 6*/
    while(1)
    {
        /* display the menu*/
        printf("Enter your choise:\n"
            " 1 to insert an element into the list in alphabetical order. \n"
            " 2 to insert an element at the end of the list. \n"
            " 3 to insert an element at the beginning of the list. \n"
            " 4 to delete an element from the list. \n"
            " 5 to delete an element from the beginning of the list. \n"
            " 6 to end. \n");
        printf(":: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&head, item);
            printList(head);
            break;
        case 2:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtEnd(&head, item);
            printList(head);
            break;
        case 3:
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insertAtBeginning(&head, item);
            printList(head);
            break;
        case 4:
            /* if list is not empty*/
            if(!isEmpty(head)){
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                /* if character is found, remove it*/
                if(delete(&head, item)){
                    printf("%c deleted.\n", item);
                    printList(head);
                }else{
                    printf("%c not found.\n\n", item);
                }
            }else{
                printf("List is empty.\n\n");
            }
            break;
        case 5:
            /* if list is not empty*/
            if(!isEmpty(head)){
                deleteAtBeginning(&head);
                printf("%c deleted.\n", item);
                printList(head);
            }else{
                printf("List is empty.\n\n");
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid choice:\n");
            break;
        }
    }
    printf("End of run.\n");
    return 0;
}

void insert(ListNodePtr *head, char value)
{
    ListNodePtr newPtr;
    ListNodePtr prevPtr;
    ListNodePtr currPtr;

    newPtr = malloc(sizeof(node_t));
    if(newPtr != NULL){
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        prevPtr = NULL;
        currPtr = *head;
        /* loop to find the correct location in the list*/
        while(currPtr != NULL && value > currPtr->data){
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }
        if(prevPtr == NULL){
            newPtr->nextPtr = *head;
            *head = newPtr;
        }else{
            prevPtr->nextPtr = newPtr;
            newPtr->nextPtr = currPtr;
        }
    }else{
        printf("%c not inserted. No memory available.\n", value);
    }
}

void insertAtEnd(ListNodePtr *head, char value)
{
    ListNodePtr current = *head;
    if (current != NULL)
    {
        while(current->nextPtr != NULL){
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->nextPtr = NULL;
        current->data = value;
        *head = current;
    }
}

void insertAtBeginning(ListNodePtr *head, char value)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}

char delete(ListNodePtr *head, char value)
{
    ListNodePtr tempPtr;
    ListNodePtr prevPtr;
    ListNodePtr currPtr;

    if(value == (*head)->data){
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        return value;
    }else{
        prevPtr = *head;
        currPtr = (*head)->nextPtr;
        while(currPtr != NULL && currPtr->data != value){
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }
        if(currPtr != NULL){
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

void deleteAtBeginning(ListNodePtr *head)
{
    ListNodePtr tempPtr = NULL;
    if(head == NULL){
        return;
    }else{
        tempPtr = *head;    /* hold onto node being removed*/
        *head = (*head)->nextPtr;   /* de-threaad the node*/
        free(tempPtr);  /* free the de-threaded node*/
    }
}

int isEmpty(ListNodePtr head)
{
    return head == NULL;
}

void printList(ListNodePtr currentPtr)
{
    if(currentPtr == NULL){
        printf("List is empty.\n\n");
    }else{
        printf("The list is: \n");
        while(currentPtr != NULL){
            printf("%c -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}
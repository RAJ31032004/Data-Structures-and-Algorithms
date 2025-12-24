#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }
}

void Display(PNODE first)
{
    printf("NULL <=> ");

    while(first != NULL)
    {
        printf("| %d | <=> ", first->data);
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0, i = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize + 1)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}


void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0, i = 0;
    PNODE temp = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    InsertLast(&head,101);
    InsertLast(&head,111);
    InsertLast(&head,121);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet);

    InsertAtPos(&head,105,3);
    Display(head);

    DeleteAtPos(&head,3);
    Display(head);

    DeleteFirst(&head);
    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Number of nodes : %d\n", iRet);

    return 0;
}

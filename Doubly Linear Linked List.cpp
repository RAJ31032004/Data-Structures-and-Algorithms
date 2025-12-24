// Doubly Linear

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE first;
        int iCount;

    public:
        DoublyLL()
        {
            cout<<"Object of DoublyLL gets created.\n";
            first = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                newn->next = first;
                first->prev = newn;
                first = newn;
            }
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(first == NULL)
            {
                first = newn;
            }
            else
            {
                PNODE temp = first;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
                newn->prev = temp;
            }
            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            if(pos < 1 || pos > iCount + 1)
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                InsertFirst(no);
            }
            else if(pos == iCount + 1)
            {
                InsertLast(no);
            }
            else
            {
                PNODE newn = new NODE;
                newn->data = no;
                newn->next = NULL;
                newn->prev = NULL;

                PNODE temp = first;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                newn->prev = temp;
                temp->next->prev = newn;
                temp->next = newn;

                iCount++;
            }
        }   // ✅ FIXED

        void DeleteFirst()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                PNODE temp = first;
                first = first->next;
                first->prev = NULL;
                delete temp;
            }
            iCount--;
        }

        void DeleteLast()
        {
            if(first == NULL)
            {
                return;
            }
            else if(first->next == NULL)
            {
                delete first;
                first = NULL;
            }
            else
            {
                PNODE temp = first;
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                DeleteFirst();
            }
            else if(pos == iCount)
            {
                DeleteLast();
            }
            else
            {
                PNODE temp = first;
                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                PNODE targ = temp->next;
                temp->next = targ->next;
                targ->next->prev = temp;
                delete targ;

                iCount--;
            }
        }

        void Display()
        {
            PNODE temp = first;
            while(temp != NULL)
            {
                cout<<"| "<<temp->data<<" | <-> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();

    cout<<"Number of nodes are : "<<obj.Count()<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.Display();

    cout<<"Number of nodes are : "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.InsertAtPos(105,4);
    obj.Display();

    obj.DeleteAtPos(4);
    obj.Display();

    cout<<"Number of nodes are : "<<obj.Count()<<"\n";
    return 0;
}

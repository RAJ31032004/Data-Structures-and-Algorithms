// Singly Circular

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
             PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else
            {
                newn->next = first;
                first = newn;
            }

            last->next = first;
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            if(first == NULL && last == NULL)
            {
                first = newn;
                last = newn;
            }
            else
            {
                last->next = newn;
                last = newn;
            }

            last->next = first;
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

                PNODE temp = first;

                for(int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteFirst()
        {
             if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                PNODE temp = first;
                first = first->next;
                delete temp;
                last->next = first;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if(first == NULL && last == NULL)
            {
                return;
            }
            else if(first == last)
            {
                delete first;
                first = NULL;
                last = NULL;
            }
            else
            {
                PNODE temp = first;

                while(temp->next != last)
                {
                    temp = temp->next;
                }

                delete last;
                last = temp;
                last->next = first;
            }

            iCount--;}

        
        
    void DeleteAtPos(int pos)
        {
            if(pos < 1 || pos > iCount)
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)    
                DeleteFirst();
            else if(pos == iCount)
                DeleteLast();
            else
            {
                PNODE temp = first;
                for(int i = 1; i < pos - 1; i++)
                    temp = temp->next;

                PNODE targ = temp->next;
                temp->next = targ->next;
                delete targ;
                iCount--;
            }
        }

       void Display()
        {
            if(first == NULL)
            {
                cout<<"Linked list is empty\n";
                return;
            }

            PNODE temp = first;

            do
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }
            while(temp != first);

            cout<<"(HEAD)\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}
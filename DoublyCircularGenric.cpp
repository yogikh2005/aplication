#include<iostream>
using namespace std;

#pragma pack(1) 
template<class T>
struct node
{  
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    public:
        struct node<T> * First;
        struct node<T> * Last;

        DoublyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};


template<class T>
DoublyCL<T> :: DoublyCL()  // Default constructor
{
    First = NULL;
    Last = NULL;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        newn->next = First;
        (First)->prev = newn;
        First = newn; 
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct node<T> *  newn = new struct node<T>; 

    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL)) // LL is empty
    {
        First = newn;
        Last = newn;
    }
    else    // If LL contains one or more nodes
    {
        (Last) -> next = newn;
        newn->prev = Last;
        Last = newn;
    }

    (First)->prev = Last;
    (Last)->next = First;
}

template<class T>
void DoublyCL<T> :: Display()
{
   struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct node<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);

    return iCnt;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        (First) = (First) ->next;
        delete (Last)->next;        // free((*First)->prev);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    int iNodeCnt = Count();
   struct node<T> * newn = NULL;
   struct node<T> *  temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt+1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        InsertFirst(no);
    }
    else if(ipos == iNodeCnt+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct node<T> *  temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

int main()
{
    int iRet = 0;
///////////////////////////////////////////////////////////////////////////////////////////////
    DoublyCL <int>iobj;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

   iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    iobj.InsertAtPos(105,5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    iobj.DeleteAtPos(5);
    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    iRet = iobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

///////////////////////////////////////////////////////////////////////////////////////////////
   cout<<"\n\n";
   DoublyCL <char>cobj;

    cobj.InsertFirst('g');
    cobj.InsertFirst('o');
    cobj.InsertFirst('y');
    
    cobj.InsertLast('i');
  

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.InsertAtPos('m',5);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.DeleteAtPos(5);
    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
	
///////////////////////////////////////////////////////////////////////////////////////////////
   cout<<"\n\n";
   DoublyCL <float>fobj;

    fobj.InsertFirst(3.5f);
    fobj.InsertFirst(5.5f);
    fobj.InsertFirst(6.6f);
    
    fobj.InsertLast(7.7f);
  

    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    fobj.InsertAtPos(11.11f,5);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    fobj.DeleteAtPos(5);
    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    fobj.DeleteFirst();
    fobj.DeleteLast();

    fobj.Display();
    iRet = fobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
	
///////////////////////////////////////////////////////////////////////////////////////////////
   cout<<"\n\n";
   DoublyCL <double>dobj;

    dobj.InsertFirst(3.5);
    dobj.InsertFirst(5.5);
    dobj.InsertFirst(6.6);
    
   dobj.InsertLast(7.7);
  

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.InsertAtPos(11.11,5);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.DeleteAtPos(5);
    dobj.Display();
    iRet =dobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";
    return 0;
}
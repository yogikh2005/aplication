#include<iostream>
using namespace std;

#pragma pack(1)
template<class T>
struct node
{
    T data;
    struct node<T> *next;
};

template<class T>
class SinglyCL
{
    public:
        struct node<T> * First;
       struct node<T> * Last;

        SinglyCL();

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
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> *newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last) -> next = newn;
        Last = newn;
        (Last)->next = First;
    }
}

template<class T>
void SinglyCL<T>::Display()
{
    struct node<T> *temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    struct node<T> * temp = First;

    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last->next);
    return iCnt;
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    struct node<T> * temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    {
        //free(*First);
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        First = (First)->next;
        //free(temp);
        delete temp;

        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
struct node<T> *temp = First;

    if((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node in LL
    { 
        delete First;

        First = NULL;
        Last = NULL;
    }
    else    // If LL contains more than 1 node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }

        delete temp->next;

        Last = temp; 
        (Last) ->next = First;
    }
}

template<class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T> * newn = NULL;
   struct node<T> * temp = First;

    if((ipos < 1) || (ipos > iNodeCnt + 1))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
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

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = 0, iCnt = 0;
    iNodeCnt = Count();
    struct node<T> *temp1 = First;
   struct node<T> * temp2 = NULL;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }   
        temp2 = temp1 ->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

int main()
{
    SinglyCL <int>iobj;

    int iRet = 0;
    
    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

    iobj.InsertAtPos(105,5);

    iobj.Display();
    iRet = iobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    iobj.DeleteAtPos(5);


    iobj.Display();
    iRet = iobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    iRet = iobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
	
/////////////////////////////////////////////////////////////////////////////////////////////
cout<<"\n\n";
SinglyCL <char>cobj;

    
    cobj.InsertFirst('g');
    cobj.InsertFirst('o');
   cobj.InsertFirst('y');
    
    cobj.InsertLast('i');
    cobj.InsertLast('r');
    cobj.InsertLast('a');

    cobj.InsertAtPos('m',5);

    cobj.Display();
    iRet = cobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    cobj.DeleteAtPos(5);


    cobj.Display();
    iRet = cobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    iRet = cobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

/////////////////////////////////////////////////////////////////////////////////////////////
cout<<"\n\n";
SinglyCL <float>fobj;

    
    fobj.InsertFirst(4.4f);
    fobj.InsertFirst(5.6f);
    fobj.InsertFirst(7.7f);
    
    fobj.InsertLast(11.1f);
    fobj.InsertLast(21.2f);
    fobj.InsertLast(121.4f);

    fobj.InsertAtPos(11.5f,5);

    fobj.Display();
    iRet = fobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    fobj.DeleteAtPos(5);


    fobj.Display();
    iRet = fobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    fobj.DeleteFirst();
    fobj.DeleteLast();

    fobj.Display();
    iRet = fobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";



/////////////////////////////////////////////////////////////////////////////////////////////
cout<<"\n\n";
SinglyCL <double>dobj;

    
    dobj.InsertFirst(4.4);
    dobj.InsertFirst(5.6);
    dobj.InsertFirst(7.7);
    
    dobj.InsertLast(11.1);
    dobj.InsertLast(21.2);
    dobj.InsertLast(121.4);

    dobj.InsertAtPos(11.55,5);

    dobj.Display();
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);


    dobj.Display();
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    return 0;
}
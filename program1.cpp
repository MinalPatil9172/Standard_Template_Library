#include<iostream>
using namespace std;

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Class Name   : SinglyLL 
//   Description  : This class represents singly linear linked list    
// 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct slnode
{
    T data;
    struct slnode *next;
};

template <class T>
class SinglyLL
{
    private:
    struct slnode<T> * Head;
    int iSize;
    
    public:
    SinglyLL();
    void Display();
    int Count();
    void InsertFirst(T);
    T SearchFirst();
    T SearchLast();
    void DeleteFirst();
    void DeleteLast();
    void InsertLast(T);
    ~SinglyLL();

};



// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Class Name   : DoublyLL 
//   Description  : This class represents Doubly  linear linked list    
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct dlnode
{
    T data;
    struct dlnode *prev;
    struct dlnode *next;
};

template <class T>
class Doubly_LL
{
private:
    struct dlnode<T> * Head;
    int iSize;
    
public:
    Doubly_LL();
    void Display();
    int Count();
    void InsertFirst(T);
    T SearchFirst();
    T SearchLast();
    void DeleteFirst();
    void DeleteLast();
    void InsertLast(T);

};
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Class Name   : Singly_Circular_LL 
//   Description  : This class represents Singly Circular Linked List    
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct scnode
{
    T data;
    struct scnode *next;
};



template <class T>
class Singly_Circular_LL
{
    private:
    struct scnode<T> * Head;
    struct scnode<T> *Tail;
    int iSize;
    
public:
    Singly_Circular_LL();
    void Display();
    int Count();
    void InsertFirst(T);
    T DisplayFirst();
    T DisplayLast();
    void DeleteFirst();
    void DeleteLast();
    void InsertLast(T);

};


// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Class Name   : Doubly_Circular_LL 
//   Description  : This class represents Doubly  Circular linked list    
// 
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct dcnode
{
    T data;
    struct dcnode *prev;
    struct dcnode *next;
};



template <class T>
class Doubly_Circular_LL
{
private:
    struct dcnode<T> * Head;
    struct dcnode<T>*Tail;
    int iSize;
    
public:
    Doubly_Circular_LL();
    void Display();
    int Count();
    void InsertFirst(T);
    T SearchFirst();
    T SearchLast();
    void DeleteFirst();
    void DeleteLast();
    void InsertLast(T);

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Description   : Methods of Singly linear linked list
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
SinglyLL<T> :: SinglyLL()
{
    Head = NULL;
    iSize = 0;
}

template <class T> 
void SinglyLL<T> :: InsertFirst(T no)//class template cha aahe
{
    struct slnode<T> *newn = new struct slnode<T>;
    newn->data = no;
    newn->next = NULL;

    newn->next = Head;
    Head = newn;
    iSize++;
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iSize;
}

template <class T>
void SinglyLL<T> :: Display()
{
    struct slnode<T> *temp = Head;//node is template
    cout<<"Elements In Linked List:  ";
    if(Head==NULL)
    {
       cout<<"Linked List is Empty\n";

    }
    else
    {
       while(temp != NULL)
        {
        cout<<temp->data<<"\t";
        temp = temp->next;
        }
    }
     cout<<"\n\n";
}
template <class T>
T SinglyLL<T> :: SearchFirst()
{
   return Head->data;    

}
template<class T>
T SinglyLL<T>::SearchLast()
{
    struct slnode<T>*temp=Head;
    
    while((temp->next)!=NULL)
    {
        temp=temp->next;
    }
     return temp->data;

}
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct slnode<T>*temp=Head;
    Head=Head->next;
    delete temp;
    iSize--;
     cout<<"After deleting first element ";
    Display();

}
template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct slnode<T>*temp=Head;
     while((temp->next->next)!=NULL)
     {
         temp=temp->next;
     }
     delete temp->next;
     iSize--;
     temp->next=NULL;
     cout<<"After deleting last element ";

     Display();

}
template <class T> 
void SinglyLL<T> :: InsertLast(T no)//class template cha aahe
{
    struct slnode<T> *newn = new struct slnode<T>;
    newn->data = no;
    newn->next = NULL;

     struct slnode<T>*temp=Head;

     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newn;
    iSize++;
    Display();
}
template<class T>
SinglyLL<T>::~SinglyLL()
{
   struct slnode<T> *temp;
    for(int i=1;i<=iSize;i++)
    {
        temp=Head;
        Head=temp->next;
        delete temp;
        
    }
    


}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Description :Methods for Doubly Linear Linked List
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Doubly_LL<T> :: Doubly_LL()
{
    Head = NULL;
    iSize = 0;
}

template <class T> 
void Doubly_LL<T> :: InsertFirst(T no)//class template cha aahe
{
    struct dlnode<T> *newn = new struct dlnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev=NULL;

    newn->next = Head;
    Head=newn;
    newn->prev=newn;
    iSize++;
}

template <class T>
int Doubly_LL<T> :: Count()
{
    return iSize;
}

template <class T>
void Doubly_LL<T> :: Display()
{
    struct dlnode<T> *temp = Head;//node is template
    cout<<"Elements In Linked List:  ";
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n\n";
}
template <class T>
T Doubly_LL<T> :: SearchFirst()
{
   return Head->data;    

}
template<class T>
T Doubly_LL<T>::SearchLast()
{
    struct dlnode<T>*temp=Head;
    
    while((temp->next)!=NULL)
    {
        temp=temp->next;
    }
     return temp->data;

}
template<class T>
void Doubly_LL<T>::DeleteFirst()
{
    struct dlnode<T>*temp=Head;
    Head=Head->next;
    delete temp;
    iSize--;
     cout<<"After deleting first element ";
    Display();

}
template<class T>
void Doubly_LL<T>::DeleteLast()
{
    struct dlnode<T>*temp=Head;
     while((temp->next->next)!=NULL)
     {
         temp=temp->next;
     }
     delete temp->next;
     iSize--;
     temp->next=NULL;
     cout<<"After deleting last element ";

     Display();

}
template <class T> 
void Doubly_LL<T> :: InsertLast(T no)//class template cha aahe
{
    struct dlnode<T> *newn = new struct dlnode<T>;
    newn->data = no;
    newn->next = NULL;

     struct dlnode<T>*temp=Head;

     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=newn;
     newn->prev=temp;
    iSize++;
    cout<<"afret Inserting at last ";
    Display();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//              Description   : Methods for Singly Circular Linked List
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
Singly_Circular_LL<T> :: Singly_Circular_LL()
{
    Head = NULL;
    Tail=NULL;
    iSize = 0;
}

template <class T> 
void Singly_Circular_LL<T> :: InsertFirst(T no)//class template cha aahe
{
    struct scnode<T> *newn = new struct scnode<T>;
    newn->data = no;
    newn->next = NULL;

     if((Head == NULL) && (Tail == NULL))    // LL is empty
        {
            Head = newn;
            Tail = newn;
        }
        else    // LL contains atleast one node
        {
            newn->next = Head;
            Head = newn;
        }
        iSize++;
        Tail -> next = Head;
       
}
template <class T>
void Singly_Circular_LL<T> :: Display()
{
    struct scnode<T> *temp = Head;//node is template
    cout<<"Elements In Linked List:  ";
    for(int i=1;i<=iSize;i++)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n\n";
}

template <class T>
int Singly_Circular_LL<T> :: Count()
{
    return iSize;
}


template <class T>
T Singly_Circular_LL<T> :: DisplayFirst()
{
   return Head->data;    

}

template<class T>
T Singly_Circular_LL<T>::DisplayLast()
{
    return Tail->data;

}

template<class T>
void Singly_Circular_LL<T>::DeleteFirst()
{
    struct scnode<T>*temp=Head;
    Head=Head->next;
    delete Tail->next;
    Tail->next=Head;
    iSize--;
    cout<<"after deleting first value ";
    Display();

}

template<class T>
void Singly_Circular_LL<T>::DeleteLast()
{
    struct scnode<T>*temp=Head;
    while((temp->next)!=Tail)
    {
        temp=temp->next;
    }
    delete Tail;
    Tail=temp;
    temp->next=Head;
     iSize--;
     cout<<"After deleting last value ";

     Display();

}
template <class T> 
void Singly_Circular_LL<T> :: InsertLast(T no)//class template cha aahe
{
    struct scnode<T> *newn = new struct scnode<T>;
    newn->data = no;
    newn->next = NULL;

    newn->next=Tail;
    Tail->next=newn;
    Tail=newn;      
    iSize++;
    cout<<"After inserting last value ";

    Display();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        Description   :Doubly Circular  Linked  List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Doubly_Circular_LL<T> :: Doubly_Circular_LL()
{
    Head = NULL;
    Tail=NULL;
    iSize = 0;
}

template <class T> 
void Doubly_Circular_LL<T> :: InsertFirst(T no)//class template cha aahe
{
    struct dcnode<T> *newn = new struct dcnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev=NULL;

    if(iSize==0)
    {
        Head=newn;
        Tail=newn;
        newn->next=newn;
    
    }
    else
    {
       newn->next=Head;
       Head->prev=newn;
       Head=newn;
       newn->prev=Tail;
       Tail->next=newn;

    }
    iSize++;
    Head=Tail->next;

}

template <class T>
int Doubly_Circular_LL<T> :: Count()
{

    return iSize;
}

template <class T>
void Doubly_Circular_LL<T> :: Display()
{

    struct dcnode<T> *temp = Head;//node is template
    cout<<"Elements In Linked List:  ";
    for(int i=1;i<=iSize;i++)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n\n";
}
template <class T>
T Doubly_Circular_LL<T> :: SearchFirst()
{
   return Head->data;    

}
template<class T>
T Doubly_Circular_LL<T>::SearchLast()
{
    
     return Tail->data;

}
template<class T>
void Doubly_Circular_LL<T>::DeleteFirst()
{
    Head=Head->next;
    delete Tail->next;
    Head->prev=Tail;
    Tail->next=Head;
    iSize--;
     cout<<"After deleting first element ";
    Display();

}
template<class T>
void Doubly_Circular_LL<T>::DeleteLast()
{
      Tail=Tail->prev;
      Tail->next=Head;
      delete Head->prev;
      Head->prev=Tail;
      iSize--;
     cout<<"After deleting last element ";

     Display();

}
template <class T> 
void Doubly_Circular_LL<T> :: InsertLast(T no)//class template cha aahe
{
    struct dcnode<T> *newn = new struct dcnode<T>;
    newn->data = no;
    newn->next = NULL;

     newn->next=Head;
     newn->prev=Tail;
     Tail->next=newn;
     Tail=newn;
     Head->prev=newn;
    iSize++;
    cout<<"afret Inserting at last ";
    Display();
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//             Description  :Main Function
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{    
    int iret=0;
    cout<<"*************************************************************************************************\n\n";
    cout<<"\t\tSingly Linear Linked List\n\n";
    cout<<"*************************************************************************************************\n";

    SinglyLL <int> slobj;
    int no=20;
    slobj.InsertFirst(no);
    no++;
    slobj.InsertFirst(no);
    no++;
    slobj.InsertFirst(no);
    no++;
    slobj.InsertFirst(no);
    slobj.Display();
    cout<<"Length of linked list is : "<<slobj.Count()<<"\n\n";
    
    iret=slobj.SearchFirst();
    cout<<"First Element is: "<<iret<<"\n\n";
   
    iret=slobj.SearchLast();
    cout<<"Last Element is: "<<iret<<"\n\n";

    slobj.DeleteFirst();
    slobj.DeleteLast();

    no++;
    slobj.InsertLast(no);

     
   
    cout<<"*************************************************************************************************\n\n";
    cout<<"\t\tDoubly Linear Linked List\n\n";
    cout<<"*************************************************************************************************\n";

    Doubly_LL <int> obj;
    
    obj.InsertFirst(no);
    no++;
    obj.InsertFirst(no);
    no++;
    obj.InsertFirst(no);
    no++;
    obj.InsertFirst(no);
    obj.Display();
    cout<<"Length of linked list is : "<<obj.Count()<<"\n\n";
    
    iret=obj.SearchFirst();
    cout<<"First Element is: "<<iret<<"\n\n";
   
    iret=obj.SearchLast();
    cout<<"Last Element is: "<<iret<<"\n\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    no++;
    obj.InsertLast(no);  

     cout<<"*************************************************************************************************\n\n";
    cout<<"\t\tSingly Circular Linked List\n\n";
    cout<<"*************************************************************************************************\n";

    Singly_Circular_LL <int> scobj;
    scobj.InsertFirst(no);
    no++;
    scobj.InsertFirst(no);
    no++;
    scobj.InsertFirst(no);
    no++;
    scobj.InsertFirst(no);
    scobj.Display();
    cout<<"Length of linked list is : "<<scobj.Count()<<"\n\n";
    
    iret=scobj.DisplayFirst();
    cout<<"First Element is: "<<iret<<"\n\n";
   
    iret=scobj.DisplayLast();
    cout<<"Last Element is: "<<iret<<"\n\n";

    scobj.DeleteFirst();
    scobj.DeleteLast();

    no++;
    scobj.InsertLast(no);
    
    cout<<"*************************************************************************************************\n\n";
    cout<<"\t\tDoubly Circular Linked List\n\n";
    cout<<"*************************************************************************************************\n";

    Doubly_Circular_LL <int> dcobj;
    
    dcobj.InsertFirst(no);
    no++;
    dcobj.InsertFirst(no);
    no++;
    dcobj.InsertFirst(no);
    no++;
    dcobj.InsertFirst(no);
    dcobj.Display();
    cout<<"Length of linked list is : "<<dcobj.Count()<<"\n\n";
    
    iret=dcobj.SearchFirst();
    cout<<"First Element is: "<<iret<<"\n\n";
   
    iret=dcobj.SearchLast();
    cout<<"Last Element is: "<<iret<<"\n\n";

    dcobj.DeleteFirst();
    dcobj.DeleteLast();

    no++;
    dcobj.InsertLast(no);
       
    return 0;
}

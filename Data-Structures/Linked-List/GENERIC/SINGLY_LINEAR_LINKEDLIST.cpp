//1========================al=======================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Singly Linear Linked-List is a type of linked-list where each node points to the   //
//Next node in the sequence while keeping the ends pointing to nullptr. This program demonstrates //
//the implementation of Generic Singly Linear Linked List .                                       //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 4th April 2025                                                                            //
//Day: Friday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
#include<limits>
using namespace std;

//2===============================================================================================//






//3================================================================================================//

template<class Generic>
struct sNode//Structure declaration for node in Generic Singly Linear Linked List
{
    Generic gData;//Data of the node
    struct sNode<Generic> *pNext;//Pointer to the next node in the linked list
};//sNODE, *PsNODE;


template<class Generic>
class SINGLY_LINEAR_LINKEDLIST
{
    private:
        struct sNode<Generic> *pHead;//Pointer to the first node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

    public:
        int iCountNode_Main;//Counter for number of nodes in linkedlist for main function which isn't directly used for class functions .
        SINGLY_LINEAR_LINKEDLIST();//Constructor to initialize the singly linear linked list
        ~SINGLY_LINEAR_LINKEDLIST();//Destructor to delete the singly linear linked list


//======Simple Access Functions======//

        //Insertion functions
        void InsertFirst(Generic);
        void InsertLast(Generic);
        void InsertAtPosition(Generic,int);

        //Deletion functions
        Generic DeleteFirst();
        Generic DeleteLast();
        Generic DeleteAtPosition(int);

        //Traversal functions
        int Count() const;
        void Display() const;

//~=====Simple Access Functions======//



//======Added Features Functions======//

        //Search and Update functions
        int Search(Generic) const;
        bool UpdateNoForNo(Generic,Generic);
        void UpdateNoForPosition(Generic,int);

        //Insert and Delete functions
        void InsertBefore(Generic,int);
        void InsertAfter(Generic,int);
        Generic DeleteBefore(int);
        Generic DeleteAfter(int);
        void DeleteList();

        //Sorting and Reversing functions
        void SortAscending();
        void Reverse();

        //Finding functions
        struct sNode<Generic> * FindMiddleNode() const;
        struct sNode<Generic> * FindKthNodeFromStart(int) const;
        struct sNode<Generic> * FindKthNodeFromMiddle(int,int) const;
        struct sNode<Generic> * FindKthNodeFromEnd(int) const;

//~=====Added Features Functions======//



        //Manual
        void Manual();
};


template<class Generic>
SINGLY_LINEAR_LINKEDLIST<Generic>::SINGLY_LINEAR_LINKEDLIST()
{
    pHead = nullptr;
    iCountNode = 0;
    iCountNode_Main = 0;
}


template<class Generic>
SINGLY_LINEAR_LINKEDLIST<Generic>::~SINGLY_LINEAR_LINKEDLIST()
{
    DeleteList();
}

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Singly Linear Linked-List                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions:                                                                                      //
//================================================================================================//
//Insertion:                                                                                      //
//1. InsertFirst() : Inserts a new node at the beginning of the linked list .                     //
//2. InsertLast() : Inserts a new node at the end of the list .                                   //
//3. InsertAtPosition() : Inserts a new node at a specified position in the linked .              //
//================================================================================================//
//Deletion:                                                                                       //
//4. DeleteFirst() : Deletes the first node of the linked list .                                  //
//5. DeleteLast() : Deletes the last node of the linked list .                                    //
//6. DeleteAtPosition() : Deletes the node at a specified position in the linked list .           //
//================================================================================================//
//Traversal:                                                                                      //
//7. Display() : Displays the contents of the linked list .                                       //
//8. Count() : Counts the number of nodes in the linked list .                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Display() Function: Displays the entire singly linear linked list .                             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Temporary pointer to traverse the linked list .                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::Display() const
{
    if((iCountNode == 0) && (pHead == nullptr))
    {
        cout<<"Linkedlist is empty"<<endl;
        cout<<"nullptr"<<endl;
        return;
    }

    cout<<"Elements from linked list are : "<<endl<<endl;
    struct sNode<Generic> *ptemp = pHead;

    while(ptemp != nullptr)
    {
        cout<<"| "<<ptemp -> gData<<" | -> ";
        ptemp = ptemp -> pNext;
    }
    cout<<"nullptr"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the singly linear linked list .                      //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
int SINGLY_LINEAR_LINKEDLIST<Generic>::Count() const
{
    return iCountNode;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the singly linear linked list .  //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Pointer to the new node .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::InsertFirst(Generic gNo)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = nullptr;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = nullptr;

    if((iCountNode == 0) && (pHead == nullptr))//If linkedlist is empty(pHead == nullptr)
    {
        pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the singly linear linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Pointer to the new node .                                          //
//2. struct sNode<Generic> * : Temporary pointer for traversal                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::InsertLast(Generic gNo)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = nullptr;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = nullptr;

    if((pHead == nullptr) && (iCountNode == 0))//If linkedlist is empty((pHead -> pNext) == nullptr)
    {
        pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        struct sNode<Generic> *ptemp = pHead;

        while(ptemp -> pNext != nullptr)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the singly linear      //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//2. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Pointer to the new node .                                          //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//3. int                     : Counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::InsertAtPosition(Generic gNo,int iPosition)
{
    if(iPosition == 1)//If position is 1
    {
        InsertFirst(gNo);
        return;
    }
    else if(iPosition == (iCountNode + 1))//If position last
    {
        InsertLast(gNo);
        return;
    }
    else//Random position
    {
        struct sNode<Generic> *PsNewNode = nullptr;
        PsNewNode = new sNode<Generic>;

        PsNewNode -> gData = gNo;
        PsNewNode -> pNext = nullptr;

        struct sNode<Generic> *ptemp = pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        iCountNode++;
        iCountNode_Main++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the singly linear linked list .        //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. Generic                 : variable to return the deleted data                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
Generic SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteFirst()
{
    Generic gDeleted = 0;

    if(iCountNode == 1)//If linkedlist contains one node
    {
        gDeleted = pHead -> gData;

        delete pHead;
        pHead = nullptr;
    }
    else//If linkedlist contains atleast one node
    {
        struct sNode<Generic> *ptemp = pHead;
        pHead = ptemp -> pNext;

        gDeleted = ptemp -> gData;

        delete ptemp;
        ptemp = nullptr;
    }

    iCountNode--;
    iCountNode_Main--;

    return gDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the singly linear linked list .               //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. Generic                 : variable to return the deleted data                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
Generic SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteLast()
{
    Generic gDeleted = 0;

    if(iCountNode == 1)//If linkedlist contains one node
    {
        gDeleted = pHead -> gData;

        delete pHead;
        pHead = nullptr;
    }
    else//If linkedlist contains atleast two node
    {
        struct sNode<Generic> *ptemp = pHead;

        while(ptemp -> pNext -> pNext != nullptr)
        {
            ptemp = ptemp -> pNext;
        }

        gDeleted = ptemp -> pNext -> gData;
        delete ptemp -> pNext;
        ptemp -> pNext = nullptr;
    }

    iCountNode--;
    iCountNode_Main--;
    return gDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the singly linear    //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position at which the new node is to be deleted .                                      //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to delete the node .                             //
//3. Generic                 : Counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
Generic SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteAtPosition(int iPosition)
{
    Generic gCnt = 0;

    if(iPosition == 1)//If position is 1
    {
        gCnt = DeleteFirst();
        return gCnt;
    }
    else if(iPosition == iCountNode)//If position last
    {
        gCnt = DeleteLast();
        return gCnt;
    }
    else//Random position
    {
        struct sNode<Generic> *ptemp = pHead;
        struct sNode<Generic> *ptempdelete = nullptr;

        for(gCnt = 1;gCnt < (iPosition - 1);gCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        gCnt = ptempdelete -> gData;
        delete ptempdelete;
        ptempdelete = nullptr;

        iCountNode--;
        iCountNode_Main--;
        return gCnt;
    }
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Other Functions:                                                                                //
//================================================================================================//
//1. Search() : Searches for a specific value in the list                                         //
//2. Reverse() : Reverses the order of the list                                                   //
//3. Sort() : Sorts the list in ascending order                                                   //
//4. UpdateNoforNo() : Updates the value of a specific node in exchange to some value             //
//5. UpdateNoForPosition() : Updates the value of a specific node at specific position            //
//6. InsertBefore() : Inserts a new node before a specific node                                   //
//7. InsertAfter() : Inserts a new node after a specific node                                     //
//8. DeleteBefore() : Deletes the node before a specific node                                     //
//9. DeleteAfter() : Deletes the node after a specific node                                       //
//10. DeleteList() : Deletes the entire list                                                      //
//11. FindMiddle() : Finds the middle node of the list                                            //
//12. FindKthNodeFromStart() : Finds the kth node from the start of the list                      //
//13. FindKthNodeFromMiddle() : Finds the kth node from the middle of the list                    //
//14. FindKthNodeFromEnd() : Finds the kth node from the end of the list                          //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Search() Function: Searches for a specific value from the singly linear linked list .           //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Temporary pointer to traverse linkedlist .                         //
//2. int                     : Counter variable & Position variable in one .                      //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
int SINGLY_LINEAR_LINKEDLIST<Generic>::Search(Generic gSearch) const
{
    struct sNode<Generic> *ptemp = pHead;
    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(ptemp -> gData == gSearch)
        {
            return iPosition;
        }

        ptemp = ptemp -> pNext;
        iPosition++;
    }

    return -1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value in the singly linear//
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//2. Generic : Value to be updated in the linked list .                                           //
//================================================================================================//
//Return: bool                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Temporary pointer to traverse linkedlist .                         //
//2. int                     : Counter variable & Position variable in one .                      //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
bool SINGLY_LINEAR_LINKEDLIST<Generic>::UpdateNoForNo(Generic gSearch,Generic gUpdate)
{
    struct sNode<Generic> *ptemp = pHead;
    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(ptemp-> gData == gSearch)
        {
            ptemp -> gData = gUpdate;

            return true;
        }

        ptemp = ptemp -> pNext;
        iPosition++;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForPosition() Function: Updates the value at a specific position in singly linear linked//
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//2. int : Value at which data is to be inserted in linked list .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Temporary pointer to traverse linkedlist .                         //
//2. int                     : Counter variable & Position variable in one .                      //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::UpdateNoForPosition(Generic gUpdate,int iPosition)
{
    struct sNode<Generic> *ptemp = pHead;
    int iCnt = 1;

    while(iCnt <= iCountNode)
    {
        if(iCnt == iPosition)
        {
            ptemp -> gData = gUpdate;

            return;
        }

        ptemp = ptemp -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in singly linear linked list . //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//2. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : Pointer to store the new node                                      //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::InsertBefore(Generic gNo,int iPosition)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = nullptr;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = nullptr;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
    }
    else
    {
        struct sNode<Generic> *ptemp = pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;//Freeing the temporary pointer
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in singly linear linked list .   //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//2. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : Pointer to store the new node                                      //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::InsertAfter(Generic gNo,int iPosition)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = nullptr;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = nullptr;

    struct sNode<Generic> *ptemp = pHead;

    if(iPosition == iCountNode)
    {
        //InsertLast(pHead,iNo); ---> Can be used

        while(ptemp -> pNext != nullptr)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;;//Freeing the temporary pointer
    }
    else
    {
        for(int iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before a specified node from singly linear linked list .//
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to delete the node .                             //
//3. Generic                 : Counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
Generic SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteBefore(int iPosition)
{
    struct sNode<Generic> *ptemp = pHead;
    Generic gCnt = 0;

    if(iPosition == 2)
    {
        pHead = ptemp -> pNext;

        gCnt = ptemp -> gData;
        delete ptemp;
        ptemp = nullptr;
    }
    else
    {
        struct sNode<Generic> *ptempdelete = nullptr;

        for(gCnt = 1;gCnt < (iPosition - 2);gCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        gCnt = ptempdelete -> gData;

        delete ptempdelete;
        ptempdelete = nullptr;
    }

    iCountNode--;
    iCountNode_Main--;
    return gCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from singly linear linked list .   //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the new node is to be deleted .                                  //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to delete the node .                             //
//3. Generic                 : Counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
Generic SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteAfter(int iPosition)
{
    struct sNode<Generic> *ptemp = pHead;
    Generic gCnt = 0;

    if(iPosition == (iCountNode - 1))
    {
        while(ptemp -> pNext -> pNext != nullptr)
        {
            ptemp = ptemp -> pNext;
        }

        gCnt = ptemp -> pNext -> gData;

        delete ptemp -> pNext;
        ptemp -> pNext = nullptr;
    }
    else
    {
        struct sNode<Generic> *ptempdelete = nullptr;

        for(gCnt = 1;gCnt < (iPosition);gCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        gCnt = ptempdelete -> gData;
        delete ptempdelete;
        ptempdelete = nullptr;
    }

    iCountNode--;
    iCountNode_Main--;

    return gCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire singly linear linked list .                           //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::DeleteList()
{
    struct sNode<Generic> *ptempdelete = pHead;

    while(pHead -> pNext != nullptr)
    {
        ptempdelete = pHead;
        pHead = pHead -> pNext;

        delete ptempdelete;
        ptempdelete = nullptr;

        iCountNode--;
        iCountNode_Main--;
    }

    delete pHead;
    pHead = nullptr;

    iCountNode--;
    iCountNode_Main--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the singly linear linked list in ascending order .              //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//3. int : temporary variable to store the data of the node .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::SortAscending()
{
    struct sNode<Generic> *ptemp1 = pHead;
    struct sNode<Generic> *ptemp2 = pHead;
    Generic gtransfer = 0;

    for(ptemp1 = pHead;ptemp1 -> pNext != nullptr;ptemp1 = ptemp1 -> pNext)
    {
        for(ptemp2 = ptemp1 -> pNext;ptemp2 != nullptr;ptemp2 = ptemp2 -> pNext)
        {
            if(ptemp1 -> gData > ptemp2 -> gData)
            {
                gtransfer = ptemp1 -> gData;
                ptemp1 -> gData = ptemp2 -> gData;
                ptemp2 -> gData = gtransfer;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in singly linear linked list .                   //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::Reverse()
{
    struct sNode<Generic> *ptempNext = nullptr;
    struct sNode<Generic> *ptempPrev = nullptr;

    while(pHead != nullptr)
    {
        ptempNext = pHead -> pNext;
        pHead -> pNext = ptempPrev;
        ptempPrev = pHead;
        pHead = ptempNext;
    }

    pHead = ptempPrev;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the singly linear linked list .         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. int    : integer to store counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> * SINGLY_LINEAR_LINKEDLIST<Generic>::FindMiddleNode() const
{
    struct sNode<Generic> *ptemp = pHead;

    for(int iCnt = 1;iCnt < ((iCountNode + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: returns the kth node from start from singly linear linkedlist .//
//================================================================================================//
//Parameters:                                                                                     //
//1. int : integer to store kth position from start .                                             //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//3. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> * SINGLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromStart(int iKth) const
{
    struct sNode<Generic> *ptemp = pHead;

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from singly linear linked    //
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : integer to store kth position from start .                                             //
//2. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> * SINGLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromMiddle(int iKth,int iDirection) const
{
    struct sNode<Generic> *ptemp = pHead;

    if(iDirection == 1)
    {
        iKth = ((iCountNode + 1)/2) - iKth;
    }
    else
    {
        iKth = ((iCountNode + 1)/2) + iKth;
    }

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end from singly linear linkedlist .    //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : variable as offset from start of list to find .                                        //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int    : integer to store counter variable .                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> * SINGLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromEnd(int iKth) const
{
    struct sNode<Generic> *ptemp = pHead;

    for(int iCnt = 1;iCnt < (iCountNode - iKth + 1);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


//5===============================================================================================//





//6===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of singly-linear-linked-list .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void SINGLY_LINEAR_LINKEDLIST<Generic>::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's SINGLY LINEAR LINKED LIST APPLICATION::::"<<endl<<endl<<endl;


    cout<<"-----Below are functionalities provided for simple access of linked list(After entering 2 in ModeSelection stage)-----"<<endl<<endl;

    cout<<"INSERTION"<<endl;
    cout<<"For Inserting data at FIRST      position : press A"<<endl;
    cout<<"For Inserting data at LAST       position : press B"<<endl;
    cout<<"For Inserting data at SPECIFIC   position : press C"<<endl<<endl;

    cout<<"DELETION"<<endl;
    cout<<"For Deleting  data at  First     position : press D"<<endl;
    cout<<"For Deleting  data at  LAST      position : press E"<<endl;
    cout<<"For Deleting  data at  SPECIFIC  position : press F"<<endl<<endl;

    cout<<"COUNT"<<endl;
    cout<<"To Count no. of nodes in linked list      : press G"<<endl<<endl;

    cout<<"DISPLAY"<<endl;
    cout<<"To View data in linked list               : press H"<<endl<<endl<<endl;


    cout<<"-----Below are functionalities provided for added features of linked list(After entering 3 in ModeSelection stage)-----"<<endl<<endl;

    cout<<"SEARCHING AND MERGING"<<endl;
    cout<<"To Search a Specific Value in linkedlist  : press I"<<endl;
    cout<<"To Reverse the linkedList                 : press J"<<endl;
    cout<<"To Sort the linkedlist                    : press M"<<endl<<endl;

    cout<<"UPDATING"<<endl;
    cout<<"To Update value with a unique value in LL : press N"<<endl;
    cout<<"To Update value at a position in LL       : press O"<<endl<<endl;

    cout<<"INSERTION 2"<<endl;
    cout<<"To Insert a node before a specific node   : press P"<<endl;
    cout<<"To Insert a node after a specific node    : press Q"<<endl<<endl;

    cout<<"DELETION 2"<<endl;
    cout<<"To Delete a node before a specific node   : press R"<<endl;
    cout<<"To Delete a node after a specific node    : press S"<<endl;
    cout<<"To Delete the entire linkedlist           : press T"<<endl<<endl;

    cout<<"FINDING"<<endl;
    cout<<"To Find middle node of LL                 : press V"<<endl;
    cout<<"To Find kth node from start of LL         : press X"<<endl;
    cout<<"To Find kth node from middle of LL        : press Y"<<endl;
    cout<<"To Find kth node from end of LL           : press Z"<<endl<<endl;

    cout<<"COUNT"<<endl;
    cout<<"To Count no. of nodes in linked list      : press G"<<endl<<endl;

    cout<<"DISPLAY"<<endl;
    cout<<"To View data in linked list               : press H"<<endl<<endl<<endl;


    cout<<"Below are the modes in which you can operate"<<endl<<endl;

    cout<<"For Manual                      : press 1"<<endl;
    cout<<"For Simple Access of linkedlist : press 2"<<endl;
    cout<<"For use of Added features       : press 3"<<endl;
    cout<<"To  Exit                        : press 4"<<endl<<endl<<endl;


    cout<<"Below are the datatype in which you can operate"<<endl<<endl;

    cout<<"For Integer number linked list : press 1"<<endl;
    cout<<"For Decimal number linked list : press 2"<<endl;
    cout<<"To exit the LinkedList App     : press 3"<<endl<<endl;
}


int main()
{
    cout<<"Welcome to Rajas's Application of Generic-Singly-Linear-LinkedList"<<endl<<endl;

    char siChoiceMode[] = {"\0"};
    char cChoiceFunction = '\0';

    int iEntryCount = 0;
    float fEntryCount = 0.0f;

    SINGLY_LINEAR_LINKEDLIST <int>SinglyLinearLL_Integer;
    SINGLY_LINEAR_LINKEDLIST <float>SinglyLinearLL_Float;

    int iPosition1 = 0,iRet = 0;
    bool bRet = false;

    while(1)
    {
        cout<<"===================================================================================================="<<endl;
        cout<<"For Integer number linked list : Press 1"<<endl;
        cout<<"For Decimal number linked list : Press 2"<<endl;
        cout<<"For Terminating application    : Press 3"<<endl;
        cout<<"Enter your choice              : ";
        cin>>siChoiceMode;


        if(atoi(siChoiceMode) == 1)
        {
            if(iEntryCount != 0)
            {
                cout<<"===================================================================================================="<<endl;
                cout<<"Would you like to continue with your old Integer Linked-List data : Yes[Y] or No[N]"<<endl;
                cin>>siChoiceMode;

                if((siChoiceMode[0] == 'N') || (siChoiceMode[0] == 'n'))
                {
                    SinglyLinearLL_Integer.~SINGLY_LINEAR_LINKEDLIST();
                    SINGLY_LINEAR_LINKEDLIST <int>SinglyLinearLL_Integer;
                }
            }
            iEntryCount++;

            siChoiceMode[0] = '\0';

            int iNo1 = 0,iNo2,iPosition1 = 0;
            struct sNode<int> *pRet = nullptr;

            while(atoi(siChoiceMode) != 4)
            {
                cout<<"===================================================================================================="<<endl;
                cout<<"Datatype Mode : Integer-linkedlist"<<endl;
                cout<<"For Manual of Application        : Press 1"<<endl;
                cout<<"For Simple Access of linkedlist  : Press 2"<<endl;
                cout<<"For Added Features of linkedlist : Press 3"<<endl;
                cout<<"To Exit Integer-Linkedlist Mode  : Press 4"<<endl;
                cout<<"Enter the mode of operation : ";
                cin>>siChoiceMode;

                if(atoi(siChoiceMode) == 1)
                {
                    SinglyLinearLL_Integer.Manual();//Display the manual for the application
                }
                else if(atoi(siChoiceMode) == 2)
                {
                    cout<<"Active Mode : SIMPLE ACCESS"<<endl;

                    while(atoi(siChoiceMode) != 1)
                    {
                        cout<<"===================================================================================================="<<endl;
                        cout<<"To exit SIMPLE ACCESS mode : press Z"<<endl;
                        cout<<"To view the manual : press Y"<<endl;
                        cout<<"Enter the function to be performed : ";
                        cin>>cChoiceFunction;

                        switch(cChoiceFunction)
                        {
                            case 'A':
                            case 'a':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                SinglyLinearLL_Integer.InsertFirst(iNo1);
                                cout<<"Node with data "<<iNo1<<" inserted at the beginning of the singly linear linked list"<<endl;

                                break;
                            case 'B':
                            case 'b':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                SinglyLinearLL_Integer.InsertLast(iNo1);
                                cout<<"Node with data "<<iNo1<<" inserted at the end of the singly linear linked list"<<endl;

                                break;
                            case 'C':
                            case 'c':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                cout<<"Enter the position at which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;
                                while((iPosition1 < 1) || (iPosition1 > (SinglyLinearLL_Integer.iCountNode_Main + 1)))
                                {
                                    cout<<"Enter the position between 1 <-> "<<(SinglyLinearLL_Integer.iCountNode_Main + 1)<<" : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                }

                                SinglyLinearLL_Integer.InsertAtPosition(iNo1,iPosition1);
                                cout<<"Node with data "<<iNo1<<" inserted at position "<<iPosition1<<" in the singly linear linked list"<<endl;

                                break;
                            case 'D':
                            case 'd':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    iRet = SinglyLinearLL_Integer.DeleteFirst();
                                    cout<<"Node with data "<<iRet<<" deleted from the beginning of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'E':
                            case 'e':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    iRet = SinglyLinearLL_Integer.DeleteLast();
                                    cout<<"Node with data "<<iRet<<" deleted from the end of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'F':
                            case 'f':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the position from which the data is to be deleted : ";
                                    cin>>iPosition1;
                                    cout<<endl;
                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    iRet = SinglyLinearLL_Integer.DeleteAtPosition(iPosition1);
                                    cout<<"Node with data "<<iRet<<" deleted from the position "<<iPosition1<<" from the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'G':
                            case 'g':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Integer.Display();
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'H':
                            case 'h':
                                iRet = SinglyLinearLL_Integer.Count();
                                cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                                break;
                            case 'Y':
                            case 'y':
                                SinglyLinearLL_Integer.Manual();//Display the manual for the application

                                break;
                            case 'Z':
                            case 'z':
                                cout<<"Exiting SIMPLE ACCESS mode"<<endl;
                                siChoiceMode[0] = '1';

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 3)
                {
                    cout<<"Active Mode : ADDED FEATURES"<<endl;

                    while(atoi(siChoiceMode) != 1)
                    {
                        cout<<"===================================================================================================="<<endl;
                        cout<<"To exit ADDED FEATURES mode : press A"<<endl;
                        cout<<"To view the manual : press B"<<endl;
                        cout<<"Enter the function to be performed : ";
                        cin>>cChoiceFunction;

                        switch(cChoiceFunction)
                        {
                            case 'B':
                            case 'b':
                                SinglyLinearLL_Integer.Manual();//Display the manual for the application

                                break;
                            case 'G':
                            case 'g':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Integer.Display();
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'H':
                            case 'h':
                                iRet = SinglyLinearLL_Integer.Count();
                                cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                                break;
                            case 'I':
                            case 'i':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be searched in the linked list : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    iRet = SinglyLinearLL_Integer.Search(iNo1);
                                    if(iRet != -1)
                                    {
                                        cout<<"Element "<<iNo1<<" is found at position "<<iRet<<" in singly linear linked list"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Element "<<iNo1<<" wasn't found in singly linear linked list"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'J':
                            case 'j':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Integer.Reverse();
                                    cout<<"!! Linked-List has been Reversed !!"<<endl;
                                }

                                cout<<"Linked-List is empty"<<endl;

                                break;
                            case 'M':
                            case 'm':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Integer.SortAscending();
                                    cout<<"Singly Linear Linked-List has been sorted in ascending order"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'N':
                            case 'n':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be updated in the linked list : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the value to be updated with : ";
                                    while((!(cin>>iNo2)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    bRet = SinglyLinearLL_Integer.UpdateNoForNo(iNo1,iNo2);
                                    if(bRet == true)
                                    {
                                        cout<<"Element "<<iNo1<<" has been updated to "<<iNo2<<" in singly linear linked list"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Element "<<iNo1<<" not found in singly linear linked list"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'O':
                            case 'o':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be updated at a specific position in the linked list : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position at which the data is to be updated : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1) || (cin.peek() != '\n')))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Integer.UpdateNoForPosition(iNo1,iPosition1);
                                    cout<<"Element at position "<<iPosition1<<" has been updated to "<<iNo1<<" in singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'P':
                            case 'p':
                                if(SinglyLinearLL_Integer.iCountNode_Main > 0)
                                {
                                    cout<<"Enter the data to be inserted in the linked list : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position before which the data is to be inserted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Integer.InsertBefore(iNo1,iPosition1);
                                    cout<<"Node with data "<<iNo1<<" inserted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'Q':
                            case 'q':
                                if(SinglyLinearLL_Integer.iCountNode_Main > 0)
                                {
                                    cout<<"Enter the data to be inserted in the linked list : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position before which the data is to be inserted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Integer.InsertAfter(iNo1,iPosition1);
                                    cout<<"Node with data "<<iNo1<<" inserted at the position "<<(iPosition1 + 1)<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'R':
                            case 'r':
                                if(SinglyLinearLL_Integer.iCountNode_Main > 1)
                                {
                                    cout<<"Enter the position before which the data is to be deleted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 2) || (iPosition1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 2 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    iRet = SinglyLinearLL_Integer.DeleteBefore(iPosition1);
                                    cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'S':
                            case 's':
                                if(SinglyLinearLL_Integer.iCountNode_Main > 1)
                                {
                                    cout<<"Enter the position before which the data is to be deleted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > (SinglyLinearLL_Integer.iCountNode_Main - 1)))
                                    {
                                        cout<<"Enter the position between 2 <-> "<<(SinglyLinearLL_Integer.iCountNode_Main - 1)<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    iRet = SinglyLinearLL_Integer.DeleteAfter(iPosition1);
                                    cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'T':
                            case 't':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Integer.DeleteList();
                                    cout<<"Linked-List has been deleted ."<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'V':
                            case 'v':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    pRet = SinglyLinearLL_Integer.FindMiddleNode();

                                    if(pRet != nullptr)
                                    {
                                        cout<<"The data in middle node from the linked list is : "<<pRet -> gData<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Invalid position"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked_List is empty!!"<<endl;
                                }

                                break;
                            case 'X':
                            case 'x':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from start : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iNo1 < 1) || (iNo1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : "<<endl;
                                        while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    pRet = SinglyLinearLL_Integer.FindKthNodeFromStart(iNo1);
                                    cout<<"Data in "<<iNo1<<" node from start is : "<<pRet -> gData<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'Y':
                            case 'y':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from middle : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((iNo1 < 1) || (iNo1 > (SinglyLinearLL_Integer.iCountNode_Main/2)))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<(SinglyLinearLL_Integer.iCountNode_Main/2)<<" : "<<endl;
                                        while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    cout<<"Kth node from start or end ? >>Press 1 : FOR start [OR] >>Press 2 : FOR end ::: Your choice : ";
                                    while((!(cin>>iNo2)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((iNo2 < 0) || (iNo2 > 1))
                                    {
                                        cout<<"Enter 0 or 1 : "<<endl;
                                        while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }


                                    pRet = SinglyLinearLL_Integer.FindKthNodeFromMiddle(iNo1,iNo2);
                                    if(iNo2 == 1)
                                    {
                                        cout<<"Data in "<<iNo1<<" node from middle to start is : "<<pRet -> gData<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Data in "<<iNo1<<" node from middle to end is : "<<pRet -> gData<<endl;
                                    }

                                    break;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'Z':
                            case 'z':
                                if(SinglyLinearLL_Integer.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from end : ";
                                    while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iNo1 < 1) || (iNo1 > SinglyLinearLL_Integer.iCountNode_Main))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<SinglyLinearLL_Integer.iCountNode_Main<<" : "<<endl;
                                        while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    pRet = SinglyLinearLL_Integer.FindKthNodeFromEnd(iNo1);
                                    cout<<"Data in "<<iNo1<<" node from start is : "<<pRet -> gData<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'A':
                            case 'a':
                                cout<<"Exiting ADDED FEATURES mode"<<endl;
                                siChoiceMode[0] = '1';

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }

                    continue;
                }
                else if(atoi(siChoiceMode) == 4)
                {
                    cout<<"Exiting the RAJAS's SINGLY LINEAR LINKEDLIST application"<<endl;
                    break;
                }
                else
                {
                    cout<<"Invalid choice"<<endl;
                    continue;
                }
            }
        }
        else if(atoi(siChoiceMode) == 2)
        {
            if(fEntryCount != 0.0f)
            {
                cout<<"===================================================================================================="<<endl;
                cout<<"Would you like to continue with your old Decimal Linked-List data : Yes[Y] or No[N]"<<endl;
                cin>>siChoiceMode;

                if((siChoiceMode[0] == 'N') || (siChoiceMode[0] == 'n'))
                {
                    SinglyLinearLL_Float.~SINGLY_LINEAR_LINKEDLIST();
                    SINGLY_LINEAR_LINKEDLIST <float>SinglyLinearLL_Float;
                }
            }
            fEntryCount++;

            siChoiceMode[0] = '\0';

            float fNo1 = 0,fNo2,fRet = 0;
            struct sNode<float> *pRet = nullptr;

            while(atoi(siChoiceMode) != 4)
            {
                cout<<"===================================================================================================="<<endl;
                cout<<"Datatype Mode : Decimal-linkedlist"<<endl;
                cout<<"For Manual of Application        : Press 1"<<endl;
                cout<<"For Simple Access of linkedlist  : Press 2"<<endl;
                cout<<"For Added Features of linkedlist : Press 3"<<endl;
                cout<<"To Exit Decimal-Linkedlist Mode  : Press 4"<<endl;
                cout<<"Enter the mode of operation : ";
                cin>>siChoiceMode;

                if(atoi(siChoiceMode) == 1)
                {
                    SinglyLinearLL_Float.Manual();//Display the manual for the application
                }
                else if(atoi(siChoiceMode) == 2)
                {
                    cout<<"Active Mode : SIMPLE ACCESS"<<endl;

                    while(atoi(siChoiceMode) != 1)
                    {
                        cout<<"===================================================================================================="<<endl;
                        cout<<"To exit SIMPLE ACCESS mode : press Z"<<endl;
                        cout<<"To view the manual : press Y"<<endl;
                        cout<<"Enter the function to be performed : ";
                        cin>>cChoiceFunction;

                        switch(cChoiceFunction)
                        {
                            case 'A':
                            case 'a':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                SinglyLinearLL_Float.InsertFirst(fNo1);
                                cout<<"Node with data "<<fNo1<<" inserted at the beginning of the singly linear linked list"<<endl;

                                break;
                            case 'B':
                            case 'b':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                SinglyLinearLL_Float.InsertLast(fNo1);
                                cout<<"Node with data "<<fNo1<<" inserted at the end of the singly linear linked list"<<endl;

                                break;
                            case 'C':
                            case 'c':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }

                                cout<<"Enter the position at which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;
                                while((iPosition1 < 1) || (iPosition1 > (SinglyLinearLL_Float.iCountNode_Main + 1)))
                                {
                                    cout<<"Enter the position between 1 <-> "<<(SinglyLinearLL_Float.iCountNode_Main + 1)<<" : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                }

                                SinglyLinearLL_Float.InsertAtPosition(fNo1,iPosition1);
                                cout<<"Node with data "<<fNo1<<" inserted at position "<<iPosition1<<" in the singly linear linked list"<<endl;

                                break;
                            case 'D':
                            case 'd':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    fRet = SinglyLinearLL_Float.DeleteFirst();
                                    cout<<"Node with data "<<fRet<<" deleted from the beginning of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'E':
                            case 'e':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    fRet = SinglyLinearLL_Float.DeleteLast();
                                    cout<<"Node with data "<<fRet<<" deleted from the end of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'F':
                            case 'f':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the position from which the data is to be deleted : ";
                                    cin>>iPosition1;
                                    cout<<endl;
                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    fRet = SinglyLinearLL_Float.DeleteAtPosition(iPosition1);
                                    cout<<"Node with data "<<fRet<<" deleted from the position "<<iPosition1<<" from the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'G':
                            case 'g':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Float.Display();
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'H':
                            case 'h':
                                iRet = SinglyLinearLL_Float.Count();
                                cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                                break;
                            case 'Y':
                            case 'y':
                                SinglyLinearLL_Float.Manual();//Display the manual for the application

                                break;
                            case 'Z':
                            case 'z':
                                cout<<"Exiting SIMPLE ACCESS mode"<<endl;
                                siChoiceMode[0] = '1';

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 3)
                {
                    cout<<"Active Mode : ADDED FEATURES"<<endl;

                    while(atoi(siChoiceMode) != 1)
                    {
                        cout<<"===================================================================================================="<<endl;
                        cout<<"To exit ADDED FEATURES mode : press A"<<endl;
                        cout<<"To view the manual : press B"<<endl;
                        cout<<"Enter the function to be performed : ";
                        cin>>cChoiceFunction;

                        switch(cChoiceFunction)
                        {
                            case 'B':
                            case 'b':
                                SinglyLinearLL_Float.Manual();//Display the manual for the application

                                break;
                            case 'G':
                            case 'g':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Float.Display();
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'H':
                            case 'h':
                                iRet = SinglyLinearLL_Float.Count();
                                cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                                break;
                            case 'I':
                            case 'i':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be searched in the linked list : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    iRet = SinglyLinearLL_Float.Search(fNo1);
                                    if(iRet != -1)
                                    {
                                        cout<<"Element "<<fNo1<<" is found at position "<<iRet<<" in singly linear linked list"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Element "<<fNo1<<" wasn't found in singly linear linked list"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'J':
                            case 'j':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Float.Reverse();
                                    cout<<"!! Linked-List has been Reversed !!"<<endl;
                                }

                                cout<<"Linked-List is empty"<<endl;

                                break;
                            case 'M':
                            case 'm':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Float.SortAscending();
                                    cout<<"Singly Linear Linked-List has been sorted in ascending order"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'N':
                            case 'n':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be updated in the linked list : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the value to be updated with : ";
                                    while((!(cin>>fNo2)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    bRet = SinglyLinearLL_Float.UpdateNoForNo(fNo1,fNo2);
                                    if(bRet == true)
                                    {
                                        cout<<"Element "<<fNo1<<" has been updated to "<<fNo2<<" in singly linear linked list"<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Element "<<fNo1<<" not found in singly linear linked list"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'O':
                            case 'o':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the value to be updated at a specific position in the linked list : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position at which the data is to be updated : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1) || (cin.peek() != '\n')))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Float.UpdateNoForPosition(fNo1,iPosition1);
                                    cout<<"Element at position "<<iPosition1<<" has been updated to "<<fNo1<<" in singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'P':
                            case 'p':
                                if(SinglyLinearLL_Float.iCountNode_Main > 0)
                                {
                                    cout<<"Enter the data to be inserted in the linked list : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position before which the data is to be inserted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Float.InsertBefore(fNo1,iPosition1);
                                    cout<<"Node with data "<<fNo1<<" inserted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'Q':
                            case 'q':
                                if(SinglyLinearLL_Float.iCountNode_Main > 0)
                                {
                                    cout<<"Enter the data to be inserted in the linked list : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    cout<<"Enter the position before which the data is to be inserted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((iPosition1 < 1) || (iPosition1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    SinglyLinearLL_Float.InsertAfter(fNo1,iPosition1);
                                    cout<<"Node with data "<<fNo1<<" inserted at the position "<<(iPosition1 + 1)<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'R':
                            case 'r':
                                if(SinglyLinearLL_Float.iCountNode_Main > 1)
                                {
                                    cout<<"Enter the position before which the data is to be deleted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 2) || (iPosition1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter the position between 2 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    fRet = SinglyLinearLL_Float.DeleteBefore(iPosition1);
                                    cout<<"Node with data "<<fRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'S':
                            case 's':
                                if(SinglyLinearLL_Float.iCountNode_Main > 1)
                                {
                                    cout<<"Enter the position before which the data is to be deleted : ";
                                    while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((iPosition1 < 1) || (iPosition1 > (SinglyLinearLL_Float.iCountNode_Main - 1)))
                                    {
                                        cout<<"Enter the position between 2 <-> "<<(SinglyLinearLL_Float.iCountNode_Main - 1)<<" : ";
                                        while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    fRet = SinglyLinearLL_Float.DeleteAfter(iPosition1);
                                    cout<<"Node with data "<<fRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                                }
                                else
                                {
                                    cout<<"!!Not Enough Nodes!!"<<endl;
                                }

                                break;
                            case 'T':
                            case 't':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    SinglyLinearLL_Float.DeleteList();
                                    cout<<"Linked-List has been deleted ."<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'V':
                            case 'v':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    pRet = SinglyLinearLL_Float.FindMiddleNode();

                                    if(pRet != nullptr)
                                    {
                                        cout<<"The data in middle node from the linked list is : "<<pRet -> gData<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Invalid position"<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked_List is empty!!"<<endl;
                                }

                                break;
                            case 'X':
                            case 'x':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from start : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((fNo1 < 1) || (fNo1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : "<<endl;
                                        while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    pRet = SinglyLinearLL_Float.FindKthNodeFromStart(fNo1);
                                    cout<<"Data in "<<fNo1<<" node from start is : "<<pRet -> gData<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'Y':
                            case 'y':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from middle : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((fNo1 < 1) || (fNo1 > (SinglyLinearLL_Float.iCountNode_Main/2)))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<(SinglyLinearLL_Float.iCountNode_Main/2)<<" : "<<endl;
                                        while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    cout<<"Kth node from start or end ? >>Press 1 : FOR start [OR] >>Press 0 : FOR end ::: Your choice : ";
                                    while((!(cin>>fNo2)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                    while((fNo2 < 0) || (fNo2 > 1))
                                    {
                                        cout<<"Enter 0 or 1 : "<<endl;
                                        while((!(cin>>fNo2)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }


                                    pRet = SinglyLinearLL_Float.FindKthNodeFromMiddle(fNo1,fNo2);
                                    if(fNo2 == 1)
                                    {
                                        cout<<"Data in "<<fNo1<<" node from middle to start is : "<<pRet -> gData<<endl;
                                    }
                                    else
                                    {
                                        cout<<"Data in "<<fNo1<<" node from middle to end is : "<<pRet -> gData<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'Z':
                            case 'z':
                                if(SinglyLinearLL_Float.iCountNode_Main != 0)
                                {
                                    cout<<"Enter the kth position from end : ";
                                    while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }

                                    while((fNo1 < 1) || (fNo1 > SinglyLinearLL_Float.iCountNode_Main))
                                    {
                                        cout<<"Enter offset between 1 <-> "<<SinglyLinearLL_Float.iCountNode_Main<<" : "<<endl;
                                        while((!(cin>>fNo1)) || (cin.peek() != '\n'))
                                        {
                                            cout<<"Invalid input. Please enter a single integer : ";
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                        }
                                    }

                                    pRet = SinglyLinearLL_Float.FindKthNodeFromEnd(fNo1);
                                    cout<<"Data in "<<fNo1<<" node from start is : "<<pRet -> gData<<endl;
                                }
                                else
                                {
                                    cout<<"!!Linked-List is empty!!"<<endl;
                                }

                                break;
                            case 'A':
                            case 'a':
                                cout<<"Exiting ADDED FEATURES mode"<<endl;
                                siChoiceMode[0] = '1';

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }

                    continue;
                }
                else if(atoi(siChoiceMode) == 4)
                {
                    cout<<"Exiting the RAJAS's SINGLY LINEAR LINKEDLIST application"<<endl;
                    break;
                }
                else
                {
                    cout<<"Invalid choice"<<endl;
                    continue;
                }
            }
        }
        else if(atoi(siChoiceMode) == 3)
        {
            cout<<"GoodBye's from the Rajas's Application of Generic-Singly-Linear-LinkedList"<<endl<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
            continue;
        }
    }
}

//6===============================================================================================//
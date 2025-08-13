//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Doubly Circular Linked-List is a type of linked-list where each node points to the //
//Next And Previous node in the sequence while keeping the ends pointing to each other.This       //
//program demonstrates the implementation of Doubly Circular Linked List .                        //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 16th April 2025                                                                           //
//Day: Wednesday                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
#include<limits>
using namespace std;

//2===============================================================================================//






//3================================================================================================//

struct sNode//Structure declaration for node in Doubly Circular Linked List
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
    struct sNode *pPrev;//Pointer to the previous node in the linked list
};//sNODE, *PsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node


class DOUBLY_CIRCULAR_LINKEDLIST
{
    private:
        PsNODE pHead;//Pointer to the first node of the linked list
        PsNODE pTail;//Pointer to the last node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

    public:
        int iCountNode_Main;//Counter for number of nodes in linkedlist for main function which isn't directly used for class functions .
        DOUBLY_CIRCULAR_LINKEDLIST();//Constructor to initialize the singly linear linked list
        ~DOUBLY_CIRCULAR_LINKEDLIST();//Destructor to delete the singly linear linked list


//======Simple Access Functions======//

        //Insertion functions
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPosition(int,int);

        //Deletion functions
        int DeleteFirst();
        int DeleteLast();
        int DeleteAtPosition(int);

        //Traversal functions
        int Count() const;
        void Display() const;

//~=====Simple Access Functions======//



//======Added Features Functions======//

        //Search and Update functions
        bool Search(int) const;
        bool UpdateNoForNo(int,int);
        void UpdateNoForPosition(int,int);

        //Insert and Delete functions
        void InsertBefore(int,int);
        void InsertAfter(int,int);
        int DeleteBefore(int);
        int DeleteAfter(int);
        void DeleteList();

        //Sorting and Reversing functions
        void SortAscending();
        void Reverse();

        //Finding functions
        PsNODE FindMiddleNode() const;
        PsNODE FindKthNodeFromStart(int) const;
        PsNODE FindKthNodeFromMiddle(int,int) const;
        PsNODE FindKthNodeFromEnd(int) const;

//~=====Added Features Functions======//



        //Manual
        void Manual();
};


DOUBLY_CIRCULAR_LINKEDLIST::DOUBLY_CIRCULAR_LINKEDLIST()
{
    pHead = nullptr;
    pTail = nullptr;
    iCountNode = 0;
    iCountNode_Main = 0;
}


DOUBLY_CIRCULAR_LINKEDLIST::~DOUBLY_CIRCULAR_LINKEDLIST()
{
    DeleteList();
}

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Doubly Circular Linked-List                                  //
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
//Display() Function: Displays the entire doubly circular linked list .                           //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::Display() const
{
    PsNODE ptemp = pHead;

    cout<<"Elements from linked list are : "<<endl;

    ///////////////////////Display in serial order//////////////////////

    cout<<"Elements from linked list in serial order are : "<<endl;

    do
    {
        cout<<"<- | "<<ptemp -> iData<<" | -> ";
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);

    cout<<endl<<endl;

    ///////////////////////Display in reverse order//////////////////////

    cout<<"Elements from linked list in reverse order are : "<<endl;

    ptemp = pTail;

    do
    {
        cout<<"<- | "<<ptemp -> iData<<" | -> ";
        ptemp = ptemp -> pPrev;
    }while(ptemp != pTail);

    cout<<endl;
    ptemp = nullptr;//Set the pointer to NULL to avoid dangling pointer
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the doubly circular linked list .                    //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::Count() const
{
    return iCountNode;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the doubly circular linked list .//
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::InsertFirst(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;
    PsNewNode -> pPrev = nullptr;

    if((iCountNode == 0) && (pHead == nullptr) && (pTail == nullptr))//If linkedlist is empty(pHead == NULL)
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = pHead;
        pHead -> pPrev = PsNewNode;
        pHead = PsNewNode;
    }

    pTail -> pNext = pHead;
    pHead -> pPrev = pTail;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the doubly circular linked list .       //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::InsertLast(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;
    PsNewNode -> pPrev = nullptr;

    if((iCountNode == 0) && (pHead == nullptr) && (pTail == nullptr))//If linkedlist is empty((pHead == NULL) && (pTail == NULL))
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        pTail -> pNext = PsNewNode;
        PsNewNode -> pPrev = pTail;
        pTail = PsNewNode;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the singly circular    //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//2. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::InsertAtPosition(int iNo,int iPosition)
{
    if(iPosition == 1)//If position is 1
    {
        InsertFirst(iNo);
        return;
    }
    else if(iPosition == (iCountNode + 1))//If position last
    {
        InsertLast(iNo);
        return;
    }
    else//Random position
    {
        //Initialize a new node
        PsNODE PsNewNode = nullptr;
        PsNewNode = new sNODE;

        //Filling the node with data
        PsNewNode -> iData = iNo;
        PsNewNode -> pNext = nullptr;

        PsNODE ptemp = pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext; // Set the Next pointer of the new node to the Next node
        ptemp -> pNext -> pPrev = PsNewNode; // Update the previous pointer of the Next node to point to the new node
        ptemp -> pNext = PsNewNode; // Set the Next pointer of the current node to the new node
        PsNewNode -> pPrev = ptemp; // Set the previous pointer of the new node to the current node
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the doubly circular linked list .      //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : variable to return the deleted data                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::DeleteFirst()
{
    int iDeleted = 0;

    if((iCountNode == 1) && (pHead == pTail))//If linkedlist contains one node
    {
        iDeleted = pHead -> iData;
        delete pHead;
        pHead = nullptr;;
        pTail = nullptr;
    }
    else//If linkedlist contains atleast one node
    {
        pHead = pHead -> pNext;
        iDeleted = pTail -> pNext -> iData;
        delete pTail -> pNext;
        pHead -> pPrev = pTail;
        pTail -> pNext = pHead;
    }

    iCountNode--;
    iCountNode_Main--;

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the doubly circular linked list .             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : variable to return the deleted data                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::DeleteLast()
{
    int iDeleted = 0;

    if((iCountNode == 1) && (pHead == pTail))//If linkedlist contains one node
    {
        iDeleted = pHead -> iData;
        delete pHead;
        pHead = nullptr;
        pTail = nullptr;
    }
    else//If linkedlist contains atleast two node
    {
        pTail = pTail -> pPrev;

        iDeleted = pHead -> pPrev -> iData;
        delete pHead -> pPrev;

        pHead -> pPrev = pTail;
        pTail -> pNext = pHead;
    }

    iCountNode--;
    iCountNode_Main--;

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the doubly circular  //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::DeleteAtPosition(int iPosition)
{
    int iCnt = 0;

    if(iPosition == 1)//If position is 1
    {
        iCnt = DeleteFirst();
        return iCnt;
    }
    else if(iPosition == iCountNode)//If position last
    {
        iCnt = DeleteLast();
        return iCnt;
    }
    else//Random position
    {
        PsNODE ptemp = pHead;
        PsNODE ptempdelete = nullptr;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;
        delete ptempdelete;
        ptempdelete = nullptr;

        iCountNode--;
        iCountNode_Main--;
        return iCnt;
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
//Search() Function: Searches for a specific value from the doubly circular linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse linkedlist.                                           //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DOUBLY_CIRCULAR_LINKEDLIST::Search(int iSearch) const
{
    PsNODE ptemp = pHead;
    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(ptemp -> iData == iSearch)
        {
            return true;
        }

        ptemp = ptemp -> pNext;
        iPosition++;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value in the doubly       //
// circular linked list .                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//2. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: bool                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse linkedlist.                                           //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool DOUBLY_CIRCULAR_LINKEDLIST::UpdateNoForNo(int iSearch,int iUpdate)
{
    PsNODE ptemp = pHead;
    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(ptemp -> iData == iSearch)
        {
            ptemp -> iData = iUpdate;
            return true;
        }

        ptemp = ptemp -> pNext;
        iPosition++;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForPosition() Function: Updates the value at a specific position in doubly circular     //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//2. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse linkedlist.                                           //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::UpdateNoForPosition(int iUpdate,int iPosition)
{
    PsNODE ptemp = pHead;
    int iCnt = 1;

    while(iCnt <= iCountNode)
    {
        if(iCnt == iPosition)
        {
            pHead -> iData = iUpdate;
            return;
        }

        ptemp = ptemp -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in doubly circular linked list //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//2. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::InsertBefore(int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;
    PsNewNode -> pPrev = nullptr;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = pHead;
        pHead -> pPrev = PsNewNode;
        pHead = PsNewNode;
    }
    else
    {
        PsNODE ptemp = pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;
        PsNewNode -> pNext -> pPrev = PsNewNode;

        ptemp = nullptr;//Freeing the temporary pointer
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in doubly circular linked list . //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//2. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::InsertAfter(int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;
    PsNewNode -> pPrev = nullptr;

    if(iPosition == iCountNode)
    {
        pTail -> pNext = PsNewNode;
        PsNewNode -> pPrev = pTail;
        pTail = PsNewNode;
    }
    else
    {
        PsNODE ptemp = pHead;

        for(int iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext -> pPrev = PsNewNode;
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before specified node from doubly circular linked list  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::DeleteBefore(int iPosition)
{
    PsNODE ptemp = pHead;
    int iCnt = 0;

    if(iPosition == 2)
    {
        pHead = pHead -> pNext;
        iCnt = pHead -> pPrev -> iData;

        iCnt = ptemp -> iData;
        delete pHead -> pPrev;
        ptemp = nullptr;
    }
    else
    {
        PsNODE ptempdelete = nullptr;

        for(iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;
        ptempdelete -> pNext -> pPrev = ptemp;

        iCnt = ptempdelete -> iData;
        delete ptempdelete;
        ptempdelete = nullptr;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode--;
    iCountNode_Main--;

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from doubly circular linked list . //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DOUBLY_CIRCULAR_LINKEDLIST::DeleteAfter(int iPosition)
{
    int iCnt = 0;

    if(iPosition == (iCountNode - 1))
    {
        pTail = pTail -> pPrev;
        iCnt = pTail -> pNext -> iData;

        delete pTail -> pNext;
        pTail -> pNext = nullptr;
    }
    else
    {
        PsNODE ptemp = pHead;
        PsNODE ptempdelete = nullptr;

        for(iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;
        ptempdelete -> pNext -> pPrev = ptemp;

        iCnt = ptempdelete -> iData;
        delete ptempdelete;
        ptempdelete = nullptr;
    }

    pHead -> pPrev = pTail;
    pTail -> pNext = pHead;

    iCountNode--;
    iCountNode_Main--;

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire doubly circular linked list .                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::DeleteList()
{
    while(iCountNode != 0)
    {
        if((pHead != nullptr) && (pHead != pTail))
        {
            pHead = pHead -> pNext;

            delete pHead -> pPrev;
            pHead -> pPrev = nullptr;

            pHead -> pPrev = pTail;
            pTail -> pNext = pHead;

            iCountNode--;
            iCountNode_Main--;
        }

        if((pHead == pTail) && (iCountNode == 1))
        {
            delete pHead;
            pTail = nullptr;
            pHead = nullptr;

            iCountNode--;
            iCountNode_Main--;

            return;
        }

        if((pTail != nullptr) && (pHead != pTail))
        {
            pTail = pTail -> pPrev;
            delete pTail -> pNext;
            pTail -> pNext = nullptr;

            pHead -> pPrev = pTail;
            pTail -> pNext = pHead;

            iCountNode--;
            iCountNode_Main--;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the doubly circular linked list in ascending order .            //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : temporary variable to store the data of the node .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::SortAscending()
{
    PsNODE ptemp1 = pHead;
    PsNODE ptemp2 = pHead;
    int itransfer = 0;

    do
    {
        do
        {
            if(ptemp1 -> iData < ptemp2 -> iData)
            {
                itransfer = ptemp1 -> iData;
                ptemp1 -> iData = ptemp2 -> iData;
                ptemp2 -> iData = itransfer;
            }

            ptemp2 = ptemp2 -> pNext;
        }while(ptemp2 != pTail);

        ptemp1 = ptemp1 -> pNext;
    }while(ptemp1 != pHead);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in doubly circular linked list .                 //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::Reverse()
{
    PsNODE pCurrent = pHead;
    PsNODE ptemp = nullptr;

    do
    {
        ptemp = pCurrent -> pPrev;
        pCurrent -> pPrev = pCurrent -> pNext;
        pCurrent -> pNext = ptemp;
        pCurrent = pCurrent -> pPrev;
    }while(pCurrent != pHead);


    pHead = ptemp -> pPrev;


    pTail = pHead -> pPrev;
    pHead = pTail -> pNext;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the doubly circular linked list .       //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE DOUBLY_CIRCULAR_LINKEDLIST::FindMiddleNode() const
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < ((iCountNode + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: return the kth node from start from doubly circular linkedlist //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : variable as offset from start of list to find .                                        //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE DOUBLY_CIRCULAR_LINKEDLIST::FindKthNodeFromStart(int iKth) const
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from doubly circular linked  //
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : variable as offset from start of list to find .                                        //
//2. int : variable to store direction from middle .                                              //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE DOUBLY_CIRCULAR_LINKEDLIST::FindKthNodeFromMiddle(int iKth,int iDirection) const
{
    PsNODE ptemp = pHead;

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
//FindKthNodeFromEnd() Function: returns the kth node from end from doubly linear linkedlist .    //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : variable as offset from start of list to find .                                        //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE DOUBLY_CIRCULAR_LINKEDLIST::FindKthNodeFromEnd(int iKth) const
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < (iCountNode - iKth + 1);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


//5===============================================================================================//





//6===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of doubly-circular-linked-list .                       //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DOUBLY_CIRCULAR_LINKEDLIST::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's DOUBLY CIRCULAR LINKED LIST APPLICATION::::"<<endl<<endl<<endl;



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
    cout<<"To Count no. of nodes in linked list      : press G"<<endl;

    cout<<"DISPLAY"<<endl;
    cout<<"To View data in linked list               : press H"<<endl<<endl<<endl;


    cout<<"-----Below are functionalities provided for added features of linked list(After entering 3 in ModeSelection stage)-----"<<endl<<endl;

    cout<<"SEARCHING AND MERGING"<<endl;
    cout<<"To Search a Specific Value in linkedlist  : press I"<<endl;
    cout<<"To Reverse the linkedList                 : press J"<<endl;
    cout<<"To Concatenate two linkedlists            : press K"<<endl;
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
    cout<<"To exit the LinkedList App      : press 4"<<endl<<endl;
}


int main()
{
    //Manual();//Display the manual for the application

    DOUBLY_CIRCULAR_LINKEDLIST DoublyCircularLL;

    PsNODE pRet = nullptr;//Pointer to the second node of the linked list

    char siChoiceMode[] = {"\0"};//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

    bool bRet = false;

    cout<<"Welcome to Rajas's Application of Singly-Linear-LinkedList"<<endl<<endl;

    while(1)
    {
        iExitMode = 0;//Resetting the exit mode to 0

        cout<<"===================================================================================================="<<endl;
        cout<<"Enter the mode of operation : ";
        cin>>siChoiceMode;

        if(atoi(siChoiceMode) == 1)
        {
            DoublyCircularLL.Manual();//Display the manual for the application
        }
        else if(atoi(siChoiceMode) == 2)
        {
            cout<<"Active Mode : SIMPLE ACCESS"<<endl;

            iExitMode = 0;//Resetting the exit mode to 0

            while(iExitMode != 1)
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

                        DoublyCircularLL.InsertFirst(iNo1);
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

                        DoublyCircularLL.InsertLast(iNo1);
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
                        while((iPosition1 < 1) || (iPosition1 > (DoublyCircularLL.iCountNode_Main + 1)))
                        {
                            cout<<"Enter the position between 1 <-> "<<(DoublyCircularLL.iCountNode_Main + 1)<<" : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }
                        }

                        DoublyCircularLL.InsertAtPosition(iNo1,iPosition1);
                        cout<<"Node with data "<<iNo1<<" inserted at position "<<iPosition1<<" in the singly linear linked list"<<endl;

                        break;
                    case 'D':
                    case 'd':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            iRet = DoublyCircularLL.DeleteFirst();
                            cout<<"Node with data "<<iRet<<" deleted from the beginning of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'E':
                    case 'e':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            iRet = DoublyCircularLL.DeleteLast();
                            cout<<"Node with data "<<iRet<<" deleted from the end of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'F':
                    case 'f':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the position from which the data is to be deleted : ";
                            cin>>iPosition1;
                            cout<<endl;
                            while((iPosition1 < 1) || (iPosition1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = DoublyCircularLL.DeleteAtPosition(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted from the position "<<iPosition1<<" from the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'G':
                    case 'g':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            DoublyCircularLL.Display();
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = DoublyCircularLL.Count();
                        cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                        break;
                    case 'Y':
                    case 'y':
                        DoublyCircularLL.Manual();//Display the manual for the application

                        break;
                    case 'Z':
                    case 'z':
                        cout<<"Exiting SIMPLE ACCESS mode"<<endl;
                        iExitMode = 1;

                        break;
                    default:
                        cout<<"Invalid choice"<<endl;
                }
            }
        }
        else if(atoi(siChoiceMode) == 3)
        {
            cout<<"Active Mode : ADDED FEATURES"<<endl;

            iExitMode = 0;//Resetting the exit mode to 0

            while(iExitMode != 1)
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
                        DoublyCircularLL.Manual();//Display the manual for the application

                        break;
                    case 'G':
                    case 'g':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            DoublyCircularLL.Display();
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = DoublyCircularLL.Count();
                        cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                        break;
                    case 'I':
                    case 'i':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the value to be searched in the linked list : ";
                            while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            bRet = DoublyCircularLL.Search(iNo1);
                            if(bRet == true)
                            {
                                cout<<"Element "<<iNo1<<" is found at position "<<iPosition1<<" in singly linear linked list"<<endl;
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
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            DoublyCircularLL.Reverse();
                            cout<<"!! Linked-List has been Reversed !!"<<endl;
                        }

                        cout<<"Linked-List is empty"<<endl;

                        break;
                    case 'M':
                    case 'm':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            DoublyCircularLL.SortAscending();
                            cout<<"Singly Linear Linked-List has been sorted in ascending order"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'N':
                    case 'n':
                        if(DoublyCircularLL.iCountNode_Main != 0)
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

                            bRet = DoublyCircularLL.UpdateNoForNo(iNo1,iNo2);
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
                        if(DoublyCircularLL.iCountNode_Main != 0)
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

                            while((iPosition1 < 1) || (iPosition1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1) || (cin.peek() != '\n')))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            DoublyCircularLL.UpdateNoForPosition(iNo1,iPosition1);
                            cout<<"Element at position "<<iPosition1<<" has been updated to "<<iNo1<<" in singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'P':
                    case 'p':
                        if(DoublyCircularLL.iCountNode_Main > 0)
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

                            while((iPosition1 < 1) || (iPosition1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            DoublyCircularLL.InsertBefore(iNo1,iPosition1);
                            cout<<"Node with data "<<iNo1<<" inserted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'Q':
                    case 'q':
                        if(DoublyCircularLL.iCountNode_Main > 0)
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
                            while((iPosition1 < 1) || (iPosition1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            DoublyCircularLL.InsertAfter(iNo1,iPosition1);
                            cout<<"Node with data "<<iNo1<<" inserted at the position "<<(iPosition1 + 1)<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'R':
                    case 'r':
                        if(DoublyCircularLL.iCountNode_Main > 1)
                        {
                            cout<<"Enter the position before which the data is to be deleted : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iPosition1 < 2) || (iPosition1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 2 <-> "<<DoublyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = DoublyCircularLL.DeleteBefore(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'S':
                    case 's':
                        if(DoublyCircularLL.iCountNode_Main > 1)
                        {
                            cout<<"Enter the position before which the data is to be deleted : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iPosition1 < 1) || (iPosition1 > (DoublyCircularLL.iCountNode_Main - 1)))
                            {
                                cout<<"Enter the position between 2 <-> "<<(DoublyCircularLL.iCountNode_Main - 1)<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = DoublyCircularLL.DeleteAfter(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'T':
                    case 't':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            DoublyCircularLL.DeleteList();
                            cout<<"Linked-List has been deleted ."<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'V':
                    case 'v':
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            pRet = DoublyCircularLL.FindMiddleNode();

                            if(pRet != nullptr)
                            {
                                cout<<"The data in middle node from the linked list is : "<<pRet -> iData<<endl;
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
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the kth position from start : ";
                            while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iNo1 < 1) || (iNo1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter offset between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : "<<endl;
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            pRet = DoublyCircularLL.FindKthNodeFromStart(iNo1);
                            cout<<"Data in "<<iNo1<<" node from start is : "<<pRet -> iData<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'Y':
                    case 'y':
                            if(DoublyCircularLL.iCountNode_Main != 0)
                            {
                                cout<<"Enter the kth position from middle : ";
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                                while((iNo1 < 1) || (iNo1 > (DoublyCircularLL.iCountNode_Main/2)))
                                {
                                    cout<<"Enter offset between 1 <-> "<<(DoublyCircularLL.iCountNode_Main/2)<<" : "<<endl;
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


                                pRet = DoublyCircularLL.FindKthNodeFromMiddle(iNo1,iNo2);
                                if(iNo2 == 1)
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to start is : "<<pRet -> iData<<endl;
                                }
                                else
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to end is : "<<pRet -> iData<<endl;
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
                        if(DoublyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the kth position from start : ";
                            while((!(cin>>iNo2)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }
                            while((iNo1 < 1) || (iNo1 > DoublyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter offset between 1 <-> "<<DoublyCircularLL.iCountNode_Main<<" : "<<endl;
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            pRet = DoublyCircularLL.FindKthNodeFromEnd(iNo1);
                            cout<<"Data in "<<iNo1<<" node from end is : "<<pRet -> iData<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'A':
                    case 'a':
                        cout<<"Exiting ADDED FEATURES mode"<<endl;
                        iExitMode = 1;

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

    return 0;//End of program
}

//6===============================================================================================//
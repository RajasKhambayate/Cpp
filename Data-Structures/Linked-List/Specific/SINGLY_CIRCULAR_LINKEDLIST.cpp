//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Singly Circular Linked-List is a type of linked-list where each node points to the //
//Next node in the sequence while keeping the end pointing to the head. This program demonstrates //
//the implementation of Singly Circular Linked List .                                             //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 07th April 2025                                                                           //
//Day: Monday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
#include<limits>
using namespace std;

//2===============================================================================================//






//3================================================================================================//

struct sNode//Structure declaration for node in Singly Circular Linked List
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
};//sNODE, *PsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node


class SINGLY_CIRCULAR_LINKEDLIST
{
    private:
        PsNODE pHead;//Pointer to the first node of the linked list
        PsNODE pTail;//Pointer to the last node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

    public:
        int iCountNode_Main;//Counter for number of nodes in linkedlist for main function which isn't directly used for class functions .
        SINGLY_CIRCULAR_LINKEDLIST();//Constructor to initialize the singly linear linked list
        ~SINGLY_CIRCULAR_LINKEDLIST();//Destructor to delete the singly linear linked list


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
        void DeleteList(); // Helper for destructor

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


SINGLY_CIRCULAR_LINKEDLIST::SINGLY_CIRCULAR_LINKEDLIST()
{
    pHead = nullptr;
    pTail = nullptr;
    iCountNode = 0;
    iCountNode_Main = 0;
}


SINGLY_CIRCULAR_LINKEDLIST::~SINGLY_CIRCULAR_LINKEDLIST()
{
    DeleteList();
}

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Singly Circular Linked-List                                  //
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
//Display() Function: Displays the entire singly circular linked list .                           //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Display() const
{
    PsNODE ptemp = pHead;

    cout<<"Elements from linked list are : "<<endl<<endl;
    cout<<"-> ";

    do
    {
        cout<<"| "<<ptemp -> iData<<" | -> ";
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);

    cout<<endl;

    ptemp = nullptr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the singly circular linked list .                    //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
int SINGLY_CIRCULAR_LINKEDLIST::Count() const
{
    return iCountNode;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the singly circular linked list .//
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertFirst(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;

    if((pHead == nullptr) && (iCountNode == 0))//If linkedlist is empty((pHead == NULL) && (pTail == NULL))
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
        pTail -> pNext = pHead;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
        pTail -> pNext = pHead;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the singly circular linked list .       //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertLast(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;

    if((pHead == nullptr) && (iCountNode == 0))//If linkedlist is empty((pHead == NULL) && (pTail == NULL))
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        pTail -> pNext = PsNewNode;
        PsNewNode -> pNext = pHead;
        pTail = PsNewNode;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the singly circular    //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Data to be inserted in the new node .                                                  //
//2. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : Temporary pointer to traverse the linked list .                                     //
//3. int    : Counter variable .                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertAtPosition(int iNo,int iPosition)
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

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;
        pTail -> pNext = PsNewNode;
    }

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the singly circular linked list .      //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : variable to return the deleted data                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int SINGLY_CIRCULAR_LINKEDLIST::DeleteFirst()
{
    int iDeleted = 0;

    if((iCountNode == 1) && (pHead == pTail))//If linkedlist contains one node
    {
        iDeleted = pHead -> iData;

        delete pHead;
        pHead = nullptr;

        delete pTail;
        pTail = nullptr;
    }
    else//If linkedlist contains atleast one node
    {
        pHead = pHead -> pNext;
        iDeleted = pTail -> pNext -> iData;
        delete pTail -> pNext;
        pTail -> pNext = pHead;
    }

    iCountNode--;
    iCountNode_Main--;

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the singly circular linked list .             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int    : variable to return the deleted data                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
int SINGLY_CIRCULAR_LINKEDLIST::DeleteLast()
{
    int iDeleted = 0;

    if((iCountNode == 1) && (pHead == pTail))//If linkedlist contains one node
    {
        iDeleted = pHead -> iData;

        delete pHead;
        pHead = nullptr;

        delete pTail;
        pTail = nullptr;
    }
    else//If linkedlist contains atleast two node
    {
        PsNODE ptemp = pHead;

        while(ptemp -> pNext != pTail)
        {
            ptemp = ptemp -> pNext;
        }

        iDeleted = ptemp -> pNext -> iData;
        delete ptemp -> pNext;
        pTail = ptemp;
        pTail -> pNext = pHead;
    }

    iCountNode--;
    iCountNode_Main--;

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the singly circular  //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position at which the new node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int    : Counter variable .                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////
int SINGLY_CIRCULAR_LINKEDLIST::DeleteAtPosition(int iPosition)
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
//9. DeleteAfter() : Deletes the node after a specific node                                      //
//10. DeleteList() : Deletes the entire list                                                      //
//11. FindMiddle() : Finds the middle node of the list                                            //
//12. FindKthNodeFromStart() : Finds the kth node from the start of the list                      //
//13. FindKthNodeFromMiddle() : Finds the kth node from the middle of the list                    //
//14. FindKthNodeFromEnd() : Finds the kth node from the end of the list                          //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Search() Function: Searches for a specific value from the singly circular linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Temporary pointer to traverse linkedlist .                                          //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool SINGLY_CIRCULAR_LINKEDLIST::Search(int iSearch) const
{
    PsNODE ptemp = pHead;
    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(ptemp -> iData == iSearch)
        {
            cout<<"Element "<<iSearch<<" is found at position "<<iPosition<<" in singly circular linked list"<<endl;
            return true;
        }

        ptemp = ptemp -> pNext;
        iPosition++;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value in the singly       //
// circular linked list .                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//2. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Temporary pointer to traverse linkedlist .                                          //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool SINGLY_CIRCULAR_LINKEDLIST::UpdateNoForNo(int iSearch,int iUpdate)
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
//UpdateNoForPosition() Function: Updates the value at a specific position in singly circular     //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Value to be searched in the linked list .                                              //
//2. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Temporary pointer to traverse linkedlist .                                          //
//2. int : Counter variable & Position variable in one .                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::UpdateNoForPosition(int iUpdate,int iPosition)
{
    PsNODE ptemp = pHead;
    int iCnt = 1;

    while(iCnt <= iCountNode)
    {
        if(iCnt == iPosition)
        {
            ptemp -> iData = iUpdate;
            return;
        }

        ptemp = ptemp -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in singly circular linked list //
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
void SINGLY_CIRCULAR_LINKEDLIST::InsertBefore(int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = pHead;
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
        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;//Freeing the temporary pointer
    }

    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in singly circular linked list . //
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
void SINGLY_CIRCULAR_LINKEDLIST::InsertAfter(int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = nullptr;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = nullptr;

    if(iPosition == iCountNode)
    {
        PsNewNode -> pNext = pHead;
        pTail -> pNext = PsNewNode;
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
        ptemp -> pNext = PsNewNode;

        ptemp = nullptr;
    }

    pTail -> pNext = pHead;

    iCountNode++;
    iCountNode_Main++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before specified node from singly circular linked list  //
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
int SINGLY_CIRCULAR_LINKEDLIST::DeleteBefore(int iPosition)
{
    if(iPosition == 2)
    {
        pHead = pHead -> pNext;
        iCnt = pTail -> pNext -> iData;
        delete pTail -> pNext;
        pTail -> pNext = pHead;
    }
    else
    {
        PsNODE ptempdelete = nullptr;
        PsNODE ptemp = pHead;

        for(int iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;
        delete ptempdelete;
        ptempdelete = nullptr;
    }

    iCountNode--;
    iCountNode_Main--;

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from singly circular linked list . //
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
int SINGLY_CIRCULAR_LINKEDLIST::DeleteAfter(int iPosition)
{
    PsNODE ptemp = pHead;

    if(iPosition == (iCountNode - 1))
    {
        while(ptemp -> pNext != pTail)
        {
            ptemp = ptemp -> pNext;
        }

        iCnt = ptemp -> pNext -> iData;
        delete ptemp -> pNext;
        ptemp -> pNext = nullptr;
        pTail = ptemp;
    }
    else
    {
        PsNODE ptempdelete = nullptr;

        for(int iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;
        delete ptempdelete;
        ptempdelete = nullptr;
    }

    pTail -> pNext = pHead;

    iCountNode--;
    iCountNode_Main--;

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire singly circular linked list .                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to delete the node .                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteList()
{
    PsNODE ptempdelete = pHead;

    while(pHead != nullptr)
    {
        ptempdelete = pHead;
        pHead = pHead -> pNext;

        delete ptempdelete;
        ptempdelete = nullptr;

        iCountNode--;
        iCountNode_Main--;
    }

    pTail = nullptr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the singly circular linked list in ascending order .            //
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
void SINGLY_CIRCULAR_LINKEDLIST::SortAscending()
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
//Reverse() Function: Reverses the order of data in singly circular linked list .                 //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Reverse()
{
    PsNODE pCurrent = pHead;
    PsNODE ptempprev = pTail;
    PsNODE ptempNext = nullptr;

    do
    {
        ptempNext = pCurrent -> pNext;
        pCurrent -> pNext = ptempprev;
        ptempprev = pCurrent;
        pCurrent = ptempNext;
    }while(pCurrent != pHead);

    pCurrent = pHead;
    pHead = pTail;
    pTail = pCurrent;

    pTail -> pNext = pHead;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the singly circular linked list .       //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindMiddleNode() const
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < ((iCountNode + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: return the kth node from start from singly circular linkedlist //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : integer to store kth position from start .                                             //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromStart(int iKth) const
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from singly circular linked  //
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : integer to store kth position from start .                                             //
//2. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromMiddle(int iKth,int iDirection) const
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
//FindKthNodeFromEnd() Function: returns the kth node from end from singly linear linkedlist .    //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : integer to store kth position from start .                                             //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromEnd(int iKth) const
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
//Manual() Function: A guide for the usage of singly-circular-linked-list .                       //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm: None                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's SINGLY CIRCULAR LINKED LIST APPLICATION::::"<<endl<<endl<<endl;



    cout<<"-----Below are functionalities provided for simple access of linked list(After entering 2 in ModeSelection stage)-----"<<endl<<endl<<endl;

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
    cout<<"To View data in linked list               : press H"<<endl<<endl;


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
    cout<<"To exit the LinkedList App      : press 4"<<endl<<endl;
}


int main()
{
    //Manual();//Display the manual for the application

    SINGLY_CIRCULAR_LINKEDLIST SinglyCircularLL;

    PsNODE pRet = nullptr;//Pointer to the second node of the linked list

    char siChoiceMode[] = {"\0"};//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

    bool bRet = false;

    cout<<"Welcome to Rajas's Application of Singly-Circular-LinkedList"<<endl<<endl;

    while(1)
    {
        iExitMode = 0;//Resetting the exit mode to 0

        cout<<"===================================================================================================="<<endl;
        cout<<"Enter the mode of operation : ";
        cin>>siChoiceMode;

        if(atoi(siChoiceMode) == 1)
        {
            SinglyCircularLL.Manual();//Display the manual for the application
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

                        SinglyCircularLL.InsertFirst(iNo1);
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

                        SinglyCircularLL.InsertLast(iNo1);
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
                        while((iPosition1 < 1) || (iPosition1 > (SinglyCircularLL.iCountNode_Main + 1)))
                        {
                            cout<<"Enter the position between 1 <-> "<<(SinglyCircularLL.iCountNode_Main + 1)<<" : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }
                        }

                        SinglyCircularLL.InsertAtPosition(iNo1,iPosition1);
                        cout<<"Node with data "<<iNo1<<" inserted at position "<<iPosition1<<" in the singly linear linked list"<<endl;

                        break;
                    case 'D':
                    case 'd':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            iRet = SinglyCircularLL.DeleteFirst();
                            cout<<"Node with data "<<iRet<<" deleted from the beginning of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'E':
                    case 'e':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            iRet = SinglyCircularLL.DeleteLast();
                            cout<<"Node with data "<<iRet<<" deleted from the end of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'F':
                    case 'f':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the position from which the data is to be deleted : ";
                            cin>>iPosition1;
                            cout<<endl;
                            while((iPosition1 < 1) || (iPosition1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = SinglyCircularLL.DeleteAtPosition(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted from the position "<<iPosition1<<" from the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'G':
                    case 'g':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            SinglyCircularLL.Display();
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = SinglyCircularLL.Count();
                        cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                        break;
                    case 'Y':
                    case 'y':
                        SinglyCircularLL.Manual();//Display the manual for the application

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
                        SinglyCircularLL.Manual();//Display the manual for the application

                        break;
                    case 'G':
                    case 'g':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            SinglyCircularLL.Display();
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = SinglyCircularLL.Count();
                        cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                        break;
                    case 'I':
                    case 'i':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the value to be searched in the linked list : ";
                            while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            bRet = SinglyCircularLL.Search(iNo1);
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
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            SinglyCircularLL.Reverse();
                            cout<<"!! Linked-List has been Reversed !!"<<endl;
                        }

                        cout<<"Linked-List is empty"<<endl;

                        break;
                    case 'M':
                    case 'm':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            SinglyCircularLL.SortAscending();
                            cout<<"Singly Linear Linked-List has been sorted in ascending order"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'N':
                    case 'n':
                        if(SinglyCircularLL.iCountNode_Main != 0)
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

                            bRet = SinglyCircularLL.UpdateNoForNo(iNo1,iNo2);
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
                        if(SinglyCircularLL.iCountNode_Main != 0)
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

                            while((iPosition1 < 1) || (iPosition1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1) || (cin.peek() != '\n')))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            SinglyCircularLL.UpdateNoForPosition(iNo1,iPosition1);
                            cout<<"Element at position "<<iPosition1<<" has been updated to "<<iNo1<<" in singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'P':
                    case 'p':
                        if(SinglyCircularLL.iCountNode_Main > 0)
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

                            while((iPosition1 < 1) || (iPosition1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            SinglyCircularLL.InsertBefore(iNo1,iPosition1);
                            cout<<"Node with data "<<iNo1<<" inserted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'Q':
                    case 'q':
                        if(SinglyCircularLL.iCountNode_Main > 0)
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
                            while((iPosition1 < 1) || (iPosition1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            SinglyCircularLL.InsertAfter(iNo1,iPosition1);
                            cout<<"Node with data "<<iNo1<<" inserted at the position "<<(iPosition1 + 1)<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'R':
                    case 'r':
                        if(SinglyCircularLL.iCountNode_Main > 1)
                        {
                            cout<<"Enter the position before which the data is to be deleted : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iPosition1 < 2) || (iPosition1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter the position between 2 <-> "<<SinglyCircularLL.iCountNode_Main<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = SinglyCircularLL.DeleteBefore(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'S':
                    case 's':
                        if(SinglyCircularLL.iCountNode_Main > 1)
                        {
                            cout<<"Enter the position before which the data is to be deleted : ";
                            while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iPosition1 < 1) || (iPosition1 > (SinglyCircularLL.iCountNode_Main - 1)))
                            {
                                cout<<"Enter the position between 2 <-> "<<(SinglyCircularLL.iCountNode_Main - 1)<<" : ";
                                while((!(cin>>iPosition1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            iRet = SinglyCircularLL.DeleteAfter(iPosition1);
                            cout<<"Node with data "<<iRet<<" deleted at the position "<<iPosition1<<" of the singly linear linked list"<<endl;
                        }
                        else
                        {
                            cout<<"!!Not Enough Nodes!!"<<endl;
                        }

                        break;
                    case 'T':
                    case 't':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            SinglyCircularLL.DeleteList();
                            cout<<"Linked-List has been deleted ."<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'V':
                    case 'v':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            pRet = SinglyCircularLL.FindMiddleNode();

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
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the kth position from start : ";
                            while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iNo1 < 1) || (iNo1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter offset between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : "<<endl;
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            pRet = SinglyCircularLL.FindKthNodeFromStart(iNo1);
                            cout<<"Data in "<<iNo1<<" node from start is : "<<pRet -> iData<<endl;
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'Y':
                    case 'y':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the kth position from start : ";
                            while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }

                            while((iNo1 < 1) || (iNo1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter offset between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : "<<endl;
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

                            if((iNo1 == 1) || (iNo2 == 0))
                            {
                                pRet = SinglyCircularLL.FindKthNodeFromMiddle(iNo1,iNo2);
                                if(iNo2 == 1)
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to start is : "<<pRet -> iData<<endl;
                                }
                                else
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to end is : "<<pRet -> iData<<endl;
                                }
                            }
                            else
                            {
                                while((iNo2 != 1) || (iNo2 != 0))
                                {
                                    cout<<"Kth node from start or end ? >>Press 1 : FOR start [OR] >>Press 2 : FOR end ::: Your choice : ";
                                    while((!(cin>>iNo2)) || (cin.peek() != '\n'))
                                    {
                                        cout<<"Invalid input. Please enter a single integer : ";
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                    }
                                }

                                pRet = SinglyCircularLL.FindKthNodeFromMiddle(iNo1,iNo2);
                                if(iNo2 == 1)
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to start is : "<<pRet -> iData<<endl;
                                }
                                else
                                {
                                    cout<<"Data in "<<iNo1<<" node from middle to end is : "<<pRet -> iData<<endl;
                                }
                            }
                        }
                        else
                        {
                            cout<<"!!Linked-List is empty!!"<<endl;
                        }

                        break;
                    case 'Z':
                    case 'z':
                        if(SinglyCircularLL.iCountNode_Main != 0)
                        {
                            cout<<"Enter the kth position from start : ";
                            while((!(cin>>iNo2)) || (cin.peek() != '\n'))
                            {
                                cout<<"Invalid input. Please enter a single integer : ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            }
                            while((iNo1 < 1) || (iNo1 > SinglyCircularLL.iCountNode_Main))
                            {
                                cout<<"Enter offset between 1 <-> "<<SinglyCircularLL.iCountNode_Main<<" : "<<endl;
                                while((!(cin>>iNo1)) || (cin.peek() != '\n'))
                                {
                                    cout<<"Invalid input. Please enter a single integer : ";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                }
                            }

                            pRet = SinglyCircularLL.FindKthNodeFromEnd(iNo1);
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
            cout<<"Exiting the RAJAS's SINGLY CIRCULAR LINKEDLIST application"<<endl;
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
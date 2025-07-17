//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Singly Circular Linked-List is a type of linked-list where each node points to the //
//Next node in the sequence while keeping the end pointing to the head. This program demonstrates //
//the implementation of Singly Circular Linked List .                                             //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU GCC/G++                                                                          //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 07th April 2025                                                                           //
//Day: Monday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
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

        PsNODE pHead1;
        PsNODE pTail1;

        PsNODE pHead2;
        PsNODE pTail2;

    public:
        SINGLY_CIRCULAR_LINKEDLIST();//Constructor to initialize the singly linear linked list
        ~SINGLY_CIRCULAR_LINKEDLIST();//Destructor to delete the singly linear linked list


//======Simple Access Functions======//

        //Insertion functions
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPosition(int, int);

        //Deletion functions
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);

        //Traversal functions
        int Count();
        void Display();

//~=====Simple Access Functions======//



//======Added Features Functions======//

        //Search and Update functions
        bool Search(int);
        void UpdateNoForNo(int,int);
        void UpdateNoForPosition(int,int);
        void Concat();

        //Insert and Delete functions
        void InsertBefore(int, int);
        void InsertAfter(int, int);
        void DeleteBefore(int);
        void DeleteAfter(int);
        void DeleteList();

        //Sorting and Reversing functions
        void SortAscending();
        void Reverse();

        //Finding functions
        PsNODE FindMiddleNode();
        PsNODE FindKthNodeFromStart();
        PsNODE FindKthNodeFromMiddle();
        PsNODE FindKthNodeFromEnd();

//~=====Added Features Functions======//



        //Manual
        void Manual();
};


SINGLY_CIRCULAR_LINKEDLIST::SINGLY_CIRCULAR_LINKEDLIST()
{
    pHead = NULL;
    iCountNode = 0;
}


SINGLY_CIRCULAR_LINKEDLIST::~SINGLY_CIRCULAR_LINKEDLIST()
{
    delete pHead;
    iCountNode = 0;
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and display the data of each node.               //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Display()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        printf("Linkedlist is empty\n");
        printf("NULL\n");
        return;
    }

    cout<<"Elements from linked list are : "<<endl<<endl;
    PsNODE ptemp = pHead;

    cout<<"-> ";

    do
    {
        cout<<"| "<<ptemp -> iData<<" | -> ";
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);

    cout<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the singly circular linked list .                    //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Return the value of iCountNode which is updated during insertion and deletion operations.    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int SINGLY_CIRCULAR_LINKEDLIST::Count()
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, update the Next pointer of the new node with  //
//   the address of the first node and update the first pointer with the address of the new node. //
//5. Update the Next pointer of the new node to point to the head node .                          //
//6. Increment the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertFirst(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iCountNode == 0)//If linkedlist is empty(pHead == NULL)
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
    }

    pTail -> pNext = pHead;

    iCountNode++;

    cout<<"Node with data "<<iNo<<" inserted at the beginning of the singly circular linked list"<<endl;
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, traverse till the last node and update the    //
//   Next pointer of the last node with the address of the new node.                              //
//5. Update the Next pointer of the new node to point to the head node .                          //
//6. Increment the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertLast(int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iCountNode == 1)//If linkedlist is empty((pHead == NULL) && (pTail == NULL))
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

    pTail -> pNext = pHead;

    iCountNode++;

    cout<<"Node with data "<<iNo<<" inserted at the end of the singly circular linked list"<<endl;
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is 1,call the InsertFirst() function to insert the new node at the beginning.//
//5. If the position is the last,call the InsertLast() function to insert the new node at the end.//
//6. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the Next       //
//   pointer of the previous node with the address of the new node.                               //
//7. Update the Next pointer of the new node to point to the head node .                          //
//8. Increment the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertAtPosition(int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iCountNode + 1)))//If position is invalid
    {
        while(iCnt <= 2)
        {
            cout<<"Invalid position"<<endl;

            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= (iCountNode + 1)))
            {
                InsertAtPosition(iNo,iPosition);
                return;
            }

            iCnt++;
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }
    else if(iCountNode == 0)//If linkedlist is empty
    {
        pHead = PsNewNode;
        pTail = PsNewNode;
    }
    else if(iPosition == 1)//If position is 1
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
    }
    else if(iPosition == (iCountNode + 1))//If position last
    {
        PsNewNode -> pNext = pHead;
        pTail -> pNext = PsNewNode;
        pTail = PsNewNode;
    }
    else//Random position
    {
        PsNODE ptemp = pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;
    }

    pTail -> pNext = pHead;

    iCountNode++;

    cout<<"Node with data "<<iNo<<" inserted at position "<<iPosition<<" in the singly circular linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the singly circular linked list .      //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                               //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list contains one node, delete the node and return .                           //
//3. If the linked list contains more than one node, store the address of the first node in a     //
//   temporary pointer, update the first pointer with the address of the next node and free the   //
//   memory of the temporary pointer.                                                             //
//4. Update the Next pointer of the new node to point to the head node .                          //
//5. Decrement the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteFirst()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))//If linkedlist is empty
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else if((iCountNode == 1) && (pHead == pTail))//If linkedlist contains one node
    {
        pTail = NULL;

        cout<<"Node with data "<<(pHead) -> iData<<" deleted from the beginning of the singly circular linked list"<<endl;

        free(pHead);
        pHead = NULL;
    }
    else//If linkedlist contains atleast one node
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pTail -> pNext -> iData<<" deleted from the beginning of the singly circular linked list"<<endl;
        free(pTail -> pNext);
    }

    pTail -> pNext = pHead;

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the singly circular linked list .             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list contains one node, delete the node and return .                           //
//3. If the linked list contains more than one node, traverse till the second last node and       //
//   delete the last node.                                                                        //
//4. Update the Next pointer of the new node to point to the head node .                          //
//5. Decrement the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteLast()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))//If linkedlist is empty
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else if((iCountNode == 1) && ((pHead) -> pNext == NULL))//If linkedlist contains one node
    {
        cout<<"Node with data "<<(pHead) -> iData<<" deleted from the end of the singly circular linked list"<<endl;

        pTail = NULL;
        free(pHead);
        pHead = NULL;
    }
    else//If linkedlist contains atleast two node
    {
        PsNODE ptemp = pHead;

        while(ptemp -> pNext != pTail)
        {
            ptemp = ptemp -> pNext;
        }

        cout<<"Node with data "<<ptemp -> pNext -> iData<<" deleted from the end of the singly circular linked list"<<endl;

        free(ptemp -> pNext);
        pTail = ptemp;
        pTail -> pNext = pHead;
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the singly circular  //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable .                                                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. PsNODE : temporary pointer to delete the node .                                              //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the position is invalid, display a message that the position is invalid.                  //
//3. If the position is 1,call the DeleteFirst() function to delete the first node.               //
//4. If the position is the last,call the DeleteLast() function to delete the last node.          //
//5. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted        //
//   and free the memory of the node to be deleted.                                               //
//6. Decrement the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteAtPosition(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))//If linkedlist is empty
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > iCountNode))//If position is invalid
    {
        while(iCnt <= 2)
        {
            cout<<"Invalid position"<<endl;

            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= iCountNode))
            {
                DeleteAtPosition(iPosition);
                return;
            }

            iCnt++;
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }

    if((iCountNode == 1) && (pHead == pTail))
    {
        cout<<"Node with data "<<(pHead) -> iData<<" deleted from the singly linear linked list"<<endl;

        pTail = NULL;
        free(pHead);
        pHead = NULL;
    }
    else if(iPosition == 1)//If position is 1
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pTail -> pNext -> iData<<" deleted from the beginning of the singly linear linked list"<<endl;

        free(pTail -> pNext);
        pTail -> pNext = pHead;
    }
    else if(iPosition == iCountNode)//If position last
    {
        PsNODE ptempdelete = pHead;

        while(ptempdelete -> pNext != pTail)
        {
            ptempdelete = ptempdelete -> pNext;
        }

        cout<<"Node with data "<<ptempdelete -> pNext -> iData<<" deleted from the end of the singly linear linked list"<<endl;

        free(ptempdelete -> pNext);
        pTail = ptempdelete;
        pTail -> pNext = pHead;
    }
    else//Random position
    {
        PsNODE ptemp = pHead;
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        cout<<"Node with data "<<ptempdelete -> iData<<" deleted from "<<iPosition<<" position from singly linear linked list"<<endl;

        free(ptempdelete);
    }

    iCountNode--;
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Other Functions:                                                                                //
//================================================================================================//
//1. Search() : Searches for a specific value in the list                                         //
//2. Reverse() : Reverses the order of the list                                                   //
//3. Concat() : Concatenates two lists                                                            //
//4. Sort() : Sorts the list in ascending order                                                   //
//5. UpdateNoforNo() : Updates the value of a specific node in exchange to some value             //
//6. UpdateNoForPosition() : Updates the value of a specific node at specific position            //
//7. InsertBefore() : Inserts a new node before a specific node                                   //
//8. InsertAfter() : Inserts a new node after a specific node                                     //
//9. DeleteBefore() : Deletes the node before a specific node                                     //
//10. DeleteAfter() : Deletes the node after a specific node                                      //
//11. DeleteList() : Deletes the entire list                                                      //
//12. FindMiddle() : Finds the middle node of the list                                            //
//13. FindKthNodeFromStart() : Finds the kth node from the start of the list                      //
//14. FindKthNodeFromMiddle() : Finds the kth node from the middle of the list                    //
//15. FindKthNodeFromEnd() : Finds the kth node from the end of the list                          //
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
//1. int : Counter variable & Position variable in one .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. Count the number of nodes in the linked list .                                               //
//3. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, display a message that the value is found and return.//
//4. If the value is not found, return false.                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool SINGLY_CIRCULAR_LINKEDLIST::Search(int iSearch)
{
    if((iCountNode == 0)  && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        return false;
    }

    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(pHead -> iData == iSearch)
        {
            cout<<"Element "<<iSearch<<" is found at position "<<iPosition<<" in singly circular linked list"<<endl;
            return true;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    cout<<"Element "<<iSearch<<" not found in singly circular linked list"<<endl;
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
//1. int : Counter variable & Position variable in one .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, update the data of the node with the specified value.//
//2. If the value is not found, display a message that the value is not found.                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::UpdateNoForNo(int iSearch,int iUpdate)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }

    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(pHead -> iData == iSearch)
        {
            pHead -> iData = iUpdate;
            cout<<"Element "<<iSearch<<" has been updated to "<<iUpdate<<" in singly circular linked list"<<endl;

            return;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    cout<<"Element "<<iSearch<<" not found in singly circular linked list"<<endl;
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
//1. int : Counter variable & Position variable in one .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, update the data of the node with the specified value.//
//2. If the value is not found, display a message that the value is not found.                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::UpdateNoForPosition(int iUpdate,int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iCountNode + 1)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            cout<<"Invalid position"<<endl;
            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= (iCountNode + 1)))
            {
                UpdateNoForPosition(iUpdate,iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }

    iCnt = 1;

    while(iCnt <= iCountNode)
    {
        if(iCnt == iPosition)
        {
            pHead -> iData = iUpdate;
            cout<<"Element at position "<<iPosition<<" has been updated to "<<iUpdate<<" in singly circular linked list"<<endl;

            return;
        }

        pHead = pHead -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Concat() Function: Concats two singly circular linked list .                                    //
//================================================================================================//
//Parameters:                                                                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If both linked lists are empty, display a message that both linked lists are empty.          //
//2. If the first linked list is empty, display a message that the first linked list is empty.    //
//3. If the second linked list is empty, display a message that the second linked list is empty.  //
//4. Traverse the first linked list till the last node and update thepNext pointer of the last    //
//   node with the address of the first node of the second linked list and free the second linked //
//   list.                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Concat()
{
    if((pHead1 == NULL) && (pHead2 == NULL) && (pTail1 == 0) && (pTail2 == NULL))
    {
        cout<<"Both linkedlist are empty"<<endl;
        return;
    }
    else if((pHead1 == NULL) && (pTail1))
    {
        cout<<"First linkedlist is empty"<<endl;
        return;
    }
    else if((pHead2 == NULL) && (pTail2 == NULL))
    {
        cout<<"Second linkedlist is empty"<<endl;
        return;
    }

    pTail1 -> pNext = pHead2;
    pTail2 -> pNext = pHead1;

    pTail1 = pTail2;

    pHead2 = NULL; //Freeing the second linked list
    pTail2 = NULL; //Freeing the second linked list
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
//2. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is 1, update the Next pointer of the new node with the address of the first  //
//   node and update the first pointer with the address of the new node.                          //
//5. If the position is last,update the Next pointer of the last node with the address of the new //
//   node and update the last pointer with the address of the new node.                           //
//6. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the            //
//   Next pointer of the previous node with the address of the new node.                          //
//7. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertBefore(int iNo,int iPosition)
{
    if((iCountNode == 0)  && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist are empty\n"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iCountNode)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            cout<<"Invalid position"<<endl;
            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= (iCountNode)))
            {
                InsertBefore(iNo,iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }


    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = pHead;
        pHead = PsNewNode;
    }
    else
    {
        PsNODE ptemp = pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;//Freeing the temporary pointer
    }

    pTail -> pNext = pHead;

    iCountNode++;
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
//2. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the position is invalid, display a message that the position is invalid.                  //
//3. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the Next       //
//   pointer of the previous node with the address of the new node.                               //
//4. If the position is the last, traverse till the last node and update the Next pointer of      //
//   the last node with the address of the new node.we can call the InsertFirst() Function or use //
//   its logic .                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::InsertAfter(int iNo,int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist are empty"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iCountNode)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            cout<<"Invalid position"<<endl;
            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= (iCountNode)))
            {
                InsertAfter(iNo,iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }


    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = new sNODE;

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iPosition == iCountNode)
    {
        PsNewNode -> pNext = pHead;
        pTail -> pNext = PsNewNode;
        pTail = PsNewNode;
    }
    else
    {
        PsNODE ptemp = pHead;

        for(iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;
    }

    pTail -> pNext = pHead;

    iCountNode++;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before specified node from singly circular linked list  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the position is invalid, display a message that the position is invalid.                  //
//3. If the position is 2, store the address of the first node in a temporary pointer and update  //
//   the first pointer with the Next pointer of the first node and free the memory of the         //
//   temporary pointer.                                                                           //
//4. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted and    //
//   free the memory of the node to be deleted.                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteBefore(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == 0))
    {
        cout<<"linkedlist are empty"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 2) || (iPosition > (iCountNode)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            cout<<"Invalid position"<<endl;
            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 2) && (iPosition <= (iCountNode)))
            {
                DeleteBefore(iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }

    if(iPosition == 2)
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pTail -> pNext -> iData<<" deleted from the beginning of the singly circular linked list"<<endl;

        free(pTail -> pNext);
        pTail -> pNext = pHead;
    }
    else
    {
        PsNODE ptempdelete = NULL;
        PsNODE ptemp = pHead;

        for(iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        cout<<"Node with data "<<ptempdelete -> iData<<" deleted from the singly circular linked list"<<endl;

        free(ptempdelete);
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from singly circular linked list . //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the position is invalid, display a message that the position is invalid.                  //
//3. If the position is the last, traverse till the second last node and delete the last node.    //
//4. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted and    //
//   free the memory of the node to be deleted.                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteAfter(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist are empty"<<endl;
        return;
    }

    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iCountNode - 1)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            cout<<"Invalid position"<<endl;
            cout<<"Enter valid position : "<<endl;
            cin>>iPosition;

            if((iPosition >= 1) && (iPosition <= (iCountNode - 1)))
            {
                DeleteAfter(iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }

    PsNODE ptemp = pHead;

    if(iPosition == (iCountNode - 1))
    {
        while(ptemp -> pNext != pTail)
        {
            ptemp = ptemp -> pNext;
        }

        cout<<"Node with data "<<ptemp -> pNext -> iData<<" deleted from the singly circular linked list"<<endl;

        free(ptemp -> pNext);
        ptemp -> pNext = NULL;
        pTail = ptemp;
    }
    else
    {
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        cout<<"Node with data "<<ptempdelete -> iData<<" deleted from the singly circular linked list"<<endl;

        free(ptempdelete);
    }

    pTail -> pNext = pHead;

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire singly circular linked list .                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and free the memory of each node.  //
//   Update the first pointer to NULL after freeing the memory of each node.                      //
//3. Finally, free the memory of the first pointer.                                               //
//4. Display a message that the linked list has been deleted.                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::DeleteList()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is already empty"<<endl;
        return;
    }

    do
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pTail -> pNext -> iData<<" deleted from the singly circular linked list"<<endl;

        free(pTail -> pNext);
        pTail -> pNext = pHead;

        iCountNode--;

    }while(pHead != pTail);

    if(pHead == pTail)
    {
        cout<<"Node with data "<<pTail -> iData<<" deleted from the singly circular linked list"<<endl;

        free(pTail);
        pTail = NULL;
    }

    free(pHead);
    pHead = NULL;

    free(pTail);
    pTail = NULL;

    cout<<"Singly Circular Linked-List has been deleted"<<endl;
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and compare the data of each node  //
//   with the data of the next node. If the data of the first node is greater than the data of    //
//   the next node, swap the data of the two nodes. Repeat this process till the last node.       //
//3. Finally, display a message that the linked list has been sorted in ascending order.          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::SortAscending()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return;
    }

    int itransfer = 0;
    PsNODE ptemp1 = pHead;
    PsNODE ptemp2 = pHead;

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

    cout<<"Singly Circular Linked-List has been sorted as in ascending order"<<endl;
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and compare the data of each node  //
//   with the data of the next node. If the data of the first node is greater than the data of    //
//   the next node, swap the data of the two nodes. Repeat this process till the last node.       //
//3. Finally, display a message that the linked list has been sorted in ascending order.          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SINGLY_CIRCULAR_LINKEDLIST::Reverse()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return;
    }

    PsNODE pCurrent = pHead;
    PsNODE ptempprev = pTail;
    PsNODE ptempNext = NULL;

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

    cout<<"Singly Circular Linked-List's data has been reversed"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the singly linear linked list .         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. Traverse the linked list till the middle node and return the address of the middle node.     //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindMiddleNode()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    PsNODE ptemp = pHead;

    int iCnt = 0;

    for(iCnt = 1;iCnt < ((iCountNode + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: return the kth node from start from singly circular linkedlist //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store kth position from start .                                             //
//3. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the kth position is invalid, display a message that the kth position is invalid.          //
//3. Travel the linked list till the kth node from start and return the address of the kth node.  //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromStart()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    cout<<"Enter the kth position from start : ";
    cin>>iKth;
    cout<<endl;
    int iCnt = 0;

    if((iKth < 1) || (iKth > iCountNode))
    {
        cout<<"Invalid position"<<endl;

        cout<<"Wrong input, call function again ."<<endl;

        return NULL;
    }


    for(iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        cout<<"Invalid position"<<endl;
        return NULL;
    }
    else
    {
        cout<<"Data in "<<iKth<<" node from start is : "<<ptemp -> iData<<endl;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from singly circular linked  //
// list .                                                                                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store kth position from start .                                             //
//3. int : integer to store counter variable .                                                    //
//4. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the kth position is invalid, display a message that the kth position is invalid.          //
//3. If the kth position is random, traverse the linked list till the kth node from middle and    //
//   return the address of the kth node.                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromMiddle()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    cout<<"Enter the kth position from middle : ";
    cin>>iKth;
    cout<<endl;
    int iDirection = 0;
    cout<<"Kth node from start or end ? >>Press 1 : FOR start [OR] >>Press 2 : FOR end ::: Your choice : ";
    cin>>iDirection;
    cout<<endl;
    int iCnt = 0;


    if((iKth < 1) || (iKth >= ((iCountNode + 1)/2)))
    {
        printf("Invalid position\n");

        printf("Wrong input, call function again .\n");

        return NULL;
    }

    if(iDirection == 1)
    {
        iKth = ((iCountNode + 1)/2) - iKth;
    }
    else
    {
        iKth = ((iCountNode + 1)/2) + iKth;
    }

    for(iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        cout<<"Invalid position"<<endl;
        return NULL;
    }
    else
    {
        if(iDirection == 1)
        {
            cout<<"Data in "<<iKth<<" node from middle to start is : "<<ptemp -> iData<<endl;
        }
        else
        {
            cout<<"Data in "<<iKth<<" node from middle to end is : "<<ptemp -> iData<<endl;
        }
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end from singly linear linkedlist .    //
//================================================================================================//
//Parameters: None                                                                                    //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store kth position from start .                                             //
//3. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the kth position is invalid, display a message that the kth position is invalid.          //
//3. If the kth position is random, traverse the linked list till the kth node from end and       //
//   return the address of the kth node.                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE SINGLY_CIRCULAR_LINKEDLIST::FindKthNodeFromEnd()
{
    if((iCountNode == 0) && (pHead == NULL) && (pTail == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    cout<<"Enter the kth position from end : ";
    cin>>iKth;
    cout<<endl;
    int iCnt = 0;

    if((iKth < 1) || (iKth > iCountNode))
    {
        cout<<"Invalid position"<<endl;

        cout<<"Wrong input, call function again ."<<endl;

        return NULL;
    }

    int iIndex = iCountNode - iKth + 1;

    for(iCnt = 1;iCnt < iIndex;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        cout<<"Invalid position"<<endl;
        return NULL;
    }
    else
    {
        cout<<"Data in "<<iKth<<" node from end is : "<<ptemp -> iData<<endl;
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
    printf("::::MANUAL FOR RAJAS's SINGLY CIRCULAR LINKED LIST APPLICATION::::\n\n\n");



    printf("-----Below are functionalities provided for simple access of linked list(After entering 2 in ModeSelection stage)-----\n\n");

    printf("INSERTION\n");
    printf("For Inserting data at FIRST      position : press A\n");
    printf("For Inserting data at LAST       position : press B\n");
    printf("For Inserting data at SPECIFIC   position : press C\n\n");

    printf("DELETION\n");
    printf("For Deleting  data at  First     position : press D\n");
    printf("For Deleting  data at  LAST      position : press E\n");
    printf("For Deleting  data at  SPECIFIC  position : press F\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in linked list      : press G\n");

    printf("DISPLAY\n");
    printf("To View data in linked list               : press H\n\n\n");


    printf("-----Below are functionalities provided for added features of linked list(After entering 3 in ModeSelection stage)-----\n\n");

    printf("SEARCHING AND MERGING\n");
    printf("To Search a Specific Value in linkedlist  : press I\n");
    printf("To Reverse the linkedList                 : press J\n");
    printf("To Concatenate two linkedlists            : press K\n");
    printf("To Sort the linkedlist                    : press M\n\n");

    printf("UPDATING\n");
    printf("To Update value with a unique value in LL : press N\n");
    printf("To Update value at a position in LL       : press O\n\n");

    printf("INSERTION 2\n");
    printf("To Insert a node before a specific node   : press P\n");
    printf("To Insert a node after a specific node    : press Q\n\n");

    printf("DELETION 2\n");
    printf("To Delete a node before a specific node   : press R\n");
    printf("To Delete a node after a specific node    : press S\n");
    printf("To Delete the entire linkedlist           : press T\n\n");

    printf("FINDING\n");
    printf("To Find middle node of LL                 : press V\n");
    printf("To Find kth node from start of LL         : press X\n");
    printf("To Find kth node from middle of LL        : press Y\n");
    printf("To Find kth node from end of LL           : press Z\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in linked list      : press G\n\n");

    printf("DISPLAY\n");
    printf("To View data in linked list               : press H\n\n\n");


    printf("Below are the modes in which you can operate\n\n");

    printf("For Manual                      : press 1\n");
    printf("For Simple Access of linkedlist : press 2\n");
    printf("For use of Added features       : press 3\n");
    printf("To exit the LinkedList App      : press 4\n\n");
}


int main()
{
    //Manual();//Display the manual for the application

    SINGLY_CIRCULAR_LINKEDLIST SinglyCircularLL;

    PsNODE pRet = NULL;//Pointer to the second node of the linked list

    char siChoiceMode[] = "0";//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

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
                        cin>>iNo1;
                        cout<<endl;

                        SinglyCircularLL.InsertFirst(iNo1);
                        break;
                    case 'B':
                    case 'b':
                        cout<<"Enter the data to be inserted in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        SinglyCircularLL.InsertLast(iNo1);
                        break;
                    case 'C':
                    case 'c':
                        cout<<"Enter the data to be inserted in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        cout<<"Enter the position at which the data is to be inserted : ";
                        cin>>iPosition1;
                        cout<<endl;

                        SinglyCircularLL.InsertAtPosition(iNo1,iPosition1);

                        break;
                    case 'D':
                    case 'd':
                        SinglyCircularLL.DeleteFirst();

                        break;
                    case 'E':
                    case 'e':
                        SinglyCircularLL.DeleteLast();

                        break;
                    case 'F':
                    case 'f':
                        cout<<"Enter the position at which the data is to be deleted : ";
                        cin>>iPosition1;

                        SinglyCircularLL.DeleteAtPosition(iPosition1);

                        break;
                    case 'G':
                    case 'g':
                        SinglyCircularLL.Display();

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
                        SinglyCircularLL.Display();

                        break;
                    case 'H':
                    case 'h':
                        iRet = SinglyCircularLL.Count();
                        cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                        break;
                    case 'I':
                    case 'i':
                        cout<<"Enter the value to be searched in the linked list : ";
                        cin>>iNo1;

                        SinglyCircularLL.Search(iNo1);

                        break;
                    case 'J':
                    case 'j':
                        SinglyCircularLL.Reverse();

                        break;
                    case 'K':
                    case 'k':
                        SinglyCircularLL.Concat();

                        break;
                    case 'L':
                    case 'l':
                        //SinglyCircularLL.Merge(&pHead1,&pHead1);

                        break;
                    case 'M':
                    case 'm':
                        SinglyCircularLL.SortAscending();

                        break;
                    case 'N':
                    case 'n':
                        cout<<"Enter the value to be updated in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        cout<<"Enter the value to be updated with : ";
                        cin>>iNo2;

                        SinglyCircularLL.UpdateNoForNo(iNo1,iNo2);

                        break;
                    case 'O':
                    case 'o':
                        cout<<"Enter the value to be updated at a specific position in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        cout<<"Enter the position at which the data is to be updated : ";
                        cin>>iPosition1;

                        SinglyCircularLL.UpdateNoForPosition(iNo1,iPosition1);

                        break;
                    case 'P':
                    case 'p':
                        cout<<"Enter the data to be inserted in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        cout<<"Enter the position before which the data is to be inserted : ";
                        cin>>iPosition1;
                        cout<<endl;

                        SinglyCircularLL.InsertBefore(iNo1,iPosition1);

                        break;
                    case 'Q':
                    case 'q':
                        cout<<"Enter the data to be inserted in the linked list : ";
                        cin>>iNo1;
                        cout<<endl;


                        cout<<"Enter the position after which the data is to be inserted : ";
                        cin>>iPosition1;
                        cout<<endl;

                        SinglyCircularLL.InsertAfter(iNo1,iPosition1);

                        break;
                    case 'R':
                    case 'r':
                        cout<<"Enter the position before which the data is to be deleted : ";
                        cin>>iPosition1;
                        cout<<endl;

                        SinglyCircularLL.DeleteBefore(iPosition1);

                        break;
                    case 'S':
                    case 's':
                        cout<<"Enter the position after which the data is to be deleted : ";
                        cin>>iPosition1;
                        cout<<endl;
 
                        SinglyCircularLL.DeleteAfter(iPosition1);

                        break;
                    case 'T':
                    case 't':
                        SinglyCircularLL.DeleteList();

                        break;
                    case 'U':
                    case 'u':
                        //SinglyCircularLL.RemoveDuplicates();

                        break;
                    case 'V':
                    case 'v':
                        pRet = SinglyCircularLL.FindMiddleNode();

                        if(pRet != NULL)
                        {
                            cout<<"The data in middle node from the linked list is : "<<pRet -> iData<<endl;
                        }
                        else
                        {
                            cout<<"Invalid position"<<endl;
                        }

                        break;
                    case 'W':
                    case 'w':
                        cout<<"Enter the first linked list : ";
                        cin>>iNo1;
                        cout<<endl;

                        cout<<"Enter the second linked list : ";
                        cin>>iNo2;

                        //iReturn = pRet -> iDataFindDifference();

                        break;
                    case 'X':
                    case 'x':
                        pRet = SinglyCircularLL.FindKthNodeFromStart();

                        break;
                    case 'Y':
                    case 'y':
                        pRet = SinglyCircularLL.FindKthNodeFromMiddle();

                        break;
                    case 'Z':
                    case 'z':
                        pRet = SinglyCircularLL.FindKthNodeFromEnd();

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
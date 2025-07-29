//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Doubly Linear Linked-List is a type of linked-list where each node points to the   //
//Next And Previous node in the sequence while keeping the ends pointing to NULL. This program    //
//demonstrates the implementation of Generic Doubly Linear Linked List .                          //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 6th April 2025                                                                            //
//Day: Sunday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<iostream>
using namespace std;

//2===============================================================================================//






//3================================================================================================//

template<class Generic>
struct sNode//Structure declaration for node in Generic Doubly Linear Linked List
{
    Generic gData;//Data of the node
    struct sNode<Generic> *pNext;//Pointer to the next node in the linked list
    struct sNode<Generic> *pPrev;//Pointer to the previous node in the linked list
};//sNODE, *PsNODE;


template<class Generic>
class DOUBLY_LINEAR_LINKEDLIST
{
    private:
        struct sNode<Generic> *pHead;//Pointer to the first node of the linked list
        int iCountNode;//Counter for the number of nodes in the linked list

        struct sNode<Generic> *pHead1;
        struct sNode<Generic> *pHead2;

    public:
        DOUBLY_LINEAR_LINKEDLIST();//Constructor to initialize the doubly linear linked list
        ~DOUBLY_LINEAR_LINKEDLIST();//Destructor to delete the doubly linear linked list


//======Simple Access Functions======//

        //Insertion functions
        void InsertFirst(Generic);
        void InsertLast(Generic);
        void InsertAtPosition(Generic,int);

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
        bool Search(Generic);
        void UpdateNoForNo(Generic,Generic);
        void UpdateNoForPosition(Generic,int);
        void Concat();

        //Insert and Delete functions
        void InsertBefore(Generic,int);
        void InsertAfter(Generic,int);
        void DeleteBefore(int);
        void DeleteAfter(int);
        void DeleteList();

        //Sorting and Reversing functions
        void SortAscending();
        void Reverse();

        //Finding functions
        struct sNode<Generic> * FindMiddleNode();
        struct sNode<Generic> * FindKthNodeFromStart();
        struct sNode<Generic> * FindKthNodeFromMiddle();
        struct sNode<Generic> * FindKthNodeFromEnd();

//~=====Added Features Functions======//



        //Manual
        void Manual();
};


template<class Generic>
DOUBLY_LINEAR_LINKEDLIST<Generic>::DOUBLY_LINEAR_LINKEDLIST()
{
    pHead = NULL;
    iCountNode = 0;
}


template<class Generic>
DOUBLY_LINEAR_LINKEDLIST<Generic>::~DOUBLY_LINEAR_LINKEDLIST()
{
    free(pHead);
    pHead = NULL;
    iCountNode = 0;
}

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Doubly Linear Linked-List                                    //
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
//Display() Function: Displays the entire doubly linear linked list .                             //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and display the data of each node.               //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::Display()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        cout<<"NULL"<<endl;
        return;
    }

    cout<<"Elements from linked list are : "<<endl<<endl;

    ///////////////////////Display in serial order//////////////////////

    cout<<"Elements from linked list in serial order are : "<<endl;

    cout<<"NULL";
    while(pHead -> pNext != NULL)
    {
        cout<<"<- | "<<pHead -> gData<<" | -> ";
        pHead = pHead -> pNext;
    }
    cout<<"<- | "<<pHead -> gData<<" | -> ";
    cout<<"NULL"<<endl<<endl;

    ///////////////////////Display in reverse order//////////////////////

    cout<<"Elements from linked list in reverse order are : "<<endl<<endl;

    cout<<"NULL";
    while(pHead -> pPrev != NULL)
    {
        cout<<"<- | "<<pHead -> gData<<" | -> ";
        pHead = pHead -> pPrev;
    };
    cout<<"<- | "<<pHead -> gData<<" | -> ";
    cout<<"NULL";
    cout<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the doubly linear linked list .                      //
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
template<class Generic>
int DOUBLY_LINEAR_LINKEDLIST<Generic>::Count()
{
    return iCountNode;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the doubly linear linked list .  //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Pointer to the new node .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, update the Next pointer of the new node with  //
//   the address of the first node and update the first pointer with the address of the new node. //
//5. Increment the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::InsertFirst(Generic gNo)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = NULL;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if((iCountNode == 0) && (pHead == NULL))//If linkedlist is empty(pHead == NULL)
    {
        pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = pHead;
        pHead -> pPrev = PsNewNode;
        pHead = PsNewNode;
    }

    iCountNode++;

    cout<<"Node with data "<<gNo<<" inserted at the beginning of the doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the doubly linear linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Data to be inserted in the new node .                                              //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : Pointer to the new node .                                          //
//2. struct sNode<Generic> * : Temporary pointer for traversal                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, traverse till the last node and update the    //
//   Next pointer of the last node with the address of the new node.                              //
//5. Increment the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::InsertLast(Generic gNo)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = NULL;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if(iCountNode == 0)//If linkedlist is empty (pHead == NULL)
    {
        pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        struct sNode<Generic> *ptemp = pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
        PsNewNode -> pPrev = ptemp;
    }

    iCountNode++;

    cout<<"Node with data "<<gNo<<" inserted at the end of the doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the doubly linear      //
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
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
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
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::InsertAtPosition(Generic gNo,int iPosition)
{
    //Initialize a new node
    struct sNode<Generic> *PsNewNode = NULL;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

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
                InsertAtPosition(gNo,iPosition);
                return;
            }

            iCnt++;
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }
    else if((iCountNode == 0) && (pHead == NULL))//If linkedlist is empty
    {
        pHead = PsNewNode;
    }
    else if(iPosition == 1)//If position is 1
    {
        PsNewNode -> pNext = pHead;
        pHead -> pPrev = PsNewNode;
        pHead = PsNewNode;
    }
    else if(iPosition == (iCountNode + 1))//If position last
    {
        struct sNode<Generic> *ptemp = pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
        PsNewNode -> pPrev = ptemp;
    }
    else//Random position
    {
        struct sNode<Generic> *ptemp = pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext -> pPrev = PsNewNode;
        ptemp -> pNext = PsNewNode;
        PsNewNode -> pPrev = ptemp;
    }

    iCountNode++;

    cout<<"Node with data "<<gNo<<" inserted at position "<<iPosition<<" in the doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the doubly linear linked list .        //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list contains one node, delete the node and return .                           //
//3. If the linked list contains more than one node, store the address of the first node in a     //
//   temporary pointer, update the first pointer with the address of the next node and free the   //
//   memory of the temporary pointer.                                                             //
//4. Decrement the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteFirst()
{
    if((iCountNode == 0) && (pHead == NULL))//If linkedlist is empty
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else if((iCountNode == 1) && ((pHead) -> pNext == NULL))//If linkedlist contains one node
    {
        cout<<"Node with data "<<(pHead) -> gData<<" deleted from the beginning of the doubly linear linked list"<<endl;

        free(pHead);
        pHead = NULL;
    }
    else//If linkedlist contains atleast one node
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pHead -> pPrev -> gData<<" deleted from the beginning of the doubly linear linked list"<<endl;
        free(pHead -> pPrev);
        pHead -> pPrev = NULL;
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the doubly linear linked list .               //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list contains one node, delete the node and return .                           //
//3. If the linked list contains more than one node, traverse till the second last node and       //
//   delete the last node.                                                                        //
//4. Decrement the count of nodes in the linked list by 1.                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteLast()
{
    if((iCountNode == 0) && (pHead == NULL))//If linkedlist is empty
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }
    else if((iCountNode == 1) && ((pHead) -> pNext == NULL))//If linkedlist contains one node
    {
        cout<<"Node with data "<<(pHead) -> gData<<" deleted from the end of the doubly linear linked list"<<endl;

        free(pHead);
        pHead = NULL;
    }
    else//If linkedlist contains atleast two node
    {
        struct sNode<Generic> *ptemp = pHead;

        while(ptemp -> pNext -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        cout<<"Node with data "<<ptemp -> pNext -> gData<<" deleted from the end of the doubly linear linked list"<<endl;

        free(ptemp -> pNext);
        ptemp -> pNext = NULL;
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the doubly linear    //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable .                                                                     //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//3. struct sNode<Generic> * : temporary pointer to delete the node .                             //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteAtPosition(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL))//If linkedlist is empty
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

    if((iCountNode == 1) && ((pHead) -> pNext == NULL))
    {
        cout<<"Node with data "<<(pHead) -> gData<<" deleted from the doubly linear linked list"<<endl;

        free(pHead);
        pHead = NULL;
    }
    else if(iPosition == 1)//If position is 1
    {
        pHead = pHead -> pNext;

        cout<<"Node with data "<<pHead -> pPrev -> gData<<" deleted from the beginning of the doubly linear linked list"<<endl;

        free(pHead -> pPrev);
        pHead -> pPrev = NULL;
    }
    else if(iPosition == iCountNode)//If position last
    {
        struct sNode<Generic> *ptempdelete = pHead;

        while(ptempdelete -> pNext -> pNext != NULL)
        {
            ptempdelete = ptempdelete -> pNext;
        }

        cout<<"Node with data "<<ptempdelete -> pNext -> gData<<" deleted from the end of the doubly linear linked list"<<endl;

        free(ptempdelete -> pNext);
        ptempdelete -> pNext = NULL;
    }
    else//Random position
    {
        struct sNode<Generic> *ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptempdelete = ptempdelete -> pNext;
        }

        ptempdelete -> pNext = ptempdelete -> pNext -> pNext;

        cout<<"Node with data "<<ptempdelete -> pNext -> pPrev -> gData<<" deleted from "<<iPosition<<" position from doubly linear linked list"<<endl;

        free(ptempdelete -> pNext -> pPrev);
        ptempdelete -> pNext -> pPrev = ptempdelete;
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
//Search() Function: Searches for a specific value from the doubly linear linked list .           //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, display the position of the node and return true.    //
//2. If the value is not found, return false.                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
bool DOUBLY_LINEAR_LINKEDLIST<Generic>::Search(Generic gSearch)
{
    if((iCountNode == 0)  && (pHead == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        return false;
    }

    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(pHead -> gData == gSearch)
        {
            cout<<"Element "<<gSearch<<" is found at position "<<iPosition<<" in doubly linear linked list"<<endl;
            return true;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    cout<<"Element "<<gSearch<<" not found in doubly circular linked list"<<endl;
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value in the doubly linear//
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//2. Generic : Value to be updated in the linked list .                                           //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::UpdateNoForNo(Generic gSearch,Generic gUpdate)
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"Linkedlist is empty"<<endl;
        return;
    }

    int iPosition = 1;

    while(iPosition <= iCountNode)
    {
        if(pHead -> gData == gSearch)
        {
            pHead -> gData = gUpdate;
            cout<<"Element "<<gSearch<<" has been updated to "<<gUpdate<<" in doubly linear linked list"<<endl;

            return;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    cout<<"Element "<<gSearch<<" not found in doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForPosition() Function: Updates the value at a specific position in doubly linear linked//
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. Generic : Value to be searched in the linked list .                                          //
//2. int : Value at which data is to be inserted in linked list .                                 //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::UpdateNoForPosition(Generic gUpdate,int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL))
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
                UpdateNoForPosition(gUpdate,iPosition);
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
            pHead -> gData = gUpdate;
            cout<<"Element at position "<<iPosition<<" has been updated to "<<gUpdate<<" in doubly linear linked list"<<endl;

            return;
        }

        pHead = pHead -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Concat() Function: Concats two doubly linear linked list .                                      //
//================================================================================================//
//Parameters:                                                                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If both linked lists are empty, display a message that both linked lists are empty.          //
//2. If the first linked list is empty, display a message that the first linked list is empty.    //
//3. If the second linked list is empty, display a message that the second linked list is empty.  //
//4. Traverse the first linked list till the last node and update thepNext pointer of the last    //
//   node with the address of the first node of the second linked list and free the second linked //
//   list.                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::Concat()
{
    if((pHead1 == NULL) && (pHead2 == NULL))
    {
        cout<<"Both linkedlist are empty"<<endl;
        return;
    }
    else if(pHead1 == NULL)
    {
        cout<<"First linkedlist is empty"<<endl;
        return;
    }
    else if(pHead2 == NULL)
    {
        cout<<"Second linkedlist is empty"<<endl;
        return;
    }

    struct sNode<Generic> *ptemp = pHead1;

    while(ptemp -> pNext != NULL)
    {
        ptemp = ptemp -> pNext;
    }

    ptemp -> pNext = pHead2;
    pHead1 -> pPrev = ptemp;
    pHead2 = NULL;//Freeing the second linked list
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in doubly linear linked list . //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the position is invalid, display a message that the position is invalid.                  //
//3. If the position is 1, call the InsertFirst() Function or use its logic .                     //
//4. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the Next       //
//   pointer of the previous node with the address of the new node.                               //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::InsertBefore(Generic gNo,int iPosition)
{
    if((iCountNode == 0)  && (pHead == NULL))
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
                InsertBefore(gNo,iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }


    //Initialize a new node
    struct sNode<Generic> *PsNewNode = NULL;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = pHead;
        pHead -> pPrev = PsNewNode;
        pHead = PsNewNode;
    }
    else
    {
        struct sNode<Generic> *ptemp = pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;
        PsNewNode -> pNext -> pPrev = PsNewNode;

        ptemp = NULL;//Freeing the temporary pointer
    }

    iCountNode++;

    cout<<"Node with data "<<gNo<<" inserted at the position "<<iPosition<<" of the doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in doubly linear linked list .   //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::InsertAfter(Generic gNo,int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL))
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
                InsertAfter(gNo,iPosition);
                return;
            }
        }

        cout<<"Wrong input entered 3 times , call function again ."<<endl;

        return;
    }


    //Initialize a new node
    struct sNode<Generic> *PsNewNode = NULL;
    PsNewNode = new sNode<Generic>;

    //Filling the node with data
    PsNewNode -> gData = gNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    struct sNode<Generic> *ptemp = pHead;

    if(iPosition == iCountNode)
    {
        //InsertLast(pHead,iNo); ---> Can be used

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
        PsNewNode -> pPrev = ptemp;

        ptemp = NULL;;//Freeing the temporary pointer
    }
    else
    {
        for(iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext -> pPrev = PsNewNode;
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;
    }

    iCountNode++;

    cout<<"Node with data "<<gNo<<" inserted at the position "<<(iPosition + 1)<<" of the doubly linear linked list"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before a specified node from doubly linear linked list .//
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to delete the node .                             //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteBefore(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL))
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

    struct sNode<Generic> *ptemp = pHead;

    if(iPosition == 2)
    {
        pHead = ptemp -> pNext;
        pHead -> pPrev = NULL;

        cout<<"Node with data "<<ptemp -> gData<<" deleted from the beginning of the doubly linear linked list"<<endl;

        free(ptemp);
        ptemp = NULL;
    }
    else
    {
        struct sNode<Generic> *ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;
        ptempdelete -> pNext -> pPrev = ptemp;

        cout<<"Node with data "<<ptempdelete -> gData<<" deleted from the doubly linear linked list"<<endl;

        free(ptempdelete);
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from doubly linear linked list .   //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to delete the node .                             //
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
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteAfter(int iPosition)
{
    if((iCountNode == 0) && (pHead == NULL))
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

    struct sNode<Generic> *ptemp = pHead;

    if(iPosition == (iCountNode - 1))
    {
        while(ptemp -> pNext -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        cout<<"Node with data "<<ptemp -> pNext -> gData<<" deleted from the doubly linear linked list"<<endl;

        free(ptemp -> pNext);
        ptemp -> pNext = NULL;
    }
    else
    {
        struct sNode<Generic> *ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;
        ptempdelete -> pNext -> pPrev = ptemp;

        cout<<"Node with data "<<ptempdelete -> gData<<" deleted from the doubly linear linked list"<<endl;

        free(ptempdelete);
    }

    iCountNode--;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire doubly linear linked list .                           //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and free the memory of each node.  //
//   Update the first pointer to NULL after freeing the memory of each node.                      //
//3. Finally, free the memory of the first pointer.                                               //
//4. Display a message that the linked list has been deleted.                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::DeleteList()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is already empty"<<endl;
        return;
    }

    struct sNode<Generic> *ptempdelete = pHead;

    while(pHead != NULL)
    {
        ptempdelete = pHead;
        pHead = pHead -> pNext;

        cout<<"Node with data "<<ptempdelete -> gData<<" deleted from the doubly linear linked list"<<endl;

        free(ptempdelete);
        ptempdelete = NULL;

        iCountNode--;
    }

    free(pHead);
    pHead = NULL;

    cout<<"Doubly Linear Linked-List has been deleted"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the doubly linear linked list in ascending order .              //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//3. int : temporary variable to store the data of the node .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and compare the data of each node  //
//   with the data of the next node. If the data of the first node is greater than the data of    //
//   the next node, swap the data of the two nodes. Repeat this process till the last node.       //
//3. Finally, display a message that the linked list has been sorted in ascending order.          //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::SortAscending()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return;
    }

    int itransfer = 0;
    struct sNode<Generic> *ptemp1 = pHead;
    struct sNode<Generic> *ptemp2 = pHead;

    for(ptemp1 = pHead;ptemp1 -> pNext != NULL;ptemp1 = ptemp1 -> pNext)
    {
        for(ptemp2 = ptemp1 -> pNext;ptemp2 != NULL;ptemp2 = ptemp2 -> pNext)
        {
            if(ptemp1 -> gData > ptemp2 -> gData)
            {
                itransfer = ptemp1 -> gData;
                ptemp1 -> gData = ptemp2 -> gData;
                ptemp2 -> gData = itransfer;
            }
        }
    }

    cout<<"Doubly Linear Linked-List has been sorted as in ascending order"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in doubly linear linked list .                   //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list is not empty, traverse the linked list and compare the data of each node  //
//   with the data of the next node. If the data of the first node is greater than the data of    //
//   the next node, swap the data of the two nodes. Repeat this process till the last node.       //
//3. Finally, display a message that the linked list has been sorted in ascending order.          //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::Reverse()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return;
    }

    struct sNode<Generic> *ptemp = NULL;
    struct sNode<Generic> *pCurrent = pHead;

    while(pCurrent != NULL)
    {
        ptemp = pCurrent -> pPrev;
        pCurrent -> pPrev = pCurrent -> pNext;
        pCurrent -> pNext = ptemp;
        pCurrent = pCurrent -> pPrev;
    }

    if(ptemp != NULL)
    {
        pHead = ptemp -> pPrev;
    }

    cout<<"Doubly Linear Linked-List's data has been reversed"<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the doubly linear linked list .         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. Traverse the linked list till the middle node and return the address of the middle node.     //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> *DOUBLY_LINEAR_LINKEDLIST<Generic>::FindMiddleNode()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    struct sNode<Generic> *ptemp = pHead;

    int iCnt = 0;

    for(iCnt = 1;iCnt < ((iCountNode + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: returns the kth node from start from doubly linear linkedlist .//
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. int : integer to store kth position from start .                                             //
//3. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the kth position is invalid, display a message that the kth position is invalid.          //
//3. Travel the linked list till the kth node from start and return the address of the kth node.  //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> *DOUBLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromStart()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    struct sNode<Generic> *ptemp = pHead;

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
        cout<<"Data in "<<iKth<<" node from start is : "<<ptemp -> gData<<endl;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from doubly linear linked    //
// list .                                                                                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
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
template<class Generic>
struct sNode<Generic> *DOUBLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromMiddle()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    struct sNode<Generic> *ptemp = pHead;

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
        cout<<"Invalid position"<<endl;

        cout<<"Wrong input, call function again ."<<endl;

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
            cout<<"Data in "<<iKth<<" node from middle to start is : "<<ptemp -> gData<<endl;
        }
        else
        {
            cout<<"Data in "<<iKth<<" node from middle to end is : "<<ptemp -> gData<<endl;
        }
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end from doubly linear linkedlist .    //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: struct sNode<Generic> *                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. struct sNode<Generic> * : temporary pointer to traverse the linked list .                    //
//2. int : integer to store kth position from start .                                             //
//3. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the kth position is invalid, display a message that the kth position is invalid.          //
//3. If the kth position is random, traverse the linked list till the kth node from end and       //
//   return the address of the kth node.                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
struct sNode<Generic> *DOUBLY_LINEAR_LINKEDLIST<Generic>::FindKthNodeFromEnd()
{
    if((iCountNode == 0) && (pHead == NULL))
    {
        cout<<"linkedlist is empty"<<endl;
        return 0;
    }

    struct sNode<Generic> *ptemp = pHead;

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
        cout<<"Data in "<<iKth<<" node from end is : "<<ptemp -> gData<<endl;
    }

    return ptemp;
}


//5===============================================================================================//





//6===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of doubly-linear-linked-list .                         //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm: None                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Generic>
void DOUBLY_LINEAR_LINKEDLIST<Generic>::Manual()
{
    cout<<"::::MANUAL FOR RAJAS's DOUBLY LINEAR LINKED LIST APPLICATION::::"<<endl<<endl<<endl;


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
    cout<<"To  Exit                        : press 4"<<endl<<endl<<endl;


    cout<<"Below are the datatype in which you can operate"<<endl<<endl;

    cout<<"For Integer number linked list : press 1"<<endl;
    cout<<"For Decimal number linked list : press 2"<<endl;
    cout<<"To exit the LinkedList App     : press 3"<<endl<<endl;
}


int main()
{
    cout<<"Welcome to Rajas's Application of Generic-Singly-Linear-LinkedList"<<endl<<endl;

    char siChoiceMode[] = "0";
    char cChoiceFunction = '\0';

    int iEntryCount = 0;
    float fEntryCount = 0.0f;

    DOUBLY_LINEAR_LINKEDLIST <int>SinglyLinearLL_Integer;
    DOUBLY_LINEAR_LINKEDLIST <float>SinglyLinearLL_Float;


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
                    SinglyLinearLL_Integer.~DOUBLY_LINEAR_LINKEDLIST();
                    DOUBLY_LINEAR_LINKEDLIST <int>SinglyLinearLL_Integer;
                }
            }
            iEntryCount++;

            siChoiceMode[0] = '\0';

            int iNo1 = 0,iNo2,iPosition1 = 0,iRet = 0;
            bool bRet = false;
            struct sNode<int> *pRet = NULL;

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
                    SinglyLinearLL_Integer.Manual();
                }
                else if(atoi(siChoiceMode) == 2)
                {
                    siChoiceMode[0] = '\0';

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
                                cin>>iNo1;
                                cout<<endl;

                                SinglyLinearLL_Integer.InsertFirst(iNo1);
                                break;
                            case 'B':
                            case 'b':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;

                                SinglyLinearLL_Integer.InsertLast(iNo1);
                                break;
                            case 'C':
                            case 'c':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;

                                cout<<"Enter the position at which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Integer.InsertAtPosition(iNo1,iPosition1);

                                break;
                            case 'D':
                            case 'd':
                                SinglyLinearLL_Integer.DeleteFirst();

                                break;
                            case 'E':
                            case 'e':
                                SinglyLinearLL_Integer.DeleteLast();

                                break;
                            case 'F':
                            case 'f':
                                cout<<"Enter the position at which the data is to be deleted : ";
                                cin>>iPosition1;

                                SinglyLinearLL_Integer.DeleteAtPosition(iPosition1);

                                break;
                            case 'G':
                            case 'g':
                                SinglyLinearLL_Integer.Display();

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
                                siChoiceMode[0] = '1';
                                cout<<"Exiting SIMPLE ACCESS mode"<<endl;

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 3)
                {
                    siChoiceMode[0] = '\0';

                    cout<<"Active Mode : ADDED ACCESS"<<endl;

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
                                SinglyLinearLL_Integer.Display();

                                break;
                            case 'H':
                            case 'h':
                                iRet = SinglyLinearLL_Integer.Count();
                                cout<<"Number of nodes in the linked list are : "<<iRet<<endl;

                                break;
                            case 'I':
                            case 'i':
                                cout<<"Enter the value to be searched in the linked list : ";
                                cin>>iNo1;

                                bRet = SinglyLinearLL_Integer.Search(iNo1);

                                break;
                            case 'J':
                            case 'j':
                                SinglyLinearLL_Integer.Reverse();

                                break;
                            case 'K':
                            case 'k':
                                SinglyLinearLL_Integer.Concat();

                                break;
                            case 'L':
                            case 'l':
                                //SinglyLinearLL.Merge(&pHead1,&pHead1);

                                break;
                            case 'M':
                            case 'm':
                                SinglyLinearLL_Integer.SortAscending();

                                break;
                            case 'N':
                            case 'n':
                                cout<<"Enter the value to be updated in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;

                                cout<<"Enter the value to be updated with : ";
                                cin>>iNo2;

                                SinglyLinearLL_Integer.UpdateNoForNo(iNo1,iNo2);

                                break;
                            case 'O':
                            case 'o':
                                cout<<"Enter the value to be updated at a specific position in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;

                                cout<<"Enter the position at which the data is to be updated : ";
                                cin>>iPosition1;

                                SinglyLinearLL_Integer.UpdateNoForPosition(iNo1,iPosition1);

                                break;
                            case 'P':
                            case 'p':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;

                                cout<<"Enter the position before which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Integer.InsertBefore(iNo1,iPosition1);

                                break;
                            case 'Q':
                            case 'q':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>iNo1;
                                cout<<endl;


                                cout<<"Enter the position after which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Integer.InsertAfter(iNo1,iPosition1);

                                break;
                            case 'R':
                            case 'r':
                                cout<<"Enter the position before which the data is to be deleted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Integer.DeleteBefore(iPosition1);

                                break;
                            case 'S':
                            case 's':
                                cout<<"Enter the position after which the data is to be deleted : ";
                                cin>>iPosition1;
                                cout<<endl;
        
                                SinglyLinearLL_Integer.DeleteAfter(iPosition1);

                                break;
                            case 'T':
                            case 't':
                                SinglyLinearLL_Integer.DeleteList();

                                break;
                            case 'U':
                            case 'u':
                                //SinglyLinearLL_Integer.RemoveDuplicates();

                                break;
                            case 'V':
                            case 'v':
                                pRet = SinglyLinearLL_Integer.FindMiddleNode();

                                if(pRet != NULL)
                                {
                                    cout<<"The data in middle node from the linked list is : "<<pRet -> gData<<endl;
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
                                pRet = SinglyLinearLL_Integer.FindKthNodeFromStart();

                                break;
                            case 'Y':
                            case 'y':
                                pRet = SinglyLinearLL_Integer.FindKthNodeFromMiddle();

                                break;
                            case 'Z':
                            case 'z':
                                pRet = SinglyLinearLL_Integer.FindKthNodeFromEnd();

                                break;
                            case 'A':
                            case 'a':
                                siChoiceMode[0] = '1';
                                cout<<"Exiting ADDED FEATURES mode"<<endl;

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 4)
                {
                    cout<<"Exiting the Integer-Linkedlist"<<endl;
                    break;
                }
                else
                {
                    cout<<"Invalid Choice"<<endl;
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
                    SinglyLinearLL_Float.~DOUBLY_LINEAR_LINKEDLIST();
                    DOUBLY_LINEAR_LINKEDLIST <float>SinglyLinearLL_Float;
                }
            }
            fEntryCount++;

            siChoiceMode[0] = '\0';

            float fNo1 = 0,fNo2,fRet = 0;
            int iPosition1 = 0;
            bool bRet = false;
            struct sNode<float> *pRet = NULL;

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
                    SinglyLinearLL_Float.Manual();
                }
                else if(atoi(siChoiceMode) == 2)
                {
                    siChoiceMode[0] = '\0';

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
                                cin>>fNo1;
                                cout<<endl;

                                SinglyLinearLL_Float.InsertFirst(fNo1);
                                break;
                            case 'B':
                            case 'b':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                SinglyLinearLL_Float.InsertLast(fNo1);
                                break;
                            case 'C':
                            case 'c':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                cout<<"Enter the position at which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Float.InsertAtPosition(fNo1,iPosition1);

                                break;
                            case 'D':
                            case 'd':
                                SinglyLinearLL_Float.DeleteFirst();

                                break;
                            case 'E':
                            case 'e':
                                SinglyLinearLL_Float.DeleteLast();

                                break;
                            case 'F':
                            case 'f':
                                cout<<"Enter the position at which the data is to be deleted : ";
                                cin>>iPosition1;

                                SinglyLinearLL_Float.DeleteAtPosition(iPosition1);

                                break;
                            case 'G':
                            case 'g':
                                SinglyLinearLL_Float.Display();

                                break;
                            case 'H':
                            case 'h':
                                fRet = SinglyLinearLL_Float.Count();
                                cout<<"Number of nodes in the linked list are : "<<fRet<<endl;

                                break;
                            case 'Y':
                            case 'y':
                                SinglyLinearLL_Float.Manual();//Display the manual for the application

                                break;
                            case 'Z':
                            case 'z':
                                siChoiceMode[0] = '1';
                                cout<<"Exiting SIMPLE ACCESS mode"<<endl;

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 3)
                {
                    siChoiceMode[0] = '\0';

                    cout<<"Active Mode : ADDED ACCESS"<<endl;

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
                                SinglyLinearLL_Float.Display();

                                break;
                            case 'H':
                            case 'h':
                                fRet = SinglyLinearLL_Float.Count();
                                cout<<"Number of nodes in the linked list are : "<<fRet<<endl;

                                break;
                            case 'I':
                            case 'i':
                                cout<<"Enter the value to be searched in the linked list : ";
                                cin>>fNo1;

                                bRet = SinglyLinearLL_Float.Search(fNo1);

                                break;
                            case 'J':
                            case 'j':
                                SinglyLinearLL_Float.Reverse();

                                break;
                            case 'K':
                            case 'k':
                                SinglyLinearLL_Float.Concat();

                                break;
                            case 'L':
                            case 'l':
                                //SinglyLinearLL_Float.Merge(&pHead1,&pHead1);

                                break;
                            case 'M':
                            case 'm':
                                SinglyLinearLL_Float.SortAscending();

                                break;
                            case 'N':
                            case 'n':
                                cout<<"Enter the value to be updated in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                cout<<"Enter the value to be updated with : ";
                                cin>>fNo2;

                                SinglyLinearLL_Float.UpdateNoForNo(fNo1,fNo2);

                                break;
                            case 'O':
                            case 'o':
                                cout<<"Enter the value to be updated at a specific position in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                cout<<"Enter the position at which the data is to be updated : ";
                                cin>>iPosition1;

                                SinglyLinearLL_Float.UpdateNoForPosition(fNo1,iPosition1);

                                break;
                            case 'P':
                            case 'p':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                cout<<"Enter the position before which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Float.InsertBefore(fNo1,iPosition1);

                                break;
                            case 'Q':
                            case 'q':
                                cout<<"Enter the data to be inserted in the linked list : ";
                                cin>>fNo1;
                                cout<<endl;


                                cout<<"Enter the position after which the data is to be inserted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Float.InsertAfter(fNo1,iPosition1);

                                break;
                            case 'R':
                            case 'r':
                                cout<<"Enter the position before which the data is to be deleted : ";
                                cin>>iPosition1;
                                cout<<endl;

                                SinglyLinearLL_Float.DeleteBefore(iPosition1);

                                break;
                            case 'S':
                            case 's':
                                cout<<"Enter the position after which the data is to be deleted : ";
                                cin>>iPosition1;
                                cout<<endl;
        
                                SinglyLinearLL_Float.DeleteAfter(iPosition1);

                                break;
                            case 'T':
                            case 't':
                                SinglyLinearLL_Float.DeleteList();

                                break;
                            case 'U':
                            case 'u':
                                //SinglyLinearLL_Float.RemoveDuplicates();

                                break;
                            case 'V':
                            case 'v':
                                pRet = SinglyLinearLL_Float.FindMiddleNode();

                                if(pRet != NULL)
                                {
                                    cout<<"The data in middle node from the linked list is : "<<pRet -> gData<<endl;
                                }
                                else
                                {
                                    cout<<"Invalid position"<<endl;
                                }

                                break;
                            case 'W':
                            case 'w':
                                cout<<"Enter the first linked list : ";
                                cin>>fNo1;
                                cout<<endl;

                                cout<<"Enter the second linked list : ";
                                cin>>fNo2;

                                //iReturn = pRet -> iDataFindDifference();

                                break;
                            case 'X':
                            case 'x':
                                pRet = SinglyLinearLL_Float.FindKthNodeFromStart();

                                break;
                            case 'Y':
                            case 'y':
                                pRet = SinglyLinearLL_Float.FindKthNodeFromMiddle();

                                break;
                            case 'Z':
                            case 'z':
                                pRet = SinglyLinearLL_Float.FindKthNodeFromEnd();

                                break;
                            case 'A':
                            case 'a':
                                siChoiceMode[0] = '1';
                                cout<<"Exiting ADDED FEATURES mode"<<endl;

                                break;
                            default:
                                cout<<"Invalid choice"<<endl;
                        }
                    }
                }
                else if(atoi(siChoiceMode) == 4)
                {
                    cout<<"Exiting the Decimal-Linkedlist"<<endl;
                }
                else
                {
                    cout<<"Invalid Choice"<<endl;
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
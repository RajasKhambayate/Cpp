////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program sorts the unsorted array or n-Numbers .                               //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 26th May 2025                                                                             //
//Day: Monday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<limits>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Insertion_Sort_n_Number() Function: This function sorts the unsorted array or n-Number .        //
//================================================================================================//
//Parameters:                                                                                     //
//1. int[](piArray1) : The address of array to perfrom addition of n-Numbers .                    //
//2. int(iLength)   : The size of the array .                                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iIterator1) : variable to iterate through the loop                                       //
//2. int(iIterator2) : variable to iterate through the loop                                       //
//3. int(iSelected)  : variable to iterate through the loop                                       //
//================================================================================================//
//Algorithm:                                                                                      //
//1. The first element of the array is considered already sorted.                                 //
//2. Pick the next element from the unsorted part of the array (let's call it 'key').             //
//3. Compare 'key' with the elements in the sorted part, moving from right to left.               //
//4. Shift each element in the sorted part that is greater than 'key' one position to the right.  //
//5. Insert 'key' into the correct position (the 'hole' created by shifting).                     //
//6. Repeat steps 2-5 until the entire array is sorted.                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Insertion_Sort_n_Number(int piArray1[],int iLength)
{
    int iIterator1 = 0,iIterator2 = 0,iSelected = 0;

    for(iIterator1 = 1;iIterator1 < iLength;iIterator1++)
    {
        for(iIterator2 = (iIterator1 - 1),iSelected = piArray1[iIterator1];(iIterator2 >= 0) && (piArray1[iIterator2] > iSelected);iIterator2--)
        {
            piArray1[iIterator2 + 1] = piArray1[iIterator2];
        }

        piArray1[iIterator2 + 1] = iSelected;
    }
}

//Starting point of the program
int main()
{
    int iSize = 0,iCnt = 0,iRet = 0;
    int *piArray = NULL;

    while(1)
    {
        cout<<"Please enter the size of n : ";
        while(iSize < 2)
        {
            while((!(cin>>iSize)) || (cin.peek() != '\n'))
            {
                cout<<"Invalid input. Please enter a single whole number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }

            if(iSize < 2)
            {
                cout<<"Please enter size greater than 1"<<endl;
            }
        }

        piArray = new int[iSize];

        cout<<"Please enter the n-numbers : ";
        for(iCnt = 0;iCnt < iSize;iCnt++)
        {
            while((!(cin>>piArray[iCnt])) || (cin.peek() != '\n'))
            {
                cout<<"Invalid input. Please enter a single whole number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }

        Insertion_Sort_n_Number(piArray,iSize);

        cout<<"Sorted Array is : "<<endl;
        for(iCnt = 0;iCnt < iSize;iCnt++)
        {
            cout<<piArray[iCnt]<<"\t";
        }cout<<endl;

        cout<<"Would you like to try Insertion_Sort_n_Number one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iSize)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iSize == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Insertion_Sort_n_Number program ."<<endl;
            break;
        }
        else
        {
            cout<<"===================================================================================================="<<endl;
            iSize = -1;
            continue;
        }
    }

    return 0;
}
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
//Bubble_Sort_n_Number() Function: This function sorts the unsorted array or n-Number .           //
//================================================================================================//
//Parameters:                                                                                     //
//1. int[](piArray1) : The address of array to perfrom addition of n-Numbers .                    //
//2. int(iLength)   : The size of the array .                                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iIterator1) : variable to iterate through the outer loop (passes)                        //
//2. int(iIterator2) : variable to iterate through the inner loop (comparisons)                   //
//3. int(iTemp)      : variable to swap values                                                    //
//4. bool(bSwap)     : variable to check if a swap occurred in a pass.                            //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Start from the first element, iterate through the array from left to right with 'iIterator1' //
//   (this is a pass).                                                                            //
//2. In each pass, compare adjacent elements using an inner loop with 'iIterator2'.               //
//3. If the current element is greater than the next one, swap them.                              //
//4. Keep a boolean flag 'bSwap' to track if any swap happened in a pass.                         //
//5. After each pass, the largest unsorted element "bubbles up" to its correct position.          //
//6. If a full pass completes with no swaps ('bSwap' remains false), the array is sorted, and we  //
//   can break out of the outer loop early.                                                       //
//7. Repeat the passes until the array is fully sorted.                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Bubble_Sort_n_Number(int piArray1[],int iLength)
{
    int iIterator1 = 0,iIterator2 = 0,iTemp = 0;
    bool bSwap = false;

    for(iIterator1 = 0;iIterator1 < iLength;iIterator1++)
    {
        bSwap = false;

        for(iIterator2 = 0;iIterator2 < (iLength - iIterator1 - 1);iIterator2++)
        {
            if(piArray1[iIterator2] > piArray1[iIterator2 + 1])// if(piArray1[iIterator2] < piArray1[iIterator2 + 1])  ------> For Decreasing Order Sort
            {
                iTemp = piArray1[iIterator2];
                piArray1[iIterator2] = piArray1[iIterator2 + 1];
                piArray1[iIterator2 + 1] = iTemp;
                bSwap = true;
            }
        }

        if(bSwap == false)
        {
            break;
        }
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

        Bubble_Sort_n_Number(piArray,iSize);

        cout<<"Sorted Array is : "<<endl;
        for(iCnt = 0;iCnt < iSize;iCnt++)
        {
            cout<<piArray[iCnt]<<"\t";
        }cout<<endl;

        cout<<"Would you like to try Bubble_Sort_n_Number one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iSize)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iSize == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Bubble_Sort_n_Number program ."<<endl;
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
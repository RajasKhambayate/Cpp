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
//Selection_Sort_n_Numbers() Function: This function sorts the unsorted array or n-Number .       //
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
//3. int(iMin_Index) : variable to iterate through the loop                                       //
//4. int(iTemp)      : variable to swap values                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Iterate from the first element to the second-to-last element of the array(using iIterator1). //
//2. Assume the element at the current position 'iIterator' is the minimum .                      //
//3. In an inner loop, scan the rest of the unsorted part of the array (from 'iIterator+1' to the //
//   end) .                                                                                       //
//4. If an element smaller than the current minimum is found, update the index of the minimum.    //
//5. After scanning the unsorted part, swap the element at position 'iIterator' with the minimum  //
//   element .                                                                                    //
//6. Repeat until the entire array is sorted .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Selection_Sort_n_Number(int piArray1[],int iLength)
{
    int iIterator1 = 0,iIterator2 = 0,iMin_Index = 0,iTemp = 0;

    for(iIterator1 = 0;iIterator1 < (iLength - 1);iIterator1++)
    {
        iMin_Index = iIterator1;

        for(iIterator2 = (iIterator1 + 1);iIterator2 < iLength;iIterator2++)
        {
            if(piArray1[iMin_Index] > piArray1[iIterator2])
            {
                iMin_Index = iIterator2;
            }
        }

        if(iIterator1 != iMin_Index)
        {
            iTemp = piArray1[iIterator1];
            piArray1[iIterator1] = piArray1[iMin_Index];
            piArray1[iMin_Index] = iTemp;
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

        Selection_Sort_n_Number(piArray,iSize);

        cout<<"Sorted Array is : "<<endl;
        for(iCnt = 0;iCnt < iSize;iCnt++)
        {
            cout<<piArray[iCnt]<<"\t";
        }cout<<endl;

        cout<<"Would you like to try Selection_Sort_n_Number one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iSize)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iSize == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Selection_Sort_n_Number program ."<<endl;
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
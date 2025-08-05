////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program add all n numbers the number within a array .                         //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 25th May 2025                                                                             //
//Day: Sunday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<limits>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Summation_n-Numbers() Function: This function adds all number in a array .                      //
//================================================================================================//
//Parameters:                                                                                     //
//1. int[](pArray1) : The address of array to perfrom addition of n-Numbers .                     //
//2. int(iLength)   : The size of the array .                                                     //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt)         : The variable to store the count of digits .                              //
//2. int(iSummation)   : The variable to store the summation of digits .                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the array while adding the value of each element in another variable .              //

////////////////////////////////////////////////////////////////////////////////////////////////////
int Summation_n_Numbers(int pArray1[],int iLength)
{
    int iCnt = 0,iSummation = 0;

    for(iCnt = 0;iCnt < iLength;iCnt++)
    {
        iSummation += pArray1[iCnt];
    }

    return iSummation;
}

//Starting point of the program
int main()
{
    int iSize = 0,iCnt = 0,iRet = 0;
    int *pArray = NULL;

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

        pArray = new int[iSize];

        cout<<"Please enter the n-numbers : ";
        for(iCnt = 0;iCnt < iSize;iCnt++)
        {
            while((!(cin>>pArray[iCnt])) || (cin.peek() != '\n'))
            {
                cout<<"Invalid input. Please enter a single whole number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }

        iRet = Summation_n_Numbers(pArray,iSize);
        cout<<"Summation of n-Numbers is : "<<iRet<<endl;

        cout<<"Would you like to try Summation_n-Numbers one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iSize)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iSize == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Summation_n-Numbers program ."<<endl;
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
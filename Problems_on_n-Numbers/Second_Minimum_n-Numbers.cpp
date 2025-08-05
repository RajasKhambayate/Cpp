////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program will give you second minimum number among n-Numbers .                 //
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
//Second_Minimum_n_Number() Function: This function gives second minimum number among n values .  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int[](piArray1) : The address of array to perfrom addition of n-Numbers .                    //
//2. int(iLength)   : The size of the array .                                                     //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt)       : The variable to store the count of digits .                                //
//2. int(iSec_Min)   : The variable to store the second minimum number .                          //
//3. int(iMin)       : The variable to store the minimum number .                                 //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the array while checking for minimum number and when iteration finds minimum number //
//   put the min value in second min value .                                                      //
//2. return the Second minimum value when iteration stops .                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Second_Minimum_n_Number(int piArray1[],int iLength)
{
    int iCnt = 0,iSec_Min = numeric_limits<int>::max(),iMin = numeric_limits<int>::max();

    for(iCnt = 0;iCnt < iLength;iCnt++)
    {
        if(iMin > piArray1[iCnt])
        {
            iSec_Min = iMin;
            iMin = piArray1[iCnt];
        }
        else if((iSec_Min > piArray1[iCnt]) && (iMin < piArray1[iCnt]))
        {
            iSec_Min = piArray1[iCnt];
        }
    }


    return iSec_Min;
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


        iRet = Second_Minimum_n_Number(piArray,iSize);
        cout<<"Second Minimum among all of n-Numbers is : "<<iRet<<endl;

        cout<<"Would you like to try Second_Minimum_n_Number one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iSize)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iSize == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Second_Minimum_n_Number program ."<<endl;
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
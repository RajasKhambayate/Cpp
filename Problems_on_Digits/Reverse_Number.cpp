////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program reverses the digits of a number .                                     //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 21th May 2025                                                                             //
//Day: Wednesday                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<limits>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse_Number() Function: This function reverses the digit within a number .                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value display the digits from .                                            //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iDigit)   : variable to store the remainder of the number .                              //
//2. int(iReverse) : variable to store reversed number .                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Divide the original number by 10 and add the remainder to another variable till the original //
//   number is greater than zero .                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Reverse_Number(int iValue)
{
    int iDigit = 0,iReverse = 0;

    if(iValue < 0)
    {
        iValue = -iValue;
    }

    while(iValue > 0)
    {
        iDigit = iValue % 10;
        iReverse = iReverse * 10 + iDigit;
        iValue = iValue / 10;
    }

    return iReverse;
}

//Starting point of the program
int main()
{
    int iNo = 0;

    while(1)
    {
        cout<<"Please enter a integer value : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter a single whole number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        int iRet = Reverse_Number(iNo);
        cout<<iRet<<" : is a reverse form of : "<<iNo<<endl;

        cout<<"Would you like to try Reverse_Number one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Reverse_Number program ."<<endl;
            break;
        }
        else
        {
            cout<<"===================================================================================================="<<endl;
            iNo = -1;
            continue;
        }
    }

    return 0;
}
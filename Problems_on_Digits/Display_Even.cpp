////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program displays the digits which are even from a number .                    //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 19th May 2025                                                                             //
//Day: Monday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<limits>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Display_Even() Function: This function displays the digits which are even from a number .       //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value display the digits from .                                            //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iDigit) : The variable to store the remainder of the original number after being divided //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Divide the number by 10 and display the digits which provides remainder 0 when divide by 2 . //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display_Even(int iValue)
{
    if(iValue < 0)
    {
        iValue = -iValue;
    }

    int iDigit = 0;

    cout<<"Digits which are even from "<<iValue<<" are : "<<endl;
    while(iValue != 0)
    {
        iDigit = iValue % 10;

        if(((iDigit % 2) == 0) && (iDigit != 0))
        {
            cout<<iDigit<<endl;
        }

        iValue = iValue / 10;
    }
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

        Display_Even(iNo);

        cout<<"Would you like to try Display_Even one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Display_Even program ."<<endl;
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
////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program displays the digits within a number .                                 //
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
//Display_Digits() Function: This function displays the digits within a number .                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value display the digits from .                                            //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iDigit) : The value to display the digits .                                              //
//2. int(iCnt)   : The variable to store the count of digits .                                    //
//3. int(iSum)   : The variable to store the summation of digits .                                //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Divide the number by 10 and display the remainder till the value becomes 0                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display_Digits(int iValue)
{
    if(iValue < 0)
    {
        iValue = -iValue;
    }

    int iDigit = 0,iCnt = 0,iSum = 0;

    cout<<"Digits from "<<iValue<<" are : "<<endl;
    while(iValue != 0)
    {
        iDigit = iValue % 10;
        cout<<iDigit<<endl;
        iValue = iValue / 10;
        iCnt++;
        iSum = iSum + iDigit;//iSum += iDigit;
    }

    cout<<"Number of digits are : "<<iCnt<<endl;
    cout<<"Summation of digits are : "<<iSum<<endl;
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

        Display_Digits(iNo);

        cout<<"Would you like to try Display_Digits one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Display_Digits program ."<<endl;
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
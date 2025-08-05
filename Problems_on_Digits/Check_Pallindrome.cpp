////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks if the value is palindrome or not .                            //
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
//Check_Palindrome() Function: This function returns true if number is palindrome .               //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value display the digits from .                                            //
//================================================================================================//
//Return: bool                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iDigit)   : variable to store remainder of number when divide by 10 .                    //
//2. int(iReverse) : variable to store the reversed number .                                      //
//3. int(iTemp)    : variable to temporaily store the main number to compare it later .           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Take the absolute value of the input number to handle negative inputs.                       //
//2. Store the original number in a temporary variable.                                           //
//3. Initialize a variable 'iReverse' to 0, which will store the reversed number.                 //
//4. Loop while the input number is greater than 0:                                               //
//   a. Get the last digit using the modulo operator (number % 10).                               //
//   b. Update 'iReverse' by multiplying it by 10 and adding the new digit.                       //
//   c. Remove the last digit from the input number using integer division (number / 10).         //
//5. After the loop, compare the reversed number with the original number (stored in temp).       //
//6. If they are equal, return true. Otherwise, return false.                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Check_Palindrome(int iValue)
{
    int iDigit = 0,iReverse = 0,iTemp = 0;

    if(iValue < 0)
    {
        iValue = -iValue;
    }

    iTemp = iValue;

    while(iValue > 0)
    {
        iDigit = iValue % 10;
        iReverse = iReverse * 10 + iDigit;
        iValue = iValue / 10;
    }

    if(iReverse == iTemp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Starting point of the program
int main()
{
    int iNo = 0;

    while(1)
    {
        cout<<"Please enter an integer value: ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter a single whole number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        bool bRet = Check_Palindrome(iNo);
        if(bRet == true)
        {
            cout<<iNo<<" is a palindrome number ."<<endl;
        }
        else
        {
            cout<<iNo<<" is not a palindrome number ."<<endl;
        }

        cout<<"Would you like to try Check_Palindrome one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Check_Palindrome program ."<<endl;
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
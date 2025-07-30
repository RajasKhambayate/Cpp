////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program performs factorial of a number .                                      //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 16th May 2025                                                                             //
//Day: Friday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//Factorial() Function: This function returns factorial of a number .                             //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value for calculating factorial .                                          //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt) : Loop counter variable .                                                          //
//2. int(iFactorial) : Variable to store factorial of a number .                                  //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize iFactorial to 1 .                                                                 //
//2. Loop from 1 to iValue .                                                                      //
//3. Multiply iFactorial with iCnt in each iteration .                                            //
//4. Return iFactorial .                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Factorial(int iValue)
{
    int iFactorial = 1;

    for(int iCnt = 1;iCnt <= iValue;iCnt++)
    {
        iFactorial = iFactorial * iCnt;
    }

    return iFactorial;
}

//Starting point of application
int main()
{
    int iNo = 0;
    int iRet = 0;

    while(1)
    {
        iNo = 0;

        while(iNo <= 0)
        {
            cout<<"Please enter a positive integer value : ";
            cin>>iNo;
        }

        iRet = Factorial(iNo);
        cout<<"Factorial of "<<iNo<<" is : "<<iRet<<endl;

        cout<<"Would you like to try Factorial one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        cin>>iNo;

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Factorial program ."<<endl;
            break;
        }
        else
        {
            cout<<"===================================================================================================="<<endl;
            continue;
        }
    }

    return 0;
}
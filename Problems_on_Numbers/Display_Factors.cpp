////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program displays factors of a number .                                        //
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
//Display_Factors() Function: This function displays factors of a number.                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value for calculating factors .                                            //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt) : Loop counter variable .                                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Loop 'iCnt' from 1 to 'iValue':                                                              //
//   a. If 'iValue' is divisible by 'iCnt', print 'iCnt'.                                         //
//2. End of loop.                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display_Factors(int iValue)
{
    cout<<"Factors of "<<iValue<<" are :"<<endl;

    for(int iCnt = 1;iCnt <= iValue/2;iCnt++)
    {
        if((iValue % iCnt) == 0)
        {
            cout<<iCnt<<endl;
        }
    }
    cout<<iValue<<endl;//Printing the number itself as it is also a factor of itself .
}

//Starting point of application
int main()
{
    int iNo = 0;

    while(1)
    {
        iNo = 0;

        while(iNo <= 0)
        {
            cout<<"Please enter a positive integer value : ";
            cin>>iNo;
        }

        Display_Factors(iNo);

        cout<<"Would you like to try Display_Factors one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        cin>>iNo;

        if(iNo == 0)
        {
            cout<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Display_Factors program ."<<endl;
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
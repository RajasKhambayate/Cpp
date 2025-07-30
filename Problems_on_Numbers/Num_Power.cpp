////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program is used for calculating a number rays to some +ve integer power .     //
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
//Num_Power() Function: This function is used to calculate the number rays to some power .        //
//================================================================================================//
//Parameters:                                                                                     //
//1. float(fValue) : The value to be powered on .                                                 //
//2. int(iPower) : The non-negative integer power value.                                          //
//================================================================================================//
//Return: float(fAns)                                                                             //
//================================================================================================//
//Local variables:                                                                                //
//1. float(fAns) : To store the answer of the power calculation .                                 //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If 'fValue' is 0, return 0 (as 0^iPower = 0).                                                //
//2. If 'iPower' is 0, return 1.0 (as fValue^0 = 1).                                              //
//3. Initialize 'fAns' to 1.0.                                                                    //
//4. Loop 'iCnt' from 0 up to 'iPower - 1':                                                       //
//   a. 'fAns = fAns * fValue'.                                                                   //
//5. Return 'fAns'.                                                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////
float Num_Power(float fValue,int iPower)
{
    if(fValue == 0)
    {
        return 0.0f;
    }

    if(iPower == 0)
    {
        return 1.0f;
    }

    float fAns = 1.0f;

    for(int iCnt = 0;iCnt < iPower;iCnt++)
    {
        fAns = fAns * fValue;
    }

    return fAns;
}


//Starting point of application
int main()
{
    float fNo = 0;
    int iPower = 0;
    float fRet = 0;

    while(1)
    {
        cout<<"Enter the value to be used for power calculation : ";
        cin>>fNo;

        do
        {
            cout<<"Enter the non-negative integer power: ";
            cin>>iPower;

            if(iPower < 0)
            {
                cout<<"Power cannot be negative. Please enter a non-negative integer power."<<endl;
            }
        }
        while(iPower < 0);

        fRet = Num_Power(fNo,iPower);
        cout<<endl<<""<<fNo<<"^"<<iPower<<" = "<<fRet<<endl;

        cout<<"Would you like to try Num_Power one more time? >Press for->YES:ANY_NUMBER OR NO:0 <=>Your Choice : ";
        cin>>fRet;

        if(fRet == 0)
        {
            cout<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Num_Power program ."<<endl;
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
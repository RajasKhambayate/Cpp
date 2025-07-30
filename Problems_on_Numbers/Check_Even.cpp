////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks weather a number is even or odd .                              //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 16th May 2025                                                                             //
//Day: Friday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>//for printf and scanf functions .
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Check_Prime() Function: This function checks weather a number is even or odd .                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value to determine even or odd .                                           //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Check if 'iValue' is even or odd using modulo operator .                                     //
//2. If 'iValue' is even, return true.                                                            //
//3. Else, return false.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Check_Even(int iValue)
{
    if((iValue % 2) == 0)
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
        cout<<"Please enter a integer value : ";
        cin>>iNo;

        if(iNo == 0)
        {
            cout<<"Zero(0) is neither even nor odd"<<endl;
            continue;
        }

        bool bRet = Check_Even(iNo);
        if(bRet == true)
        {
            cout<<iNo<<" : It is even number"<<endl;
        }
        else
        {
            cout<<iNo<<" : It is odd number"<<endl;
        }


        cout<<"Would you like to try Check_Even one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        cin>>iNo;

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Check_Even program ."<<endl;
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
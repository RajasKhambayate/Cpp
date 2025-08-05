////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks weather a number is perfect or not .                           //
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
#include<limits>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Check_Perfect() Function: This function checks weather a number is perfect or not .             //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value to determine even or odd .                                           //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt)       : The value used for iteration and also for checking factors                 //
//2. int(iSummation) : The value to check whether number is perfect or not                        //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Check if 'iValue' is perfect or not by adding all its factors except itself                  //
//2. If 'iSummation' is equal to iValue, return true.                                             //
//3. Else, return false.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Check_Perfect(int iValue)
{
    int iCnt = 0,iSummation = 0;

    for(iCnt = (iValue / 2);((iCnt >= 1) && (iSummation <= iValue));iCnt--)
    {
        if((iValue % iCnt) == 0)
        {
            iSummation = iSummation + iCnt;
        }
    }

    if(iSummation == iValue)
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
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter a single whole number : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if((iNo == 0) || (iNo == 1))
        {
            cout<<"Zero(0) and One(1) are not perfect ."<<endl;
            continue;
        }
        if(iNo < 0)
        {
            iNo = -iNo;
        }

        bool bRet = Check_Perfect(iNo);
        if(bRet == true)
        {
            cout<<iNo<<" : It is perfect number"<<endl;
        }
        else
        {
            cout<<iNo<<" : It is not a perfect number"<<endl;
        }


        cout<<"Would you like to try Check_Perfect one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Check_Perfect program ."<<endl;
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
////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks weather a number is prime or composite .                       //
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
//Check_Prime() Function: This function determines whether number is prime or composite .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value to determine prime or composite .                                    //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iFact) : To count the number of factors of 'iValue' .                                    //
//2. int(iCnt) : Loop counter variable .                                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize 'iFact' to 0.                                                                     //
//2. Loop 'iCnt' from 1 to 'iValue/2':                                                            //
//   a. If 'iValue' is divisible by 'iCnt', increment 'iFact'.                                    //
//3. End of loop.                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Check_Prime(int iValue)
{
    if((iValue == 0) || (iValue == 1))
    {
        return false;
    }

    int iFact = 0;

    for(int iCnt = 1;iCnt <= iValue/2;iCnt++)
    {
        if((iValue % iCnt) == 0)
        {
            iFact++;
        }
    }

    if(iFact == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Starting point of application
int main()
{
    int iNo = -1;

    while(1)
    {
        while(iNo < 0)
        {
            cout<<endl<<"Please enter a positive integer value : ";
            while((!(cin>>iNo)) || (cin.peek() != '\n'))
            {
                cout<<"Invalid input. Please enter a single whole number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }

            if(iNo < 0)
            {
                continue;
            }
        }

        if(iNo == 0 || iNo == 1)
        {
            cout<<"0 and 1 are neither prime nor composite numbers ."<<endl;
            cout<<"===================================================================================================="<<endl;

            iNo = -1;

            continue;
        }

        bool bRet = Check_Prime(iNo);
        if(bRet == true)
        {
            cout<<endl<<iNo<<" : It is prime number"<<endl;
        }
        else
        {
            cout<<endl<<iNo<<" : It is composite number"<<endl;
        }

        cout<<"Would you like to try Check_Prime one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ";
        while((!(cin>>iNo)) || (cin.peek() != '\n'))
        {
            cout<<"Invalid input. Please enter 0 or 1 : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(iNo == 0)
        {
            cout<<endl<<"===================================================================================================="<<endl;
            cout<<"Thank you for using Rajas's Check_Prime program ."<<endl;
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
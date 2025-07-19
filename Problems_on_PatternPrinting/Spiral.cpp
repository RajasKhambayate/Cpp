#include<iostream>
using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////
//Concentric_Numeric_Square_Pattern() Function: Forms a pattern which looks like Square Diamond . //
//================================================================================================//
//Parameters:                                                                                     //
//1. int : The value for determining the length of Spiral                                         //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : integer to display the pattern .                                                       //
//2. int : integer to display the pattern .                                                       //
//3. int : integer to display the pattern .                                                       //
//4. int : integer to display the pattern .                                                       //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Concentric_Numeric_Square_Pattern(int iValue)
{
    int int_i = 0,int_j = 0;

    int int_x = 0,int_y = 0;

    for(int_i = 1;int_i <= ((2 * iValue) - 1);int_i++)
    {
        for(int_j = 1;int_j <= ((2 * iValue) - 1);int_j++)
        {
            if(int_i <= iValue)
            {
                int_x = int_i;
            }
            else
            {
                int_x = 2 * iValue - int_i;
            }


            if(int_j <= iValue)
            {
               int_y = int_j;
            }
            else
            {
               int_y = 2 * iValue - int_j;
            }


            if(int_x < int_y)
            {
                cout<<int_x<<"\t";
            }
            else
            {
                cout<<int_y<<"\t";
            }
        }

        cout<<endl;
    }

}

int main()
{
    int iNo = 0;

    cout<<"Enter a number : "<<" ";
    cin>>iNo;

    Concentric_Numeric_Square_Pattern(iNo);

    return 0;
}

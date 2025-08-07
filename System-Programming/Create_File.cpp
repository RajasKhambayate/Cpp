////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program creates file using creat system call .                                //
//================================================================================================//
//Language: C++                                                                                   //
//Compiler : GNU G++                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 07th August 2025                                                                          //
//Day: Thursday                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<fcntl.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//Creat_File() Function: This function creates file using creat system call and returns FD .      //
//================================================================================================//
//Parameters:                                                                                     //
//1. char *(argv) : The string as input for File_Name .                                           //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iFile_Descriptor)   : variable to store File_Descriptor of created file .                //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Create File using create() system call .                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Create_File(char *argv)
{
    int File_Descriptor = 0;

    File_Descriptor = creat(argv,0777);// All permissions for everyone

    return File_Descriptor;
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        cerr<<"!!Invalid number of Arguments , seems like you forgot to mention File_Name as argument!!"<<endl;
        cout<<"Create Application  : g++ Create_File.cpp -o creat"<<endl;
        cout<<"Usage               : ./creat File_Name"<<endl;
        return -1;
    }

    int iRet = Create_File(argv[1]);

    if(iRet == -1)
    {
        perror("Unable to Create File ");
        return -1;
    }
    else
    {
        cout<<"File is successfully created with File_Descriptor : "<<iRet<<endl;
        close(iRet);
    }

    return 0;
}
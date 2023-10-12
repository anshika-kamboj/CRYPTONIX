#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "steg.cpp"
#include "clue.cpp"
#include "strength.cpp"
#include "ciphers.cpp"

using namespace std;

int main()
{

    cout<<"\n#############################################"<<endl;
    cout<<"########## CryptoniX ########################"<<endl;
    cout<<"#############################################"<<endl;
    
    cout<<flush;
    system("color 7");

    int choice;

    home:
    cout<<"\nWelcome to the CryptoniX!\n!"<<endl
    <<"Please Select Option of Your Interest:\n "<<endl
    <<"1. Cryptic Clue Solver"<<endl
    <<"            OR                     "<<endl
    <<"2. Text Steganography"<<endl
    <<"            OR                     "<<endl
    <<"3. Ciphers"<<endl
    <<"            OR                     "<<endl
    <<"4. Password/Word Strength Checker"<<endl
    <<"            OR                     "<<endl
    <<"5. Exit"<<endl<<endl;

    choose: cout<<"Enter your choice code: ";
    cin>>choice;

    switch(choice){
        case 1: 
            getchar();
            solver();
            getch();
            goto home;
        case 2:
            getchar();
            stega();
            getch();
            goto home;
        case 3:
            getchar();
            ciphers();
            getch();
            goto home;
        case 4:
            getchar();
            sth_chk();
            getch();
            goto home;
        case 5:
            break;
    }

    cout<<"Thank YOU for using CryptoniX!!"<<endl<<endl;
    getch();

    return 0;
}
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
void gotoxy (int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class id{
    char user[20];
    char pass[20];
    public:
        int ptr;
        char msg[10][100];
        int unread_count;
        id ()
        {
            unread_count=0;
            ptr=0;
        }
        
        char name[20];
        void create()
        {
            cout<<"Enter your name: (without spaces) ";
            gets(name);
            cout<<"Enter id: ";
            cin>>user;
            cout<<"Enter pass: ";
            cin>>pass;
        }
        

        int check_msg()
        {
            if (unread_count)
                return unread_count;
            else
                return 0;
        } 
        char* get_id ()
        {
            return user;
        }
        
        char* get_pass ()
        {
            return pass;
        }
    };
    

    
    
    
        
        
        
        

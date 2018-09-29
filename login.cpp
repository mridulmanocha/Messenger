#include "id_class.cpp"
#include <string.h>
#include <process.h>

void msg_open(id &user, int a)
{
            system("cls");
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            for(int j=0; j<20; j++)
            {
                cout<<"*";
                for (int i=0; i<68; i++)
                    cout<<" ";
                cout<<"*"<<endl;
            }
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            
            gotoxy(25,5);
            cout<<user.msg[a];
}

void message(id &user)
{
            system("cls");
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            for(int j=0; j<20; j++)
            {
                cout<<"*";
                for (int i=0; i<68; i++)
                    cout<<" ";
                cout<<"*"<<endl;
            }
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            gotoxy(25,2);
            cout<<"Welcome "<<user.name<<" to your inbox";
            int i, j;
            for (i=0, j=5; i<user.ptr; i++, j+=2)
            {    
                gotoxy(25,j);
                cout<<i+1<<". "<<user.msg[i];
            }
            user.unread_count=0;
            int choice;
            gotoxy(25,j);
            cout<<"Enter choice: ";
            cin>>choice;
            if (choice>user.ptr)
            message(user);
            msg_open(user, choice-1);
}

void send(id &sender)
{
            system("cls");
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            for(int j=0; j<20; j++)
            {
                cout<<"*";
                for (int i=0; i<68; i++)
                    cout<<" ";
                cout<<"*"<<endl;
            }
            for (int i=0; i<70; i++)
                cout<<"*";
            cout<<endl;
            gotoxy(25,2);
            cout<<"Send a message";
            gotoxy(25,7);
            cout<<"User: ";
            char user[20];
            cin.ignore();
            gets(user);
            gotoxy(25,9);
            char m[100];
            cout<<"Write your message: ($ to end) ";
            cin.getline(m, 100, '$');
            
            id temp;
            fstream f("data.dat", ios::binary|ios::in|ios::out);
            while (!f.eof())
            {
            	
                cout<<"done";
                int l=f.tellg();
                f.read((char*)&temp, sizeof(temp));
                if (!strcmp(user,temp.get_id()))
                {
                    temp.unread_count++;
                    for(int j=0; m[j]!='\0'; j++)
                    {
                        temp.msg[temp.ptr][j]=m[j];
                    }
					if(temp.ptr<10)   
                    	temp.ptr++;
                    else
                    	temp.ptr=0;
                    f.seekp(l);
                    f.write((char*)&temp, sizeof(temp));
                }
            }
            f.close();
}

void open(id &user)
{
    system("cls");
    for (int i=0; i<70; i++)
        cout<<"*";
    cout<<endl;
    for(int j=0; j<20; j++)
    {
        cout<<"*";
        for (int i=0; i<68; i++)
            cout<<" ";
        cout<<"*"<<endl;
    }
    for (int i=0; i<70; i++)
        cout<<"*";
    cout<<endl;
    
    gotoxy(25,2);
    cout<<"Welcome "<<user.name<<" to Friendsbook";
    
    gotoxy(25,9);
    cout<<"1. Send Messages";
    gotoxy(25,11);
    cout<<"2. Inbox ("<<user.unread_count<<")";
    
    int choice;
    gotoxy(25,13);
    cout<<"Enter choice: ";
    cin>>choice;
    
    if (choice==1)
        send(user);
            
    else if (choice==2)
        message(user);
}



    

int main()
{
    system("cls");
    for (int i=0; i<70; i++)
        cout<<"*";
    cout<<endl;
    for(int j=0; j<20; j++)
    {
        cout<<"*";
        for (int i=0; i<68; i++)
            cout<<" ";
        cout<<"*"<<endl;
    }
    for (int i=0; i<70; i++)
        cout<<"*";
    cout<<endl;
    
    gotoxy(25,2);
    cout<<"Welcome to login page";
    
    gotoxy(25,9);
    cout<<"User: ";
    gotoxy(25,11);
    cout<<"Password: ";
    char user[20], pass[20];
    gotoxy(32,9);
    gets(user);
    gotoxy(35,11);
    gets(pass);
    
    id temp;
    ifstream fin("data.dat", ios::binary);
    while (!fin.eof())
    {
        fin.read((char*)&temp, sizeof(temp));
        if (!strcmp(user,temp.get_id()))
        {
            if (!strcmp(pass,temp.get_pass()))
                break;
            else 
                cout<<"Wrong Id or Password";
            getch();
            exit(1);
        }
    }
    open (temp);
    
    
    getch();
    return 0;
}
    

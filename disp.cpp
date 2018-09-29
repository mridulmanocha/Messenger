#include "id_class.cpp"
using namespace std;

void disp(id &user)
{
    cout<<"user: "<<user.get_id();
    cout<<"pass: "<<user.get_pass();
    cout<<"ptr: "<<user.ptr;
    getch();
}

int main()
{
    id temp;
    fstream file ("data.dat", ios::binary|ios::out|ios::app);
    while (!file.eof())
    {
        file.read((char*)&temp, sizeof(temp));
        disp(temp);
    }
    file.close();
    
    getch();
    return 0;
}

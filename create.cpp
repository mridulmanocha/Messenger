#include "id_class.cpp"
using namespace std;

int main()
{
    id temp;
    temp.create();
    fstream file ("data.dat",ios::binary|ios::out|ios::app);
    file.write((char*)&temp, sizeof(temp));
    file.close();
    
    getch();
    return 0;
}

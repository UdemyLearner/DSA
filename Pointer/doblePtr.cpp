#include <iostream>
using namespace std;
int main()
{
    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout<< "Memory Location of i "<<&i<<endl;
    cout << "Pointing of Pointer p1 ->" << p1 << endl;
    cout << "Pointing of Pointer p2 ->" << p2 << endl;

    //cout << "value at p1 ->" << *p1 << endl;
    cout << "value at p2 ->" << *p2 << endl;

    
    cout << "Address of p1 ->" << &p1 << endl;
    cout << "Address of p2 ->" << &p2 << endl;

    cout <<"Values at "<< i << endl
         << *p1 << endl
         << **p2 << endl;

    
    

    return 0;
}

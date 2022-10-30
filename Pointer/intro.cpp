#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num = 5;
    cout << "Value of num variable is " << num << endl;
    cout << "Address of num Variable " << &num << endl;

    int *p = &num;
    cout << "Address to which pointer p is pointing to is " << p << endl
         << " value of pointer p which variable it is pointing to " << *p;

    return 0;
}

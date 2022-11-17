#include "iostream"
using namespace std;

void update(int n)
{
    n++;
}

void updateRef(int &n)
{
    n++;
}

int main(int argc, char const *argv[])
{
    int i = 5;
    int &j = i; // J is refrence varibale of I
    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << i << endl;

    cout << "Memory of i " << &i << endl
         << "Memory of i " << &j << endl;

    cout << "before update() -> " << i << endl;
    update(i);
    cout << "after  update() -> " << i << endl;
    cout << "-------------------------------" << endl;
    cout << "before updateRef() -> " << i << endl;
    updateRef(i);
    cout << " after updateRef() -> " << i << endl;

    return 0;
}

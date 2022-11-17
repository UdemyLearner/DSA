#include <iostream>
using namespace std;

void update(int **p2)
{
     // p2 = p2 + 1;// no change
     //*p2 = *p2 + 1;// change hoga
     **p2 = **p2 + 1; // change hoga
}

int main()
{
     int i = 5;
     int *p1 = &i;
     int **p2 = &p1;

     cout << "Memory Location of i " << &i << endl;
     cout << "Pointing of Pointer p1 ->" << p1 << endl;
     cout << "Pointing of Pointer p2 ->" << p2 << endl;

     // cout << "value at p1 ->" << *p1 << endl;
     cout << "value at p2 ->" << *p2 << endl;

     cout << "Address of p1 ->" << &p1 << endl;
     cout << "Address of p2 ->" << &p2 << endl;

     cout << "Values at i " << i << endl
          << "p1 " << *p1 << endl
          << "p2 " << **p2 << endl;

     cout << "Before" << i << endl
          << p1 << endl
          << p2 << endl;
     update(p2);
     cout << "After " << i << endl
          << p1 << endl
          << p2 << endl;

     return 0;
}

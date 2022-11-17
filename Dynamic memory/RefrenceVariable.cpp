#include "iostream"
using namespace std;

void update(int n)      //Pass by Value
{                       // Copy of i is created and stored in n varable 
    n++;                // alag sa meory create hogi hor n variable
}

void updateRef(int &n)  //Pass by Refrence
{                       // &n is same memory block as i variable
    n++;                // alag sa koi memory block nahi use hoga
}

int& func(int a){
    int num = a;
    int &ans = num;
    return ans;
} // func(n); <- Gives Warning as after func(n) call all the variable defined in code block of func(n) will be cleared as they are local variable 

int* fun(int n) {
    int* ptr = &n;
    return ptr;
} // fun(n); <- Gives Warning as after func(n) call all the variable defined in code block of func(n) will be cleared as they are local variable 

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

    // func(n); <- Gives Warning as after func(n) call all the variable drfined in code block of func(n) will be cleared as they are local variable 
    // fun(n); <- Gives Warning as after func(n) call all the variable drfined in code block of fun(n) will be cleared as they are local variable 

    return 0;
}

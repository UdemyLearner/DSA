#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
// /*
    int arr[5] = {1,2,3,4,5};
    char ch[6]= "abcde"; 

    cout<<arr<<endl;
    cout<<ch<<endl; //will print whole string

    char *c = &ch[0];
    cout<<c<<endl; //will print whole string
// */

    char temp = 'z';
    char *p = &temp;

    cout<<p<<endl;

    return 0;
}

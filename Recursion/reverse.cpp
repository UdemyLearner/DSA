#include <iostream>
using namespace std;
void reverse(string &str, int i, int j) // pass by refrence
{
    cout << "call recived for " << str << endl;
    // Base case
    if (i > j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;
    // recusive call
    reverse(str, i, j);
}
void reverse1(string &str, int i, int j) // pass by refrence
{
    cout << "call recived for " << str << endl;
    // Base case
    if (i > j-i)
    {
        return;
    }
    swap(str[i], str[j-i]);
    i++;
    reverse1(str, i,j);
    
}
int main(int argc, char const *argv[])
{
    string str = "naredi";
    reverse1(str, 0, str.length() - 1);
    cout << str << endl;
    reverse(str, 0, str.length() - 1);
    cout << str << endl;
    return 0;
}

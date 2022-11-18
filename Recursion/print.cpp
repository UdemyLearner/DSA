#include "iostream"
using namespace std;
void print(int n){
    if (n == 0) 
        return ;
    cout<<n<<endl;
    print(n-1);    
}
void printHead(int n){
    if (n == 0) 
        return ;
    
    print(n-1);    
    cout<<n<<endl;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    printHead(n);
    cout<<endl;
    print(n);
    return 0;
}

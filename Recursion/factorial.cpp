#include <iostream>
using namespace std;

int fact(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    cout << n << endl;
    return n * fact(n - 1);
    /*
    int x = fact(n - 1);
    int y = n * x;
    return y;
    */
}

int main()
{
    int n;
    cin >> n;
    int ans = fact(n);
    cout << "Factorial is = " << ans << endl;
    return 0;
}
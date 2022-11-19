#include <iostream>
using namespace std;

int power(int a, int b)
{
    // base case
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    // recursive case
    int ans = power(a, b / 2);
    // if b is even then a^b/2 * a^b/2
    // if b is odd then a * a^b/2 * a^b/2
    if (b % 2 == 0)
        return ans * ans;
    else
        return ans * ans * a;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int ans = power(a, b);
    cout << ans << "\n";
    return 0;
}

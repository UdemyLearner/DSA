#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    // base case
    if (n == 0)
        return;
    // base case
    int digit = n % 10;  // last digit
    n = n / 10;          // reamaning digit after last digit is removed
    sayDigit(n, arr);
    cout << arr[digit] << " ";

}

int main(int argc, char const *argv[])
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin >> n;
    sayDigit(n, arr);
    return 0;
}

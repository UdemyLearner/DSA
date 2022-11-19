#include "iostream"

using namespace std;

bool checkPalindrome(string str, int i, int j)
{
    // base case
    if (i > j)
        return true;
    if (str[i] != str[j])
        return false;
    else
        // recursive call
        return checkPalindrome(str, i + 1, j - 1);
}

int main(int argc, char const *argv[])
{
    string str = "abccbas";
    bool isPalindrome = checkPalindrome(str, 0, str.length() - 1);
    if (isPalindrome)
        cout << "is Palindrome";
    else
        cout << "not Palindrome";
    return 0;
}

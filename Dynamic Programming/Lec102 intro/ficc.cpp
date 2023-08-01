#include <bits/stdc++.h>
using namespace std;

int fib_Recursion(int n)
{
    // base case
    if (n <= 1)
        return n;

    return fib_Recursion(n - 1) + fib_Recursion(n - 2);
}

int fib_TD(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib_TD(n - 1, dp) + fib_TD(n - 2, dp);
    return dp[n];
}
//iterative DP approch
int fib_BU(int n){
    vector<int> dp(n+1);
    dp[1]=1;
    dp[0]=0;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib_SO(int n){
    int prev1 = 1;
    int prev2 = 0;
    for (size_t i = 2; i <=n; i++)
    {
        int curr = prev1 + prev2;
        // shifting prev
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << "Using Recursion  " << fib_Recursion(n) << endl;
    cout << "Using DP :\n1. Top-Down => recusion + memoization : " << fib_TD(n, dp) << endl
         << "2. Bottom-Up => tabular : " << fib_BU(n) << endl
         << "3. Space Optimization =>  : " << fib_SO(n) << endl
         << endl;
}
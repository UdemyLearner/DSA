#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);
        return;
    }
    solve(str, output, index + 1, ans);
    // include
    char elem = str[index];
    output.push_back(elem);
    solve(str, output, index + 1, ans);
}

int main()
{
    string str = "abc";
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
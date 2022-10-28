// https://leetcode.com/problems/permutation-in-string/
#include <bits/stdc++.h>
using namespace std;
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }

    return 1;
}

bool checkInclusion(string s1, string s2)
{

    // S1 sa har alphabet ki occurence nikal li kitne baar repeat hua ha vo aur save kar liya in count1
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    // traverse S2 string in window of size of s1 length and compare
    // aur sath hi m check kar liya ki kahi S2 , S1 sa choti tu nahi ha na

    // running for 1st window
    int i = 0;
    int count2[26] = {0};
    int window = s1.length();

    while (i < window && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // check kar le ki kya pata ki count1 aur count 2 equal ho gaye ho
    if (checkEqual(count1, count2))
        return 1;
    // move in the size of window of size of s1

    // aage window process kiya
    while (i < s2.length())
    {
        char ch = s2[i];
        int index = ch - 'a';
        count2[index]++;
        char oldch = s2[i - window];
        index = oldch - 'a';
        count2[index]--;
        i++;
        if (checkEqual(count1, count2))
            return 1;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<< checkInclusion(s1,s2);

    return 0;
}

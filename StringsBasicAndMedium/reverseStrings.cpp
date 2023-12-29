#include <bits/stdc++.h>
using namespace std;

string reverseString(string &str)
{
    string result;

    int i = 0;

    int n = str.length();

    while (i < n)
    {
        while (i < n && str[i] == ' ')
            i++;
        if (i >= n)
            break;

        int j = i + 1;

        while (j < n && str[j] != ' ')
        {
            j++;
        }

        string word = str.substr(i, j - i);

        if (result.size() == 0)
            result = word;
        else
        {
            result = word + " " + result;
        }

        i = j + 1;
    }
    return result;
}
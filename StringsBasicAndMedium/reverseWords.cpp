#include <bits/stdc++.h>
using namespace std;

string revWords(string s)
{

    string result;

    int i = 0;

    int n = s.length();

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            break;

        int j = i + 1;

        while (j < n && s[j] != ' ')
            j++;

        string word = s.substr(i, j - i);

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
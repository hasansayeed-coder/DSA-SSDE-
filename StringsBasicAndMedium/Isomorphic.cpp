#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string &str1, string &str2)
{
    int size1 = str1.size();
    int size2 = str2.size();

    if (size1 != size2)
        return false;

    unordered_map<char, char> mpp1;
    unordered_map<char, char> mpp2;

    for (int i = 0; i < size1; i++)
    {
        if (mpp1.find(str1[i]) != mpp1.end())
        {
            if (mpp1[str1[i]] != str2[i])
                return false;
        }

        else
        {
            mpp1[str1[i]] = str2[i];
        }

        if (mpp2.find(str2[i]) != mpp2.end())
        {
            if (mpp2[str2[i]] != str1[i])
                return false;
        }

        else
        {
            mpp2[str2[i]] = str1[i];
        }
    }

    return true;
}
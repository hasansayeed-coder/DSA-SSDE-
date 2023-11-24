#include <bits/stdc++.h>
using namespace std;

vector<int> twoOddNum(vector<int> arr)
{

    int n = arr.size();
    int wholeXoredValue = 0;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        wholeXoredValue ^= arr[i];
    }

    int firstSetBit = 0;

    for (int i = 0; i < 32; i++)
    {
        int currentValue = (1 << i);
        if ((wholeXoredValue & currentValue) != 0)
        {
            firstSetBit = currentValue;
            break;
        }
    }

    vector<int> sortedSet;
    vector<int> sortedNoSet;

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & firstSetBit) != 0)
        {
            sortedSet.push_back(arr[i]);
        }

        else
        {
            sortedNoSet.push_back(arr[i]);
        }
    }

    int first = 0;
    int second = 0;

    for (int i = 0; i < sortedSet.size(); i++)
    {
        first = first ^ sortedSet[i];
    }

    for (int i = 0; i < sortedNoSet.size(); i++)
    {
        second = second ^ sortedNoSet[i];
    }

    if (first > second)
    {
        ans.push_back(first);
        ans.push_back(second);
    }

    else
    {
        ans.push_back(second);
        ans.push_back(first);
    }

    return ans;
}
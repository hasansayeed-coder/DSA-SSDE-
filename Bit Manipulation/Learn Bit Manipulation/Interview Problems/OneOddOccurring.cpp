#include <bits/stdc++.h>
using namespace std;

int missingNumber(int n, vector<int> &arr)
{

    int missingNumber = 0;

    for (int i = 0; i < n; i++)
    {
        missingNumber = missingNumber ^ arr[i];
    }

    return missingNumber;
}
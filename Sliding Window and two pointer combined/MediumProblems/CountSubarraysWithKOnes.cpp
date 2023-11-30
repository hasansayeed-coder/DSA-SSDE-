#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int k)
{

    int l = 0, count = 0, total = 0;

    for (int r = 0; r < arr.size(); r++)
    {

        if (arr[r] == 1)
            count++;

        while (count > k)
        {
            if (arr[l] == 1)
                count--;
            l++;
        }

        total = total + (r - l + 1);
    }

    return total;
}

int subarrayWithSum(vector<int> &arr, int k)
{
    return solve(arr, k) - solve(arr, k - 1);
}
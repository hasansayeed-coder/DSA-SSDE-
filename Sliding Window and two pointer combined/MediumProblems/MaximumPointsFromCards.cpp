#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int> &arr, int K)
{

    int l = 0;
    int r = arr.size() - K;

    int sum = 0;

    for (int i = r; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    int total = sum;

    while (r < arr.size())
    {
        total = total + arr[l] - arr[r];
        sum = max(sum, total);
        l++;
        r++;
    }

    return sum;
}
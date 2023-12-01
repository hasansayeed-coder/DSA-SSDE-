#include <bits/stdc++.h>
using namespace std;

vector<int> MinimumCoins(int n)
{
    int arr[9] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> ans;

    for (int i = 8; i >= 0; i--)
    {
        while (n >= arr[i])
        {
            n = n - arr[i];
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
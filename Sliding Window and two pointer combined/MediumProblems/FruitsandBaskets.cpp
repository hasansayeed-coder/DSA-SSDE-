#include <bits/stdc++.h>
using namespace std;

int findMaxFruits(vector<int> &arr, int n)
{

    int i = 0;
    int j = 0;
    int len = 0;
    unordered_map<int, int> count;

    while (j < n)
    {
        count[arr[j]]++;

        while (count.size() > 2)
        {
            count[arr[i]]--;

            if (count[arr[i]] == 0)
            {
                count.erase(arr[i]);
            }
            i++;
        }

        len = max(len, j - i + 1);
        j++;
    }
    return len;
}
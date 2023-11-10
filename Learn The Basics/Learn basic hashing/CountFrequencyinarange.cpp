#include <bits/stdc++.h>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums)
{

    vector<int> freq(n, 0);

    for (int i = 0; i < n; i++)
    {
        int number = nums[i];
        freq[number - 1]++;
    }

    return freq;
}
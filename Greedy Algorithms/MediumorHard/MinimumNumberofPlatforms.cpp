#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int arrival[], int departure[], int n)
{

    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int platform = 1;
    int result = 1;

    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            platform++;
            i++;
        }

        else if (arrival[i] > departure[j])
        {
            platform--;
            j++;
        }

        result = max(result, platform);
    }

    return result;
}
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int mini = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
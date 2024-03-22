#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{

    for (int i = n - 1; i >= 0; i--)
    {
        bool didSwap = false;

        for (int j = 0; j <= i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = true;
            }
        }

        if (didSwap == false)
            break;
    }
}
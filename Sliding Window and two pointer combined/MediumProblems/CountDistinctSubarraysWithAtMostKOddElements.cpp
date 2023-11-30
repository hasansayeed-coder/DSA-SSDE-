#include <bits/stdc++.h>
using namespace std;

int SubKOdds(vector<int> &arr, int k)

{

    int j = 0;

    int oddcnt = 0;

    int totalcnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] % 2 != 0)
        {

            oddcnt++;
        }

        while (oddcnt > k)
        {

            if (arr[j] % 2 != 0)
            {

                oddcnt--;
            }

            j++;
        }

        totalcnt += i - j + 1;
    }

    return totalcnt;
}

int distinctSubKOdds(vector<int> &arr, int k)

{

    int a = SubKOdds(arr, k);

    int b = SubKOdds(arr, k - 1);

    return a - b;
}

/*
int distinctSubKOdds(vector<int> &arr, int k)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & 1)
        {
            arr[i] = 1;
        }

        else
        {
            arr[i] = 0;
        }
    }

    int sum = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];

        if (sum == k)
            cnt++;

        if (mpp.find(sum - k) != mpp.end())
        {
            cnt = cnt + mpp[sum - k];
        }

        mpp[sum]++;
    }

    return cnt;
}

*/
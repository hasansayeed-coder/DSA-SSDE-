#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &boards, int mid)
{
    int n = boards.size();
    int partitions = 1;
    long long subArraySum = 0;

    for (int i = 0; i < n; i++)
    {
        if (subArraySum + boards[i] <= mid)
        {
            subArraySum += boards[i];
        }
        else
        {
            partitions++;
            subArraySum = boards[i];
        }
    }

    return partitions;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();

    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partitions = countPartitions(boards, mid);

        if (partitions > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}
// not getting accepting

#include <bits/stdc++.h>
using namespace std;

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{

    int n = a.size();
    int m = b.size();

    int len = n + m;

    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            if (left < n && right >= n)
            {
                if (a[left] > b[right - n])
                {
                    swap(a[left], b[right - n]);
                }
            }

            else if (left >= n)
            {
                if (b[left - n] > b[right - n])
                {
                    swap(b[left - n], b[right - n]);
                }
            }

            else
            {
                swap(a[left], a[right]);
            }

            right++;
            left++;
        }

        if (gap == 1)
            break;

        gap = (gap / 2) + (gap % 2);
    }
}
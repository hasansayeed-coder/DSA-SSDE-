#include <bits/stdc++.h>
using namespace std;

void reverse(int i, int n, vector<int> &nums)
{
    if (i >= (n / 2))
        return;

    swap(nums[i], nums[n - 1 - i]);
    reverse(i + 1, n, nums);
}

vector<int> reverseArray(int n, vector<int> &nums)
{

    reverse(0, n, nums);
    return nums;
}

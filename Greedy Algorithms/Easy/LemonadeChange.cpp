#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bill)
{

    int cnt5 = 0, cnt10 = 0;

    int n = bill.size();

    for (int i = 0; i < n; i++)
    {
        if (bill[i] == 5)
        {
            cnt5++;
        }

        else if (bill[i] == 10)
        {
            cnt5--;
            cnt10++;
        }

        else
        {
            cnt5--;
            cnt10--;
        }
    }

    if (cnt5 < 0)
        return false;
    if (cnt5 < 0 && cnt10 < 0)
        return false;

    return true;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> bitManipulation(int num, int i)
{

    i = i - 1;

    vector<int> ans;

    if ((num & (1 << i)) == (1 << i))
        ans.push_back(1);
    else
        ans.push_back(0);

    ans.push_back(num | (1 << i));
    ans.push_back(num & ~(1 << i));

    return ans;
}
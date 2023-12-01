#include <bits/stdc++.h>
using namespace std;

int requiredCandies(vector<int> &students)
{

    int n = students.size();

    vector<int> candies(n, 1);

    for (int i = n - 2; i >= 0; i--)
    {
        if (students[i] > students[i + 1])
        {
            candies[i] = candies[i + 1] + 1;
        }
    }

    int total_candies = candies[0];

    for (int i = 1; i < n; i++)
    {
        if (students[i] > students[i - 1] && candies[i] <= candies[i - 1])
        {
            candies[i] = 1 + candies[i - 1];
        }

        total_candies = total_candies + candies[i];
    }

    return total_candies;
}

/*

int requiredCandies(vector<int> &students)
{

    int n = students.size();

    vector<int> l(n, 1), r(n, 1);

    for (int i = 0; i < n - 1; i++)
    {
        if (students[i] < students[i + 1])
            l[i + 1] = l[i] + 1;
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (students[i - 1] > students[i])
            r[i - 1] = r[i] + 1;
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + max(l[i], r[i]);
    }

    return total;
}

*/
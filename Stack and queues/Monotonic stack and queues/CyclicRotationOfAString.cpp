#include <bits/stdc++.h>
using namespace std;

int isCyclicRotation(string &s, string &goal)
{
    queue<char> q1, q2;

    if (s.size() != goal.size())
        return false;

    for (int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
    }

    for (int i = 0; i < goal.size(); i++)
    {
        q2.push(goal[i]);
    }

    int k = goal.size() - 1;

    while (k != 0)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        if (q1 == q2)
        {
            return 1;
        }

        k--;
    }

    return 0;
}
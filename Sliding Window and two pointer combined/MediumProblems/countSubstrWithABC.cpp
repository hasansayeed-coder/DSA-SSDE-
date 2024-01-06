#include <bits/stdc++.h>
using namespace std;

int countSubstring(string s)
{

    int i = 0;
    int j = 0;

    int a = 0;
    int b = 0;
    int c = 0;

    int ans = 0;

    int n = s.length();

    while (j < n)
    {
        if (s[j] == 'a')
            a++;
        else if (s[j] == 'b')
            b++;
        else if (s[j] == 'c')
            c++;

        while (a > 0 && b > 0 && c > 0)
        {
            if (s[i] == 'a')
                a--;
            else if (s[i] == 'b')
                b--;
            else if (s[i] == 'c')
                c--;
            i++;
        }

        ans += (j - i + 1);
        j++;
    }

    int x = (n) * (n + 1) / 2;

    return x - ans;
}
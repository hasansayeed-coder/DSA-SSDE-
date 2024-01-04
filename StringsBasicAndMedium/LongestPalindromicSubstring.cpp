#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {

        if (s.length() <= 1)
            return s;
        int max_len = INT_MIN;

        int n = s.length();

        int st = 0, end = 0;

        // odd length

        for (int i = 0; i < n - 1; i++)
        {
            int l = i;
            int r = i;

            while (l >= 0 && r < n)
            {
                if (s[l] == s[r])
                {
                    l--;
                    r++;
                }

                else
                {
                    break;
                }
            }

            int len = r - l - 1;
            if (len > max_len)
            {
                max_len = len;
                st = l + 1;
                end = r - 1;
            }
        }

        // evevn length

        for (int i = 0; i < n - 1; i++)
        {
            int l = i;
            int r = i + 1;

            while (l >= 0 && r < n)
            {
                if (s[l] == s[r])
                {
                    l--;
                    r++;
                }

                else
                {
                    break;
                }
            }

            int len = r - l - 1;

            if (len > max_len)
            {
                max_len = len;
                st = l + 1;
                end = r - 1;
            }
        }

        return s.substr(st, max_len);
    }
};
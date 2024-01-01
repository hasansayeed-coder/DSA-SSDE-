#include <bits/stdc++.h>
using namespace std;

long long mod = 101103107109113;
long long BASE = 397;

long long getHash(string str)
{

    long long head = 1;

    for (auto it : str)
    {
        head = (BASE + it) * head;

        if (head > mod)
            head = head % mod;
    }

    return head;
}

bool isAnagram(string str1, string str2)
{

    if (str1.size() != str2.size())
        return false;

    if (getHash(str1) == getHash(str2))
        return true;

    return false;
}
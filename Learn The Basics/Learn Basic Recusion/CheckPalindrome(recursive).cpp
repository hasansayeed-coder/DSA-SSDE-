#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, int n, string &str)
{
    if (i >= (n / 2))
        return true;
    if (str[i] != str[n - i - 1])
        return false;

    return palindrome(i + 1, n, str);
}

bool isPalindrome(string &str)
{

    int n = str.length();

    bool response = palindrome(0, n, str);

    return response;
}

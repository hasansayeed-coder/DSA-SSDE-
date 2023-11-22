#include <bits/stdc++.h>
using namespace std;

int divideTwoInteger(int dividend, int divisor)
{

    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

    int times = 0;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor)
    {
        dividend = dividend - divisor;
        times++;
    }

    return times * sign;
}

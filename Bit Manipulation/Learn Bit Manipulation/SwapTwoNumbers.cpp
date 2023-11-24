#include <bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b)
{

    int temp1 = a;
    int temp2 = b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
#include <bits/stdc++.h>
using namespace std;

string oddEven(int N)
{

    int mask = 1;

    if ((N & mask) == 1)
        return "odd";

    return "even";
}
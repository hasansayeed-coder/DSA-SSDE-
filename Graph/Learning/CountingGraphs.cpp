#include <bits/stdc++.h>
using namespace std;

int countingGraphs(int N)
{
    int power = (N * (N - 1)) / 2;

    return pow(2, power);
}
#include <bits/stdc++.h>
using namespace std;

void fib(int n, int slast, int last, vector<int> &numbers, int cnt)
{

    if (cnt < n)
    {
        int total = last + slast;
        numbers.push_back(total);
        slast = last;
        last = total;
        fib(n, slast, last, numbers, cnt + 1);
    }

    return;
}

vector<int> generateFibonacciNumbers(int n)
{

    vector<int> numbers;

    if (n == 1)
        return {0};

    numbers.push_back(0);
    numbers.push_back(1);

    fib(n, 0, 1, numbers, 2);

    return numbers;
}
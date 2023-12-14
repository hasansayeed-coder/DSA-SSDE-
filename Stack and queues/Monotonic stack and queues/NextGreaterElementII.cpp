#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementII(vector<int> &a)
{

    int n = a.size();
    vector<int> nge(n, -1);

    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= a[i % n])
        {
            st.pop();
        }

        if ((i % n) < n)
        {
            if (!st.empty())
            {
                nge[i % n] = st.top();
            }
        }

        st.push(a[i % n]);
    }

    return nge;
}

#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int value = st.top();
    st.pop();

    insertBottom(st, element);
    st.push(value);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int element = st.top();
    st.pop();

    reverseStack(st);

    insertBottom(st, element);
}
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string S)
{

    stack<char> st;

    for (char ch : S)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
            continue;
        }

        else if (st.empty())
            return false;

        else if ((ch == ')' && st.top() == '(') ||
                 (ch == '}' && st.top() == '{') ||
                 (ch == ']' && st.top() == '['))
            st.pop();

        else
        {
            return false;
        }
    }

    return true;
}
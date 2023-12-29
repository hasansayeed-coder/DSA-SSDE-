#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{

    if (s.size() == 0)
        return 0;

    stack<char> st;
    int cnt = 0;
    int mxAns = INT_MIN;

    for (char ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
            cnt++;
            mxAns = max(mxAns, cnt);
        }

        else if (ch == ')')
        {
            st.pop();
            cnt--;
            mxAns = max(mxAns, cnt);
        }
    }

    return mxAns;
}

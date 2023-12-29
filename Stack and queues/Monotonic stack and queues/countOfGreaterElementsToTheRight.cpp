#include <bits/stdc++.h>
using namespace std;

vector<int> countGreater(vector<int> &arr, vector<int> &query)
{

    vector<int> ans;
    stack<int> st;

    int m = query.size();
    int n = arr.size();

    for (int i = 0; i < m; i++)
    {
        int count = 0;

        st.push(arr[query[i]]);

        for (int j = query[i] + 1; j < n; j++)
        {
            if (arr[j] > st.top())
            {
                count++;
            }
        }

        ans.push_back(count);
    }

    return ans;
}
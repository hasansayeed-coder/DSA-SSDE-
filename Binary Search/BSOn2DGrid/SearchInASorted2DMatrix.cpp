#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>> &MATRIX, int target)
{

    int n = MATRIX.size();
    int m = MATRIX[0].size();

    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (MATRIX[row][col] == target)
        {
            return true;
        }

        else if (MATRIX[row][col] < target)
        {
            row++;
        }

        else
        {
            col--;
        }
    }

    return false;
}
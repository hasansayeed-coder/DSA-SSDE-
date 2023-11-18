#include <bits/stdc++.h>
using namespace std;

int possible(vector<int> &arr, int mid)
{
    int n = arr.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)(arr[i]) / (double)(mid));
    }

    return sum;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    if (n > limit)
        return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid) <= limit)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

/*

int smallestDivisor(vector<int>& arr, int limit)
{

    int n = arr.size() ;


    int maxElement = *max_element(arr.begin(), arr.end()) ;

    for(int i = 1 ; i <= maxElement ; i++) {

        int sum = 0 ;

        for(int j = 0 ; j< n ; j++) {
            sum = sum + ceil((double)(arr[j]) / (double)(i)) ;
        }

        if(sum <= limit)return i  ;
    }

    return -1 ;

}
*/
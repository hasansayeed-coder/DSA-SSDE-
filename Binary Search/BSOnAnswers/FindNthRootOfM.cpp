
#define ll long long;

long long possible(int m, int mid, int n)
{

    long long ans = 1;

    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;

        if (ans > m)
        {
            return 2;
        }
    }

    if (ans == m)
        return 1;

    return 0;
}

int NthRoot(int n, int m)
{

    int low = 1;
    int high = m;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = possible(m, mid, n);

        if (val == 1)
            return mid;
        else if (val == 0)
            low = mid + 1;
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

/*


  for(int i = 1; i <= m ; i++) {

    long long val = possible(i , n) ;

    if(val == m * 1ll)return i ;

    if(val > m * 1ll) break ;
  }

  return -1;

  */
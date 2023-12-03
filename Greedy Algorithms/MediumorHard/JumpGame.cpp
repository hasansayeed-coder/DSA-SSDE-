#include<bits/stdc++.h>
using namespace std ;

int minJumps(vector<int> &arr , int n) {

    if(n == 1)return 0 ;

    int fur = 0 , totalJumps = 0 , curr = 0;

    bool f = false;

    for(int i = 0 ;i < n-1 ; i++){

        fur = max(fur , i + arr[i]) ;

        if(i == curr) {
            curr = fur ; 
            totalJumps++ ;
        }

        if(fur >= n-1)f = true ;
    }


    if(f)return totalJumps ;

    return -1 ;

  
    
}
#include<bits/stdc++.h>
using namespace std ;

int longestRepeatingSubstring(string &str, int k) {

    int l = 0 , c = 0 , ans = 0 ;
    vector<int> temp(28) ; 

    for(int r = 0 ; r < str.size() ; r++) {
        temp[str[r] - 'A']++ ; 

        c = max(c , temp[str[r] - 'A']) ;

        while(r-l+1-c > k) {
            temp[str[l]-'A']-- ;
            l++ ; 
        }

        ans = max(ans , r - l +1) ;
    } 
    return ans ; 
    
}
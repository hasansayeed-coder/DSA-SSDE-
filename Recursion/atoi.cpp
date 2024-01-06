#include<bits/stdc++.h>
using namespace std ; 



int createAtoi(string s) {

    if(s.empty())return 0  ;

    int len = s.length() , i = 0 , sign = 1 ; 

    while( i< len && s[i] == ' ')i++; 
    if(i == len)return 0 ;

    if(s[i] == '-')sign = 0  , i++ ;
    else if(s[i] == '+')sign = 1 , i++ ;

    long long ans = 0 ;

    while(s[i] >= '0' && s[i] <= '9'){
        ans = ans * 10 ;

        if(ans <=  INT_MIN || ans >= INT_MAX)break ; 

        ans = ans + (s[i] - '0');
        i++ ;
    }


    if(sign == 0)ans = -1 * ans ; 

    if(ans >= INT_MAX)return INT_MAX ; 
    if(ans <= INT_MIN)return INT_MIN ; 

    return (int)ans; 
    
}
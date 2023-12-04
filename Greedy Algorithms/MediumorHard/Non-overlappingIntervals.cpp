#include<bits/stdc++.h>
using namespace std ;

int minimumReschedules(int n, vector<vector<int>> &intervals) {
    
   sort(intervals.begin() , intervals.end()) ;

   int cnt = 0 ;
   int endTime = intervals[0][1] ;

   for(int i = 0 ; i < n-1 ; i++) {
       if(endTime <= intervals[i+1][0]){
           endTime = intervals[i+1][1] ;
       }

       else {

           cnt++;
           endTime = min(endTime, intervals[i + 1][1]);
       }
   }

   return cnt ; 
}

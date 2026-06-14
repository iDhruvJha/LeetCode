1class Solution {
2public:
3    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
4        vector<int> ans(n) ;
5        for(auto it : bookings){
6            ans[it[0] - 1] += it[2] ;
7            if( it[1] < n ){
8                ans[it[1]] -= it[2] ;
9            }
10        }
11        for(int i = 1 ; i < n ; i++ ){
12            ans[i] += ans[i-1] ;
13        }
14        return ans ;
15    }
16};
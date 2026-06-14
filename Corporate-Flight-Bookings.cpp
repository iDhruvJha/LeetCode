1class Solution {
2public:
3    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
4        vector<int> ans(n) ;
5        for(auto it : bookings){
6            for( int i = it[0] - 1 ; i <= it[1] - 1 ; i++){
7                ans[i] += it[2] ;
8            }
9        }
10        return ans ;
11    }
12};
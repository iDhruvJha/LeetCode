1class Solution {
2public:
3    int numSquares(int n) {
4        vector<int> dp(n+1,INT_MAX) ;
5        dp[0] = 0 ;
6        for( int i = 1 ; i <= n ; i++ ){
7            for( int j = 1 ; j*j <= i ; j++ ){
8                dp[i] = min(dp[i],dp[i - j*j] + 1 ) ;
9            }
10        }
11        return dp[n] ;
12    }
13};
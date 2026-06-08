1class Solution {
2public:
3    int numTrees(int n) {
4        vector<long long> dp(n+1,0) ;
5        dp[1] = 1 ;
6        for( int i = 2 ; i <= n ; i++ ){
7            dp[i] = (dp[i-1]*(4*i - 2))/(i+1) ;
8        }
9        return dp[n] ;
10    }
11};
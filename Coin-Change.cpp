1class Solution {
2public:
3    int coinChange(vector<int>& coins, int amount) {
4        vector<int> dp(amount + 1 , 1e9 ) ;
5        dp[0] = 0 ;
6        for( int i = 1 ; i <= amount ; i++ ){
7            for( auto num : coins ){
8                if( i - num >= 0 ){
9                    dp[i] = min(dp[i],dp[i-num] + 1) ;
10                }
11            }
12        }
13        return (dp[amount] >= 1e9) ? -1 : dp[amount] ;
14    }
15};
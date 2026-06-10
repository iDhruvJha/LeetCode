1class Solution {
2public:
3    int maximalSquare(vector<vector<char>>& matrix) {
4        int n = matrix.size() ;
5        int m = matrix[0].size() ;
6        vector<vector<int>> dp(n,vector<int>(m,0)) ; int sz = 0 ;
7        for( int i = 0 ; i < n ; i++ ){
8            for( int j = 0 ; j < m ; j++ ){
9                if(!i || !j || matrix[i][j] == '0'){
10                    dp[i][j] = matrix[i][j] - '0' ;
11                }
12                else{
13                    dp[i][j] = min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]}) + 1 ;
14                }
15                sz = max(sz,dp[i][j]) ;
16            }
17        }
18        return sz*sz ;
19    }
20};
1class Solution {
2public:
3    bool wordBreak(string s, vector<string>& wordDict) {
4        int n = s.size() ;
5        vector<int> dp(n+1,false) ;
6        dp[0] = true ;
7        for( int i = 0 ; i <= n ; i++ ){
8            if(!dp[i]) continue ;
9            for(auto it : wordDict){
10                int sz = it.size() ;
11                if( i + sz <= n && s.substr(i,sz) == it ){
12                    dp[i+sz] = true ;
13                }
14            }
15        }
16        return dp[n] ;
17    }
18};
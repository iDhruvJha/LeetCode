1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        int n = s.size() ;
5        vector<int> dp(n+2,0) ;
6        for(int i = n - 1 ; i >= 0 ; i--){
7            if(s[i] == ')') continue ;
8            if( i + 1 < n && s[i] == ')'){
9                dp[i] = dp[i+2] + 2 ;
10            }
11            else{
12                int x = dp[i+1] ;
13                int ind = i + 1 + x ;
14                if( ind < n && s[ind] == ')'){
15                    dp[i] = x + 2 + dp[ind + 1] ;
16                }
17            }
18        }
19        return *max_element(dp.begin(),dp.end()) ;
20    }
21};
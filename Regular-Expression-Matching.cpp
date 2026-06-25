1class Solution {
2public:
3    bool f(string &s,string &p,int i,int j ,vector<vector<int>>& dp){
4
5        int n=s.size();
6        int m=p.size();
7
8        if(i==n && j==m)
9            return true;
10
11        if(j==m)
12            return false;
13        
14        if(dp[i][j] != -1) return dp[i][j] ;
15
16        if(i==n){
17            while(j+1<m && p[j+1]=='*')
18                j+=2;
19
20            return dp[i][j] = j==m;
21        }
22
23        bool match=(s[i]==p[j] || p[j]=='.');
24
25        if(j+1<m && p[j+1]=='*'){
26
27            return dp[i][j] = f(s,p,i,j+2,dp) ||
28                  (match && f(s,p,i+1,j,dp));
29
30        }
31
32        if(match)
33            return dp[i][j] = f(s,p,i+1,j+1,dp);
34
35        return dp[i][j] = false;
36    }
37
38    bool isMatch(string s, string p) {
39        int n=s.size();
40        int m=p.size();
41        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
42        return f(s,p,0,0,dp);
43    }
44};
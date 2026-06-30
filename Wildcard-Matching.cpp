1class Solution {
2public:
3    bool isMatch(string s, string p) {
4
5        int n=s.size();
6        int m=p.size();
7
8        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
9
10        dp[n][m]=true;
11
12        for(int j=m-1;j>=0;j--)
13        {
14            if(p[j]=='*')
15                dp[n][j]=dp[n][j+1];
16        }
17
18        for(int i=n-1;i>=0;i--)
19        {
20            for(int j=m-1;j>=0;j--)
21            {
22                if(s[i]==p[j] || p[j]=='?')
23                {
24                    dp[i][j]=dp[i+1][j+1];
25                }
26                else if(p[j]=='*')
27                {
28                    dp[i][j]=dp[i][j+1] || dp[i+1][j];
29                }
30                else
31                {
32                    dp[i][j]=false;
33                }
34            }
35        }
36
37        return dp[0][0];
38    }
39};
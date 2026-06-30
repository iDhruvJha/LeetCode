1class Solution {
2public:
3
4    bool f(int i,int j,string &s1,string &s2,string &s3 , vector<vector<int>>& dp){
5
6        if(i==s1.size() && j==s2.size())
7            return true;
8
9        int k=i+j;
10        if(dp[i][j] != -1){
11            return dp[i][j] ;
12        }
13        bool ans=false;
14
15        if(i<s1.size() && s1[i]==s3[k])
16            ans = ans || f(i+1,j,s1,s2,s3,dp);
17
18        if(j<s2.size() && s2[j]==s3[k])
19            ans = ans || f(i,j+1,s1,s2,s3,dp);
20
21        return dp[i][j] = ans;
22    }
23
24    bool isInterleave(string s1, string s2, string s3) {
25        int n = s1.size() ; int m = s2.size() ;
26        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)) ;
27        if(s1.size()+s2.size()!=s3.size())
28            return false;
29
30        return f(0,0,s1,s2,s3,dp);
31    }
32};
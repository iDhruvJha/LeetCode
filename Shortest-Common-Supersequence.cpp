1class Solution {
2public:
3    string shortestCommonSupersequence(string str1, string str2) {
4
5        int n=str1.size();
6        int m=str2.size();
7
8        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
9
10        for(int i=1;i<=n;i++)
11        {
12            for(int j=1;j<=m;j++)
13            {
14                if(str1[i-1]==str2[j-1])
15                    dp[i][j]=1+dp[i-1][j-1];
16                else
17                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
18            }
19        }
20
21        string ans;
22
23        int i=n;
24        int j=m;
25
26        while(i>0 && j>0)
27        {
28            if(str1[i-1]==str2[j-1])
29            {
30                ans+=str1[i-1];
31                i--;
32                j--;
33            }
34            else if(dp[i-1][j]>dp[i][j-1])
35            {
36                ans+=str1[i-1];
37                i--;
38            }
39            else
40            {
41                ans+=str2[j-1];
42                j--;
43            }
44        }
45
46        while(i>0)
47        {
48            ans+=str1[i-1];
49            i--;
50        }
51
52        while(j>0)
53        {
54            ans+=str2[j-1];
55            j--;
56        }
57
58        reverse(ans.begin(),ans.end());
59
60        return ans;
61    }
62};